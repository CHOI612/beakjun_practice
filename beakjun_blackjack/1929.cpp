// beakjun Num.1929
//소수 구하기
//에라토스테네스의 체
//정답 

/*
endl 보다 \n 사용시 
처리 속도 증가  
flush는 buffer안에 담긴 데이터를 모두 쏟아냄 

endl 의 경우 커서 다음줄 + 출력 flush
\n 의 경우 커서 다음줄 but flush 하지 않으므로  긴 문장 출력시 buffer에 담겨 안나올수 있음  

inline 함수 빠른 처리를 위함, overhead를 줄일 수 있다
컴파일 시 즉 obj파일로 변환시 함수 부분을 치환하여 생성
*/

/*
더 빠른 출력을 위한 inline 함수
//Fast Write 
static const int buf_size = 1 << 16;

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char end) {
	if (x < 0) writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n) s[n++] = '0' + x % 10, x /= 10;
	while (n--) writeChar(s[n]);
	if (end) writeChar(end);
}

inline void writeWord(const char *s) {
	while (*s) writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;
*/

#include <iostream>
#include <cmath>
using namespace std;


void prime_number(int m, int n);

int main() {
	int n = 0;
	int m = 0;
	cin >> m;
	cin >> n;
	if (m < 1 || n>1000000) return 0;
	if (m > n) return 0;
	
	prime_number(m, n);

	return 0;
}

void prime_number(int m, int n) {

	int* number = new int[n + 1];
	number[0] = 0;
	number[1] = 0;
	for (int i = 2; i <= n ; i++) {
		number[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (number[i] == 0) continue;
		for (int j = i * 2; j <= n; j += i) {
			number[j] = 0;
		}
	}
	for (int i = m; i <= n; i++) {
		if (number[i] != 0) cout << number[i] << '\n';
	}

}
