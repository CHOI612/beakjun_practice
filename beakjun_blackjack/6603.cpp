//beakjoon num.6603
//로또
/*DFS에서 백트래킹 응용
재귀로써 DFS하며 
전체 경우의 수를 한번만 돌기 위하여 백트레킹 사용 
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

