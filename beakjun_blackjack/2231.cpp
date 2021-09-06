// beakjun Num.2231
// �ڿ��� N�� ������ M ���ϱ� (������)
//����
#include <iostream>
using namespace std;

//!1�� �ڸ� ����!

int findCipher(int n); // ���� n�� �ڸ��� ���ϴ� �Լ�
int findMinM(int n, int c ); // M�� ã�Ƴ��� �Լ�

int main()
{
	int n = 0;
	int c = 5;
	cin >> n;
	if (n < 0 || n>1000001) return 0;
	c = findCipher(n);
	cout << findMinM(n, c);

	return 0;
}

//���� ���� ���ڸ� �� ���� 
int findCipher(int n)
{
	int c = 0;
	int j = 10;
	int i = 1;
	for (; i < 8; i++) {
		if (n / j <= 0) {
			break;
		}
		else j *= 10;
	}
	return i;
}

int findMinM(int n, int c)
{
	//������ ���� ���� �� ����
	//1�� �ڸ��� ��� ��꺸�� 2������ �ִ°��� ����
	if (c == 1) {
		if (n == 4) return 2;
		else if (n == 8) return 4;
		else return 0;
	}
	int min = n - c * 9;
	if (min <= 0) min = 10;
	
	bool find = false;

	//������ ���� ���� �� ���� brute force
	while (find == false) {
		int m = findCipher(min);
		int sum = min;
		int ten = 10;
		int value = min;
		//�� �ڸ��� ���
		for (int i = 1; i <= m; i++) {
			sum += value% ten;
			value = value / ten;
		}
		if (sum == n) find = true;
		else if (min > n) {
			find = true;
			min = 0;
		}
		else min++;
	}

	return min;
}