// BeakJun Num.2798
//블랙잭의 변형

#include <iostream>
using namespace std;

int Blackjack(int a[100], int n, int m);


int main()
{
	int n = 0;
	int m = 0;
	

	cin >> n >> m;
	if (n < 3 || n > 100) return 0; // 조건에 맞지 않으면 0 반환
	if (m < 10 || m>300000) return 0;
	
	int a[100];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; // 받은 카드 배열로 넣기
		if (a[i] > 100000) return 0;
		
	}
	
	cout << Blackjack(a, n, m) << endl;


	return 0;
}


int Blackjack(int a[100], int n, int m)
{
int res = 0;

for (int i = 0; i < n-2; i++) // 받은 카드를 3개 더하기 3중 for문 
{
	int sum = 0;
	for (int k = i + 1; k < n - 1; k++)
	{
		sum = a[i] + a[k];
		for (int j = k+1; j < n; j++)
		{
			int tmp = 0;
			tmp = sum + a[j];
			if (tmp > res&&tmp <= m) res = tmp; // 결과 값중 범위를 넘지 않는 선에서 가장 큰 값으로 
		}
	}

}


return res;
}

// for 3중 보다는 재귀 함수를 사용시 훨씬 간단 

