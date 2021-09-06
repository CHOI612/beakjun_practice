// beakjoon num.10989
//�� �����ϱ� 3
//���� 

//Counting sort
// input & output���� ����ϴ� �Լ����� ���� �ӵ� ���� 
//input�� �������� �ʾƵ� �ȴ� -> �޸� ���� ����
//counting �߿����� �ٽ� b�迭�� ���� �� ����� �ƴ� counting�� ���� ���

// cout�� data type�� Ȯ�� �� ��� -> ��½ð��� ��� 
//	ios_base::sync_with_stdio(false) -> ����ؼ� data type�� Ȯ���� ���� �ʰ� ���

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	if (n < 1 || n>10, 000, 000) return 0;

	int a=0;

	int max_num = 0;
	int count[10001] = {};
	for (int i = 0; i < n; i++) {
		cin >> a;
		count[a]++;
		if (a > max_num) max_num = a;
	}
	//max�� ã�Ƽ� -> count �迭�� ������ ����
	for (int j = 1; j < max_num + 1; j++) {
		while (count[j] > 0) {
			cout << j << "\n";
			count[j]--;
		}
	}

	return 0;
}