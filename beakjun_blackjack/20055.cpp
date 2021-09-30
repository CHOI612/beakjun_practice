// beakjoon num.20055
//컨베이어 벨트 위의 로봇

/*
풀이 아이디어
과정 하나하나 작성 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

vector<int> conveyor; // 내구도

int main() {
	int n, k = 0;
	int tmp = 0;

	//input
	cin >> n >> k;
	
	for (int i = 0; i < (n*2); i++) {
		cin >> tmp;
		conveyor.push_back(tmp);
	}

	int action_cnt = 0; // 몇번째 단계 
	int empty_cnt = 0; // 내구도 0인 칸
	int up_con = 0;  // 올리는 위치
	int down_con = n-1 ; // 내리는 위치 
	vector<bool>robot(n * 2, false); //컨베이어 로봇 존재여부

	//단계 반복 
	//과정 4 이면 종료
	while (empty_cnt < k) {
		action_cnt++;
		// 과정 1
		up_con--;
		down_con--;
		if (up_con < 0) up_con = n * 2 - 1;
		if (down_con < 0) down_con = n * 2 - 1;
		robot[down_con] = false; //내리는 위치 로봇 내림
		
		int cnt = 0;
		int i = down_con;
		int j = 0;

		//과정2
		while (cnt<n*2)
		{
			j = i - 1;
			if (j < 0) j = n * 2 - 1;
			//조건 해당시 로봇 1칸 전진
			if (robot[i]==false&&robot[j] == true && conveyor[i] >0) {
				robot[j] = false;
				if (down_con != i) robot[i] = true;
				conveyor[i]--;
				if (conveyor[i] == 0) empty_cnt++;
			}
			cnt++;
			i--;
			if (i < 0) i = n*2-1;
		}

		//과정 3
		i = up_con;
		//올리는 위치 로봇 올림
		if (robot[i] == false && conveyor[i] > 0) {
			robot[i] = true;
			conveyor[i]--;
			if (conveyor[i] == 0) empty_cnt++;
		}
	
	}

	//output
	cout << action_cnt;
}