// beakjun Num.1436
// ���Ʈ ����
//��ȭ���� ��
//���� 

//string �̿��Ͽ� "666"�� �ִ����� Ȯ��

#include <iostream>
#include <string>
using namespace std;

int name_movie(int n);

int main() {
	int n = 0;
	cin >> n;
	if (n < 0 || n>10001) return 0;
	
	cout << name_movie(n);
	

	return 0;
}

int name_movie(int n) {
	int cnt = 0;
    int num = 665;
	string word;
	string six = "6";

	//int to string�� �̿��Ͽ� "6"�� ���� 3�� �ִ����� ��
	while (cnt != n) {
		num++;
		word = to_string(num);
		int cnt_six = 0;
		for (int i = 0; i < word.length(); i++) {
			if (word.at(i) == six.at(0)) {
				cnt_six++;
				if (cnt_six == 3) {
					++cnt;
					break;
				}
			}
			else cnt_six = 0;
		}
	}
	return num;
}