// beakjun Num.2231
// 자연수 N의 생성자 M 구하기 (분해합)
//정답
#include <iostream>
using namespace std;

//!1의 자리 주의!

int findCipher(int n); // 받은 n의 자리수 구하는 함수
int findMinM(int n, int c ); // M을 찾아내는 함수

int main()
{
	int n = 0;
	int c = 5;
	cin >> n;
	if (n < 0 || n>1000001) return 0;
	c = findCipher(n);
	cout << findMinM(n, c);

	return 0;
}

//받은 수가 몇자리 수 인지 
int findCipher(int n)
{
	int c = 0;
	int j = 10;
	int i = 1;
	for (; i < 8; i++) {
		if (n / j <= 0) {
			break;
		}
		else j *= 10;
	}
	return i;
}

int findMinM(int n, int c)
{
	//가능한 가장 작은 수 설정
	//1의 자리인 경우 계산보다 2가지를 넣는것이 빠름
	if (c == 1) {
		if (n == 4) return 2;
		else if (n == 8) return 4;
		else return 0;
	}
	int min = n - c * 9;
	if (min <= 0) min = 10;
	
	bool find = false;

	//가능한 가장 작은 수 부터 brute force
	while (find == false) {
		int m = findCipher(min);
		int sum = min;
		int ten = 10;
		int value = min;
		//각 자리합 계산
		for (int i = 1; i <= m; i++) {
			sum += value% ten;
			value = value / ten;
		}
		if (sum == n) find = true;
		else if (min > n) {
			find = true;
			min = 0;
		}
		else min++;
	}

	return min;
}