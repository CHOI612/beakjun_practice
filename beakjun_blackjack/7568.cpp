//Beakjun Num.7568
// ��ġ �� �ϱ�
// ���ڵ�� ������ �ƴ�
#include <iostream>
using namespace std;

int main()
{
	int ppl = 0;
	int x[49];
	int y[49];
	int cpr[49];
	fill_n(cpr, 49, 1); // cpr �迭 �ʱ�ȭ
	
	cin >> ppl; // �����
	
	if (ppl < 2 || 50 < ppl) return 0; 

	for (int i = 0; i < ppl; i++) // ���� Ű ������ �ޱ�
	{
		cin >> x[i];
		cin >> y[i];

		if (x[i] < 10 || x[i]>200) return 0;
		if(y[i] < 10 || y[i]>200) return 0;
	}

	for (int cnt = 0; cnt < ppl; cnt++)
	{
		for (int j = 0; j < ppl; j++) // �ڽŰ� �ٸ� ��� ��� ���ϱ�
		{
			if (cnt == j)continue;
			if (x[cnt] < x[j] && y[cnt] < y[j]) cpr[cnt]++; // �ڱ⺸�� ��ġ ū��� ������� Ȯ�� ==> �̰� ������ ���
			
		}

	}

	for (int k = 0; k < ppl; k++) 
	{
 		cout << cpr[k] << " ";
	}



	return 0;

}