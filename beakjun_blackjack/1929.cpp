// beakjun Num.1929
//�Ҽ� ���ϱ�
//�����佺�׳׽��� ü
//���� 

/*
endl ���� \n ���� 
ó�� �ӵ� ����  
flush�� buffer�ȿ� ��� �����͸� ��� ��Ƴ� 

endl �� ��� Ŀ�� ������ + ��� flush
\n �� ��� Ŀ�� ������ but flush ���� �����Ƿ�  �� ���� ��½� buffer�� ��� �ȳ��ü� ����  

inline �Լ� ���� ó���� ����, overhead�� ���� �� �ִ�
������ �� �� obj���Ϸ� ��ȯ�� �Լ� �κ��� ġȯ�Ͽ� ����
*/

/*
�� ���� ����� ���� inline �Լ�
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
