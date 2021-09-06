//beakjoon num.6603
//�ζ�
/*DFS���� ��Ʈ��ŷ ����
��ͷν� DFS�ϸ� 
��ü ����� ���� �ѹ��� ���� ���Ͽ� ��Ʈ��ŷ ��� 
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define For(i,n) for(int i =0; i<(n); ++i) 
int n = 0;
int arr[14] = { 0 };
int lotto[6] = { 0 };
void dfs(int depth, int t) {
	if (depth == 6) {
		For(i, 6) {
			cout << lotto[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = t; i < n; i++) {
			lotto[depth] = arr[i];
			dfs(depth + 1, i + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//input
	
	
	while (true) {
		cin >> n;
		if (n == 0) break;
		else {
			For(i, n) {
				cin >> arr[i];
			}
			dfs(0, 0);
			cout << "\n";
		}
	}


	return 0;
}

