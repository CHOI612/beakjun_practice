//beakjoon num.1003
//�Ǻ���ġ �Լ�
//Dynamic Programming
//����

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define For(i, n) for(int i =0; i<(n); ++i)
int max_v = 0;
vector<int> test_case;
vector<pair<int, int>> cnt; //first 0 second 1

//�� max������ �ѹ��� ����Ͽ� ����
void fibonacci_cnt(int n) {
	cnt.push_back(make_pair(0, 0));
	if (n == 0) {
		cnt[n].first++;
	}
	else if (n == 1) {
		cnt[n].second++;
	}
	else {
		cnt[n].first = cnt[n - 1].first + cnt[n - 2].first;
		cnt[n].second = cnt[n - 1].second + cnt[n - 2].second;
	}
	if (n != max_v) {
		n++;
		fibonacci_cnt(n);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	int t,n;
	cin >> t;
	//input
	For(i, t) {
		cin >> n;
		test_case.push_back(n);
		if (n > max_v) max_v = n;
	}

	fibonacci_cnt(0);

	//output
	//max������ �̹� ����Ǿ� �����Ƿ� ������ ���⸸ �ϸ� ��
	For(i, test_case.size()) {
		n = test_case[i];
		cout << cnt[n].first << " " << cnt[n].second << "\n";
	}

	return 0;
}