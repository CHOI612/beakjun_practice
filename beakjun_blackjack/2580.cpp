//beakjoon num.2580
//스도쿠
//백트레킹 
// 틀림 너무 복잡하게 생각함 
//feedback 참고

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
using namespace std;

#define For(i,n) for(int i =0; i<(n); ++i) 

int sudoku[10][10] = { 0 };
vector<pair<int, int>> blank;

void check_board(int s[][10], int cnt, vector<int> a) {

	if (cnt == blank.size()) {
		For(i, cnt) {
		int x = blank[i].first;
		int y = blank[i].second;
		sudoku[x][y] = a[i];
		}

	}
	else {
		a.push_back(0);
		int x = 0;
		int y = 0;

		For(i, cnt) {
			x = blank[i].first;
			y = blank[i].second;
			s[x][y] = a[i];
		}
		x = blank[cnt].first;
		y = blank[cnt].second;
		for (int i = 1; i <= 9; i++) {

			bool check_num = true;

			//row & column
			For(r, 9) {
				if (i == s[x][r]) {
					check_num = false;
					break;
				}
			}
			//column
			if (check_num == true) {
				For(c, 9) {
					if (i == s[c][y]) {
						check_num = false;
						break;
					}
				}
			}
				//box
			if (check_num == true) {
				int box_x = 0;
				int box_y = 0;
				if (x != 0) box_x = (x / 3) * 3;
				if (y != 0) box_y = (y / 3) * 3;
				for (int c = box_x; c < box_x + 3; c++) {
					for (int r = box_y; r < box_y + 3; r++) {
						if (i == s[c][r]) {
							check_num = false;
							break;
						}
					}
				}

			}
			//recall sudoku
			For(i, cnt) {
				x = blank[i].first;
				y = blank[i].second;
				s[x][y] = 0;
			}
			//do dfs
			if (check_num == true) {
				a[cnt] = i;
				check_board(s, cnt + 1, a);
			}
			}
		}
	}


int main() {
	ios_base::sync_with_stdio(false);
	int n;

	//input 
	For(i, 9) {
		For(j, 9) {
			cin >> n;
			if (n == 0) {
				blank.push_back(make_pair(i, j));
			}
			sudoku[i][j] = n;
		}
	}
	
	vector<int>ans;
	check_board(sudoku, 0,ans);
	
	//output
	For(i, 9) {
		For(j, 9) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

