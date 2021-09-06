// beakjoon num.10989
//수 정렬하기 3
//메모리초과 및 시간 초과

/*
sort
quick sort
counting sort -> O(n) 매우 빠른편이나 다른  기억장치 필요*/

//Counting sort

#include<iostream>
#include<algorithm>

using namespace std;


int main() {

	int n=0;

	cin >> n ;
	if (n < 1 || n>10, 000, 000) return 0;

	int* a = new int[n+1];
	int* b = new int[n+1];
	int max_num = 0;
	int count[10001] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		count[a[i]]++;
		b[i] = 0;
		if (a[i] > max_num) max_num = a[i];
	}
	
	for (int j = 1; j < max_num + 1; j++) {
		count[j] += count[j - 1];
	}

	for (int i = n-1; i >=0; i--) {
		b[count[a[i]]] = a[i];		
		count[a[i]]--;
	}

	for (int i = 1; i < n+1; i++) {
		cout << b[i] << "\n";
	}
	
	return 0;
}