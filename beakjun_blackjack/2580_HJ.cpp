//beakjoon num.2580
//������
//��Ʈ��ŷ 
// ���� �ڵ�

#include <iostream>
using namespace std;

int sudoku[9][9];
int hole_cnt = 0;
bool found = false;

struct hole {
	int row, col;
};

hole* sudo_hole = new hole[81]; //����� ����

bool promising(int hole_index, int candidate) {
	int i, j;
	for (i = 0; i < 9; i++) {
		if (sudoku[sudo_hole[hole_index].row][i] == candidate) //���� �࿡ �ֳ�?
			return false;
		if (sudoku[i][sudo_hole[hole_index].col] == candidate) //���� ���� �ֳ�?
			return false;
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if ((sudo_hole[hole_index].row / 3) == (i / 3) && (sudo_hole[hole_index].col / 3) == (j / 3)) { //���� ������ �ֳ�?(�̰� �����ϴ��� �����)
				if (sudoku[i][j] == candidate)
					return false;
			}
		}
	}
	return true;
}

void fill_sudoku(int cnt) {
	if (cnt == hole_cnt) { //�� ã���� ���
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		found = true; //ù �� ã������ �ٷ� ������
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (promising(cnt, i)) {
				sudoku[sudo_hole[cnt].row][sudo_hole[cnt].col] = i; //�Ʒ��� ������
				fill_sudoku(cnt + 1);
				if (found)
					return;
				sudoku[sudo_hole[cnt].row][sudo_hole[cnt].col] = 0; //���� �ٽ� �ö�(�̰� ���Ծ �����. ���ư� ���� ����� ����)
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				sudo_hole[hole_cnt].row = i;
				sudo_hole[hole_cnt++].col = j;
			}
		}
	}
	fill_sudoku(0);
}