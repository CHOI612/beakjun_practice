// beakjoon num.21608
//��� �ʵ��б�
//����

/*
!���� ���� �κ�!
���� ���� Ȯ�� �� ���� -> nn�� n ���� ���� Ȯ��
������ �ʹ� ���� -> ������ �ȵȴ�
���� ���� >> <cmath> pow �Լ� �̿�
�ֺ��� ģ���� ���� �� �ڸ��� ���� ��� > ���ǿ� �ش����� �ʴ� ������ ��������
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<bool>> position(21, vector <bool>(21,0));
vector<vector<int>> relation(401, vector <int>(6,0));
queue<int> number;
vector<pair<int,int>> set_p;

int main() {
	ios_base::sync_with_stdio(false);
	int n= 0;
	int s, f = 0;
	

	vector<pair<int, int>>check;
	check.push_back(make_pair(0, -1));
	check.push_back(make_pair(0, 1));
	check.push_back(make_pair(-1, 0));
	check.push_back(make_pair(1, 0));

	//input
	cin >> n;
	int nn = n * n;
	set_p.push_back(make_pair(-1, -1));

	for (int i = 1; i <= nn; i++) {
		cin >> s;
		number.push(s);
		set_p.push_back(make_pair(-1, -1));
		for (int j = 0; j < 4; j++) {
			cin >> f;
			relation[s][j] = f;
		}
	}

	int cnt = 0;
	int max_value = 0;
	int value, empty = 0;
	int max_value_r, max_value_c = 0;
	int max_value_empty = 0;
	int rr, cc = 0;
	int tmp = 0;

	//�л� �ڸ� ���ϱ�
	while (cnt < nn) {
		//max ���� �ʱ�ȭ
		max_value = 0;
		max_value_r = 0;
		max_value_c = 0;
		max_value_empty = 0;
		rr, cc = 0;
		tmp = 0;

		//�ڸ��� ���� ��� Ȯ��
		s = number.front();
		number.pop();

		//��� �ڸ� Ȯ��
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				//�����ʱ�ȭ
				value = 0;
				empty = 0;
				rr, cc = 0;
				if (!position[r][c]) {
					//ģ�ѻ�� 4�� �ڸ� Ȯ��
					for (int j = 0; j < 4; j++) {
						f = relation[s][j];
						rr = set_p[f].first;
						cc = set_p[f].second;
						if (rr != -1) {
							if ((abs(r - rr) + abs(c - cc)) == abs(1)) value++;
						}
					}

					//�ֺ� ��� �ִ� �ڸ� Ȯ�� 
					for (int i = 0; i < 4; i++) {
						rr = r + check[i].first;
						cc = c + check[i].second;
						if (rr >= 0 && rr < n) {
							if (cc >= 0 && cc < n) {
								if (!position[rr][cc]) empty++;
							}
						}
					}
			
					//max�� Ȯ��
					//����ĭ �߿����� ����ִ� �ڸ� ž�̵���
					//���� ��� ���� 3�� ���� ������Ʈ ���� ����
					if (max_value == value && max_value_empty < empty) {
							max_value_c = c;
							max_value_r = r;
							max_value_empty = empty;
					}
					else if (max_value < value) {
							max_value = value;
							max_value_c = c;
							max_value_r = r;
							max_value_empty = empty;
					}
					//�ֺ��� ģ���� ���� �� �ڸ��� ���� ���
					if (max_value_empty == 0 && max_value_empty == 0 && tmp==0) {
						max_value_c = c;
						max_value_r = r;
						tmp++;
						//cout << " ģ��&���ڸ� no" << s << " " << r << " " << c << "\n";
					}
				}
			}
		}

		//�ְ��� ��ġ�� �ڸ� �ɱ�
		set_p[s].first = max_value_r;
		set_p[s].second = max_value_c;
		
		position[max_value_r][max_value_c] = true;
		cnt++;

	}

	int total_satisfaction = 0;
	int sat = 0;
	cnt = 1;
	int r, c = 0;
	//�л��� ������ ���ϱ�
	while (cnt <= nn) {

		r = set_p[cnt].first;
		c = set_p[cnt].second;
		sat = 0;

		for (int j = 0; j < 4; j++) {
			f = relation[cnt][j];

			rr = set_p[f].first;
			cc = set_p[f].second;

			if (rr != -1) {
				if ((abs(r - rr) + abs(c - cc)) == abs(1)) {
					sat++;
				}
			}
		}

		if(sat!=0)total_satisfaction = total_satisfaction + pow(10,(sat-1));
		cnt++;
	}
	cout << total_satisfaction << "\n";
	return 0;
}





