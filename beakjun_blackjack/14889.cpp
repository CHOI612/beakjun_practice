//beakjoon num.14889
//스타트와 링크
//백트레킹

//전체 팀을 분할 search를 위해 DSF 이용 


#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
using namespace std;

#define For(i,n) for(int i =1; i<=(n); ++i) 
int n = 0;
int num= 0;
int min_ability = 99999;
int ability[21][21] = { 0 };


void set_team(int depth, int team_s[], int t) {
	//check ability
	if (depth == num) {
		vector<int> team_l;
		bool team_check[21] = { 0 };
		int ability_s = 0;
		int ability_l = 0;
		for (int i = 0; i < num; i++) {
			team_check[team_s[i]] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (team_check[i] == false) team_l.push_back(i);
		}
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				ability_s += ability[team_s[i]][team_s[j]];
				ability_l += ability[team_l[i]][team_l[j]];
			}
		}
		int gap = abs(ability_s - ability_l);
		if (gap < min_ability) min_ability = gap;
	}
	//set team
	else {
		for (int i = t; i <= n; i++) {
			team_s[depth] = i;
			set_team(depth + 1, team_s, i+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//input 
	cin >> n;
	num = n / 2;
	For(i, n) {
		For(j, n) {
			cin >> ability[i][j];
		}
	}

	//find the min gap of ability  in all case
	int team_s[11] = { 0 };
	set_team(0, team_s, 1);
	cout << min_ability << "\n";
	
	return 0;
}
