// beakjoon num.21608
//상어 초등학교
//정답

/*
!생각 못한 부분!
제발 범위 확인 잘 하자 -> nn과 n 범위 차이 확인
변수가 너무 많다 -> 관리가 안된다
제곱 사용시 >> <cmath> pow 함수 이용
주변에 친구가 없고 빈 자리도 없는 경우 > 조건에 해당하지 않는 경우까지 생각하자
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<bool>> position(21, vector <bool>(21,0));
vector<vector<int>> relation(401, vector <int>(6,0));
queue<int> number;
vector<pair<int,int>> set_p;

int main() {
	ios_base::sync_with_stdio(false);
	int n= 0;
	int s, f = 0;
	

	vector<pair<int, int>>check;
	check.push_back(make_pair(0, -1));
	check.push_back(make_pair(0, 1));
	check.push_back(make_pair(-1, 0));
	check.push_back(make_pair(1, 0));

	//input
	cin >> n;
	int nn = n * n;
	set_p.push_back(make_pair(-1, -1));

	for (int i = 1; i <= nn; i++) {
		cin >> s;
		number.push(s);
		set_p.push_back(make_pair(-1, -1));
		for (int j = 0; j < 4; j++) {
			cin >> f;
			relation[s][j] = f;
		}
	}

	int cnt = 0;
	int max_value = 0;
	int value, empty = 0;
	int max_value_r, max_value_c = 0;
	int max_value_empty = 0;
	int rr, cc = 0;
	int tmp = 0;

	//학생 자리 정하기
	while (cnt < nn) {
		//max 변수 초기화
		max_value = 0;
		max_value_r = 0;
		max_value_c = 0;
		max_value_empty = 0;
		rr, cc = 0;
		tmp = 0;

		//자리에 앉을 사람 확인
		s = number.front();
		number.pop();

		//모든 자리 확인
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				//변수초기화
				value = 0;
				empty = 0;
				rr, cc = 0;
				if (!position[r][c]) {
					//친한사람 4명 자리 확인
					for (int j = 0; j < 4; j++) {
						f = relation[s][j];
						rr = set_p[f].first;
						cc = set_p[f].second;
						if (rr != -1) {
							if ((abs(r - rr) + abs(c - cc)) == abs(1)) value++;
						}
					}

					//주변 비어 있는 자리 확인 
					for (int i = 0; i < 4; i++) {
						rr = r + check[i].first;
						cc = c + check[i].second;
						if (rr >= 0 && rr < n) {
							if (cc >= 0 && cc < n) {
								if (!position[rr][cc]) empty++;
							}
						}
					}
			
					//max값 확인
					//인접칸 중에서도 비어있는 자리 탑이도록
					//같은 경우 조건 3에 따라 업데이트 하지 않음
					if (max_value == value && max_value_empty < empty) {
							max_value_c = c;
							max_value_r = r;
							max_value_empty = empty;
					}
					else if (max_value < value) {
							max_value = value;
							max_value_c = c;
							max_value_r = r;
							max_value_empty = empty;
					}
					//주변에 친구가 없고 빈 자리도 없는 경우
					if (max_value_empty == 0 && max_value_empty == 0 && tmp==0) {
						max_value_c = c;
						max_value_r = r;
						tmp++;
						//cout << " 친구&빈자리 no" << s << " " << r << " " << c << "\n";
					}
				}
			}
		}

		//최고의 위치에 자리 앉기
		set_p[s].first = max_value_r;
		set_p[s].second = max_value_c;
		
		position[max_value_r][max_value_c] = true;
		cnt++;

	}

	int total_satisfaction = 0;
	int sat = 0;
	cnt = 1;
	int r, c = 0;
	//학생의 만족도 구하기
	while (cnt <= nn) {

		r = set_p[cnt].first;
		c = set_p[cnt].second;
		sat = 0;

		for (int j = 0; j < 4; j++) {
			f = relation[cnt][j];

			rr = set_p[f].first;
			cc = set_p[f].second;

			if (rr != -1) {
				if ((abs(r - rr) + abs(c - cc)) == abs(1)) {
					sat++;
				}
			}
		}

		if(sat!=0)total_satisfaction = total_satisfaction + pow(10,(sat-1));
		cnt++;
	}
	cout << total_satisfaction << "\n";
	return 0;
}





