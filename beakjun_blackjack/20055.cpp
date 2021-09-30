// beakjoon num.20055
//�����̾� ��Ʈ ���� �κ�

/*
Ǯ�� ���̵��
���� �ϳ��ϳ� �ۼ� 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

vector<int> conveyor; // ������

int main() {
	int n, k = 0;
	int tmp = 0;

	//input
	cin >> n >> k;
	
	for (int i = 0; i < (n*2); i++) {
		cin >> tmp;
		conveyor.push_back(tmp);
	}

	int action_cnt = 0; // ���° �ܰ� 
	int empty_cnt = 0; // ������ 0�� ĭ
	int up_con = 0;  // �ø��� ��ġ
	int down_con = n-1 ; // ������ ��ġ 
	vector<bool>robot(n * 2, false); //�����̾� �κ� ���翩��

	//�ܰ� �ݺ� 
	//���� 4 �̸� ����
	while (empty_cnt < k) {
		action_cnt++;
		// ���� 1
		up_con--;
		down_con--;
		if (up_con < 0) up_con = n * 2 - 1;
		if (down_con < 0) down_con = n * 2 - 1;
		robot[down_con] = false; //������ ��ġ �κ� ����
		
		int cnt = 0;
		int i = down_con;
		int j = 0;

		//����2
		while (cnt<n*2)
		{
			j = i - 1;
			if (j < 0) j = n * 2 - 1;
			//���� �ش�� �κ� 1ĭ ����
			if (robot[i]==false&&robot[j] == true && conveyor[i] >0) {
				robot[j] = false;
				if (down_con != i) robot[i] = true;
				conveyor[i]--;
				if (conveyor[i] == 0) empty_cnt++;
			}
			cnt++;
			i--;
			if (i < 0) i = n*2-1;
		}

		//���� 3
		i = up_con;
		//�ø��� ��ġ �κ� �ø�
		if (robot[i] == false && conveyor[i] > 0) {
			robot[i] = true;
			conveyor[i]--;
			if (conveyor[i] == 0) empty_cnt++;
		}
	
	}

	//output
	cout << action_cnt;
}