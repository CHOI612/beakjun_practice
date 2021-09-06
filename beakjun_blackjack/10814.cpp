//beakjoon num.10814
//나이순 정렬
//정답

/*
stable sort ->merge sort 
vector pair sort -> compare 사용하여 first만 비교하도록
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

#define For(i,n) for(int i =0; i<(n); ++i) 
bool compare(pair<int, string>a, pair<int, string>b) {
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	//input 
	int n = 0;
	cin >> n;


	int age;
	string name;
	vector <pair<int, string>> member;
	For(i, n) {
		cin >> age >> name;
		member.push_back(make_pair(age, name));
	}

	stable_sort(member.begin(), member.end(),compare);

	For(i, n) {
		cout << member[i].first << " " << member[i].second << "\n";
	}
	return 0;
}