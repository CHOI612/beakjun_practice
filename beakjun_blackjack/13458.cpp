// beakjoon num.13458
//시험감독


// 제발 범위값!!!!
// 빼기 => 마이너스 되는 것 확인하기 
//나누기 => 0으로 나누는지 확인
//int보단 longlong 쓰자
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	long long n;
	long long tmp;
	vector<long long>a;
	long long b, c;
	long long total_cnt = 0;
	//input
	cin >> n;

	for (long long i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	cin >> b >> c;

	long long cnt;
	long long result;
	for (long long i = 0; i < n; i++) {
		cnt = 0;
		tmp = a[i]; 
	
		if (tmp > b) {
			tmp -= b;
			cnt++;
			result = tmp % c;
			if (result == 0) cnt = cnt + tmp / c;
			else cnt = cnt + (tmp / c) + 1;
		}
		else cnt = 1;
		total_cnt += cnt;

	}

	cout << total_cnt;

}
