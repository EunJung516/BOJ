#include <iostream>
using namespace std;

int N, an, d[10][1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; for (int i = 0; i < 10; ++i) d[i][1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = j; k < 10; ++k) d[j][i] = (d[j][i] + d[k][i - 1]) % 10007;  // 전 경우의 수 더하기
		}
	}
	for (int i = 0; i < 10; ++i) an += d[i][N]; cout << an % 10007;
}