// BeakJun Num.2798
//������ ����

#include <iostream>
using namespace std;

int Blackjack(int a[100], int n, int m);


int main()
{
	int n = 0;
	int m = 0;
	

	cin >> n >> m;
	if (n < 3 || n > 100) return 0; // ���ǿ� ���� ������ 0 ��ȯ
	if (m < 10 || m>300000) return 0;
	
	int a[100];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; // ���� ī�� �迭�� �ֱ�
		if (a[i] > 100000) return 0;
		
	}
	
	cout << Blackjack(a, n, m) << endl;


	return 0;
}


int Blackjack(int a[100], int n, int m)
{
int res = 0;

for (int i = 0; i < n-2; i++) // ���� ī�带 3�� ���ϱ� 3�� for�� 
{
	int sum = 0;
	for (int k = i + 1; k < n - 1; k++)
	{
		sum = a[i] + a[k];
		for (int j = k+1; j < n; j++)
		{
			int tmp = 0;
			tmp = sum + a[j];
			if (tmp > res&&tmp <= m) res = tmp; // ��� ���� ������ ���� �ʴ� ������ ���� ū ������ 
		}
	}

}


return res;
}

// for 3�� ���ٴ� ��� �Լ��� ���� �ξ� ���� 

