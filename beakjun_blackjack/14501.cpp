// beakjoon num.14501
//퇴사

/*
풀이 아이디어 
N -> 넣는데 순서가 있음 
모든 경우의 수 확인 필요 
시간이 찰때까지의 가능한 경우 확인...?
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int max_p = 0;
int n = 0;
vector <pair<int, int>> s;
void consulting(int sum_t, int sum_p) {

    if(sum_t <= n) {
		int t = sum_t;
		int p = 0;

		for (int i = sum_t; i < n; i++) {
			t = i + s[i].first;
			p = sum_p + s[i].second;
			consulting(t, p);
		}
		if (sum_p > max_p) max_p = sum_p;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);

	int t, p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		s.push_back(make_pair(t, p));
	}

	consulting(0, 0);

	cout << max_p;
}