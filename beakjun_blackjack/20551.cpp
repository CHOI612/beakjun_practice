//beakjoon num.20551
//sort ������ �������� �İ���
//����
//���� ������ ����


//search 
/*
lower_bound 
-���ĵ� �迭/ ����Ʈ
-���� ���� ok
-ã������ key ���� ������ key������ ū ���� ���� ���� 
upper_bound 
-key���� �ʰ��ϴ� ���� ù��° ������ ��ġ 
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


