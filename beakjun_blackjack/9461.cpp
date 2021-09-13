//beakjoon num.9461
//�ĵ��� ����
//Dynamic Programming


/* ��ȭ���� ��������
1 1 1 2 2 3 4 5 7 9 12
n = (n-2) + (n-3);
>�ﰢ���׸����� ���� n = (n-5) + (n-1);
*/
/*  ���ڷ��� �Ǵ�
int�� ����ϰ� �Ǹ� 4bytes ���� ������ ����� �ȴ� -> 8 bytes�� long long�� ����ؾ���
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define For(i, n) for(int i =0; i<(n); ++i)

vector<long long > m(101, 0);
int total = 0;

long long Padovan(int n) {
	if (!m[n]) {
		if (n == 1) m[n] = 1;
		else if (n == 2) m[n] = 1;
		else if (n == 3) m[n] = 1;
		else if (n == 4) m[n] = 2;
		else if (n == 5) m[n] = 2;
		else {
			//m[n] = Padovan(n - 5) + Padovan(n - 1);
			m[n] = Padovan(n - 2) + Padovan(n - 3); 
		}
	}
	return m[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	int t,n;

	//Padovan(100); // max�� 100���� ��� �ǽ��ϰ� �Ǹ� 99�� �������� ����
	//input & output
	cin >> t;
	For(i, t) {
		cin >> n;
		Padovan(n);
		cout << m[n] << "\n";
	}

	return 0;
}