// beakjoon num.10989
//수 정렬하기 3
//정답 

//Counting sort
// input & output에서 사용하는 함수에서 따라 속도 차이 
//input을 저장하지 않아도 된다 -> 메모리 저장 차원
//counting 중에서도 다시 b배열로 저장 후 출력이 아닌 counting된 데로 출력

// cout의 data type을 확인 후 출력 -> 출력시간이 길다 
//	ios_base::sync_with_stdio(false) -> 사용해서 data type를 확인을 하지 않고 출력

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
	//max를 찾아서 -> count 배열의 범위를 제한
	for (int j = 1; j < max_num + 1; j++) {
		while (count[j] > 0) {
			cout << j << "\n";
			count[j]--;
		}
	}

	return 0;
}