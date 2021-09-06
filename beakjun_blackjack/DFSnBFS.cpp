//beakjoon num.1260
//DFS와 BFS
//탐색 

/*
참고
https://mygumi.tistory.com/102
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define For(i,n) for(int i =0; i<(n); ++i) 

//인접 행렬 및 재귀 함수 이용 
void dfs(int n, bool* visited, int** a, int v) {

	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i < n+1; i++) {
		if (a[v][i] == 1 && !visited[i]) {
			dfs(n,visited, a, i);
		}
	}
}

//인접 행렬 및 큐 이용
void bfs(int n, bool* visited, int** a, int v) {
	queue<int> q;

	q.push(v);
	visited[v] = true;
	
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		cout << v << " ";

		for (int i = 1; i < n + 1; i++) {
			if (a[v][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	//input 
	int n,m,v = 0;
	cin >> n >> m >> v;
	int x,y = 0;

	bool* visited = new bool[n + 1];
	For(i, n + 1) visited[i] = false;
	int** a = new int*[n+1];
	For(i,n+1){
		a[i] = new int[n+1];
		
	}

	For(i, m) {
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	dfs(n, visited, a, v);
	cout << "\n";
	For(i, n + 1) visited[i] = false;
	bfs(n, visited, a, v);
	return 0;
}

/*
7 10 1
1 2
1 4
2 3
2 5
3 4
3 5
3 6
4 6
5 7
6 7 */