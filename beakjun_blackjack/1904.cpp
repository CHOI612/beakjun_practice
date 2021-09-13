//beakjoon num.1904
//01타일
//Dynamic Programming
//정답

#include <iostream>
#include <algorithm>
#include <vector>

/* 점화식을 세워본다
 피보나치 수열을 따라 간다
	1                     1
	00 11               2
	001 100 111      3
	0000 0011 1100 1001 1111 5
	00001 00100 10000 00111 10011 11001 11100 11111 8
	000000 000011 100001 110000 001100 001001 100100 001111 100111 110011 111001 111100 111111 13
*/
/*
※계산 주의
%연산을 재귀함수 return에 넣는 이유는 값이 너무 커지기 때문이다.
계산을 다 하고 넘기면 오버플로우가 된다.
*/

using namespace std;

#define For(i, n) for(int i =0; i<(n); ++i)

vector<int> m(1000000,0);
int total = 0;

int fib(int n) {
	if (!m[n]) {
		if (n == 0) m[n] = 1;
		else if (n == 1) m[n] = 1;
		else {
			m[n] = (fib(n - 1) + fib(n - 2))% 15746;
		}
	}
	return m[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	//input
	cin >> n;

	int num = fib(n);

	//output
	cout << num;
	return 0;
}