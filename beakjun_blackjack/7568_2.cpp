// 이코드는 정답
#include <iostream>
using namespace std;


int main()
{
	int ppl = 0;
	int x[49];
	int y[49];
	int cpr[49];
	fill_n(cpr, 49, 0); // cpr 배열 초기화

	cin >> ppl; // 사람수

	for (int i = 0; i < ppl; i++) // 각각 키 몸무게 받기
	{
		cin >> x[i] >> y[i];
	}

	for (int cnt = 0; cnt < ppl; cnt++)
	{
		for (int j = 0; j < ppl; j++) // 자신과 다른 모든 사람 비교하기
		{
			if (cnt == j)continue;
			
			if (x[cnt] < x[j] && y[cnt] < y[j]) cpr[cnt]++; // 자기보다 등치 큰사람 몇명인지 확인 ==> 이게 본인의 등수           
			
		}

	}

	for (int k = 0; k < ppl; k++)
	{
		cout << cpr[k] + 1 << " ";
	}
	return 0;
}