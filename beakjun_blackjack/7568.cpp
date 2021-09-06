//Beakjun Num.7568
// 덩치 비교 하기
// 이코드는 정답이 아님
#include <iostream>
using namespace std;

int main()
{
	int ppl = 0;
	int x[49];
	int y[49];
	int cpr[49];
	fill_n(cpr, 49, 1); // cpr 배열 초기화
	
	cin >> ppl; // 사람수
	
	if (ppl < 2 || 50 < ppl) return 0; 

	for (int i = 0; i < ppl; i++) // 각각 키 몸무게 받기
	{
		cin >> x[i];
		cin >> y[i];

		if (x[i] < 10 || x[i]>200) return 0;
		if(y[i] < 10 || y[i]>200) return 0;
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
 		cout << cpr[k] << " ";
	}



	return 0;

}