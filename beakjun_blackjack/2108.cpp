//beakjoon num.2108
//통계학
//정답 

//sort & count 
/*
산술 평균 
중앙값
최빈값
범위 
float의 정확도 6자리 정확도가 떨어진다-> 실수형을 사용하고 자 한다면 double을 사용해야한다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);

	//input 
	int n = 0;
	cin >> n;
	if (n < 1 || n>500, 000) return 0;


	int a = 0;
	int sum = 0;
	int max_num = 0;
	int min_num = 0;
	vector <int> A;

	for (int i = 0; i < n; i++) {
		cin >> a;
		A.push_back(a);
		sum += a;
		if (i == 0) {
			min_num = a;
			max_num = a;
		}
		else {
			if (a < min_num) min_num = a;
			if (a > max_num) max_num = a;
		}
	}
	//정렬
	sort(A.begin(), A.end());
	
	//산술평균 
	
	double mean = (double)sum / n;
	cout << round(mean) << "\n";

	//중앙값
	cout << A[n / 2] << "\n";

	//최빈값
	vector<pair <int, int>> P;
	int cnt = 0;
	int max = 0;

	//count 사용하여  각 원소별 갯수 파악
	for (int i = 0; i < n; i++) {
		
		if (i > 0 && P.back().first == A[i]) continue;
		else {
			//count를 begin부터 하면 시간초과
			//이미 sort된 상태 이므로 해당 위치에서부터 조사
			cnt = count(A.begin()+i,A.end(), A[i]);
			P.push_back(make_pair(A[i], cnt));
			if (cnt > max) max = cnt;
		}
	}
	
	//갯수가 max값이 경우만 저장 
	vector <int>mode;
	for (int i = 0; i < P.size(); i++) {
		if (P[i].second == max) {
			mode.push_back(P[i].first);
		}
	}
	
	//max값이 여러개인 경우 두번째 작은 값으로 출력
	if (mode.size() != 1)
		cout << mode[1] << "\n";
	else
		cout << mode[0] << "\n";
	
	//범위
	cout <<A[n-1] - A[0]<< "\n";

	return 0;
}
