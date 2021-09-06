// beakjoon num.10989
//�� �����ϱ� 3
//�޸��ʰ� �� �ð� �ʰ�

/*
sort
quick sort
counting sort -> O(n) �ſ� �������̳� �ٸ�  �����ġ �ʿ�*/

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