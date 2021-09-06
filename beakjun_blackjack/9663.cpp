//beakjoon num.9663
//N-Queen
//��Ʈ��ŷ


/*
Q�� ������ �ڸ��� ��ü�� �ƴ� �� �ڸ� �ุ�� ����Ͽ� Ȯ�� �ϵ��� �Ѵ�.
dfs�� ����Ͽ� �ش� �ڸ��� ok�� ���� ���� no�� �� �ڸ� ���̻� ��� ���ϰ� ����
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
using namespace std;
#define For(i,n) for(int i =0; i<(n); ++i) 
int cnt = 0;
int n = 0;



void Q_position(int p, vector<int>q) {

	//�ش� �� ������ �ڸ� check 
	bool board[15] = { 0 };
	For(i, p) {
		int x = i;
		int y = q[i];
		board[y] = true;
		if ((y + p - i) < n) board[y + p - i] = true;
		if ((y - p + i) >= 0) board[y - p + i] = true;
	}

	//�������� ��� ������ �ڸ� ��� Ž��
	if (p == n - 1) {
		For(i, n) {
		if (board[i] != true) cnt++;
		}
	}

	else {
		q.push_back(0);

		For(i,n) {

			if (board[i] != true) {
				q[p] = i;
				Q_position(p + 1,q);
			}


		}


	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//input 
	cin >> n;

	vector<int>q;
	Q_position(0, q);

	//output
	cout <<cnt << "\n";
	return 0;
}

