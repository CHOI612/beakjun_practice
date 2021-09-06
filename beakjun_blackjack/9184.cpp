//beakjoon num.9184
//신나는 함수 실행
//Dynamic Programming
//정답

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define For(i, n) for(int i =0; i<(n); ++i)

vector<vector<vector<int>>> w_set(21, vector<vector<int>>(21, vector<int>(21)));

// 동적으로 저장을 해가며 해결 -> 저장을 이미 해놓아서  반복되는 계산하지 않도록 하는 것이 point
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	else if (w_set[a][b][c] != 0) {
		return w_set[a][b][c];
	}
	else if (a < b && b < c) {
		w_set[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c - 1);
		return w_set[a][b][c];
	}
	else {
		w_set[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		return w_set[a][b][c];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	int a,b,c;
	int result;
	bool finish_check =true;
	//input
	while (finish_check) {
		
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			finish_check = false;
			break;
		}

		result = w(a, b, c);
		
		printf("w(%d, %d, %d) = %d\n", a, b, c, result);

	}


	return 0;
}