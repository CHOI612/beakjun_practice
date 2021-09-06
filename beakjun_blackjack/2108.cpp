//beakjoon num.2108
//�����
//���� 

//sort & count 
/*
��� ��� 
�߾Ӱ�
�ֺ�
���� 
float�� ��Ȯ�� 6�ڸ� ��Ȯ���� ��������-> �Ǽ����� ����ϰ� �� �Ѵٸ� double�� ����ؾ��Ѵ�.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);

	//input 
	int n = 0;
	cin >> n;
	if (n < 1 || n>500, 000) return 0;


	int a = 0;
	int sum = 0;
	int max_num = 0;
	int min_num = 0;
	vector <int> A;

	for (int i = 0; i < n; i++) {
		cin >> a;
		A.push_back(a);
		sum += a;
		if (i == 0) {
			min_num = a;
			max_num = a;
		}
		else {
			if (a < min_num) min_num = a;
			if (a > max_num) max_num = a;
		}
	}
	//����
	sort(A.begin(), A.end());
	
	//������ 
	
	double mean = (double)sum / n;
	cout << round(mean) << "\n";

	//�߾Ӱ�
	cout << A[n / 2] << "\n";

	//�ֺ�
	vector<pair <int, int>> P;
	int cnt = 0;
	int max = 0;

	//count ����Ͽ�  �� ���Һ� ���� �ľ�
	for (int i = 0; i < n; i++) {
		
		if (i > 0 && P.back().first == A[i]) continue;
		else {
			//count�� begin���� �ϸ� �ð��ʰ�
			//�̹� sort�� ���� �̹Ƿ� �ش� ��ġ�������� ����
			cnt = count(A.begin()+i,A.end(), A[i]);
			P.push_back(make_pair(A[i], cnt));
			if (cnt > max) max = cnt;
		}
	}
	
	//������ max���� ��츸 ���� 
	vector <int>mode;
	for (int i = 0; i < P.size(); i++) {
		if (P[i].second == max) {
			mode.push_back(P[i].first);
		}
	}
	
	//max���� �������� ��� �ι�° ���� ������ ���
	if (mode.size() != 1)
		cout << mode[1] << "\n";
	else
		cout << mode[0] << "\n";
	
	//����
	cout <<A[n-1] - A[0]<< "\n";

	return 0;
}
