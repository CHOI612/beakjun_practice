//beakjoon num.9663
//N-Queen
//백트레킹


/*
Q가 가능한 자리를 전체가 아닌 그 자리 행만을 계산하여 확인 하도록 한다.
dfs를 사용하여 해당 자리가 ok면 다음 진행 no면 그 자리 더이상 고려 안하고 진행
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
using namespace std;
#define For(i,n) for(int i =0; i<(n); ++i) 
int cnt = 0;
int n = 0;



void Q_position(int p, vector<int>q) {

	//해당 행 가능한 자리 check 
	bool board[15] = { 0 };
	For(i, p) {
		int x = i;
		int y = q[i];
		board[y] = true;
		if ((y + p - i) < n) board[y + p - i] = true;
		if ((y - p + i) >= 0) board[y - p + i] = true;
	}

	//마지막일 경우 가능한 자리 모두 탐색
	if (p == n - 1) {
		For(i, n) {
		if (board[i] != true) cnt++;
		}
	}

	else {
		q.push_back(0);

		For(i,n) {

			if (board[i] != true) {
				q[p] = i;
				Q_position(p + 1,q);
			}


		}


	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//input 
	cin >> n;

	vector<int>q;
	Q_position(0, q);

	//output
	cout <<cnt << "\n";
	return 0;
}

