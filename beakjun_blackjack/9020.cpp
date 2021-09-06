// beakjun Num.9020
//골드바흐의 추측
//소수 응용


#include <iostream>
#include <cmath>
using namespace std;

//에라토스테네스의 체

int main() {
	//소수 구하기
	bool number[246913] = {false};
	int num = 246913;
	number[0] = 0;
	number[1] = 0;
	for (int i = 2; i < num; i++) {
		number[i] = i;
	}

	for (int i = 2; i <= sqrt(num); i++) {
		if (number[i] == 0) continue;
		for (int j = i * 2; j <= num; j += i) {
			number[j] = 0;
		}
	}

	int n = -1;
	int cnt = 0;
	while (n != 0)
	{
		cin >> n;
		if (n < 1 || n > 123456) return 0; // 조건에 맞지 않으면 0 반환
		if (n == 0) return 0;
		cnt = 0;
		//범위값 내에서 count
		for (int i = n + 1; i <= 2 * n; i++) {
			if (number[i] != 0) cnt++;
		}
		printf("%d\n", cnt);
	}


	return 0;
}
