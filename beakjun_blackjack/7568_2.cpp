// ���ڵ�� ����
#include <iostream>
using namespace std;


int main()
{
	int ppl = 0;
	int x[49];
	int y[49];
	int cpr[49];
	fill_n(cpr, 49, 0); // cpr �迭 �ʱ�ȭ

	cin >> ppl; // �����

	for (int i = 0; i < ppl; i++) // ���� Ű ������ �ޱ�
	{
		cin >> x[i] >> y[i];
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
		cout << cpr[k] + 1 << " ";
	}
	return 0;
}