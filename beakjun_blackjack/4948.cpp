// beakjun Num.4948
//����Ʈ�� ����
//�Ҽ� ����
//����

#include <iostream>
#include <cmath>
using namespace std;

//�����佺�׳׽��� ü
/*
bool�� �̿��ϸ� �� ������ ���� 
���� �Ҽ��� ã�� �ε����� �߰��Ͽ�
STL���� �����ϴ� 
<algorithm>��� �ʿ�
low_bound 
upper_bound
�Լ��� �̿��Ͽ� binary search�� �Ѵٸ�� ������

*/
int main() {
	//�Ҽ� ���ϱ�
	int number[246913];
	int num = 246913;
	number[0] = 0;
	number[1] = 0;
	for (int i = 2; i <num; i++) {
		number[i] = i;
	}

	for (int i = 2; i <= sqrt(num); i++) {
		if (number[i] == 0) continue;
		for (int j = i * 2; j <= num; j += i) {
			number[j] = 0;
		}
	}

	int n = -1;
	int cnt = 0;
	while (n !=0)
	{
		cin >> n;
		if (n < 1 || n > 123456) return 0; // ���ǿ� ���� ������ 0 ��ȯ
		if (n == 0) return 0;
		cnt = 0;
		//������ ������ count
		for (int i = n+1; i <=2*n; i++) {
			if (number[i] != 0) cnt++;
		}
		printf("%d\n", cnt);
	}


	return 0;
}

