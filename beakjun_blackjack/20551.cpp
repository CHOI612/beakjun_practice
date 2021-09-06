//beakjoon num.20551
//sort 마스터 배지훈의 후계자
//정답
//조건 빼먹지 말자


//search 
/*
lower_bound 
-정렬된 배열/ 리스트
-같은 원소 ok
-찾으려는 key 값이 없으면 key값보다 큰 가장 작은 정수 
upper_bound 
-key값을 초과하는 가장 첫번째 원소의 위치 
lower_bound(arr, arr+n, key);
upper_bound(arr, arr+n, key);


sort 
quick sort
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	int A[200001] = { };

	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	sort(A, A + n);

	int Q = 0;
	int ans = 0;

	for (int i = 0; i < m; i++) {

		cin >> Q;
	   
		int* ps = lower_bound(A, A + n, Q);
		ans = ps - A;
		if (A[ans] == Q && ans >= 0 && ans < n)  cout << ans << "\n";
		else cout<<"-1\n";
	}

	return 0;
}


