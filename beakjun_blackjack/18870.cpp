//beakjoon num.18870
//��ǥ ����
//���� 

//sorting
//low_bound�� find���� ���� -> find �ð��ʰ����

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

#define For(i,n) for(int i =0; i<(n); ++i) 

int main() {
	ios_base::sync_with_stdio(false);
	//input 
	int n = 0;
	cin >> n;

	int point = 0;
	vector <int> coordinate;
	vector <int> input;
	For(i, n) {
		cin >>point;
		input.push_back(point);
		coordinate.push_back(point);
	}

	sort(coordinate.begin(), coordinate.end());
	coordinate.erase(unique(coordinate.begin(), coordinate.end()), coordinate.end());
	For(i, n) {
		//cout << find(coordinate.begin(), coordinate.end(), input[i]) - coordinate.begin() << " ";
		cout << lower_bound(coordinate.begin(), coordinate.end(), input[i]) - coordinate.begin() << " ";
	}


	cout << "\n";
	return 0;
}