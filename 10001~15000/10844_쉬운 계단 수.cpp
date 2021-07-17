#include <iostream>
#include <queue>
using namespace std;

int N, ans, d[10][110];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; 
	for (int i = 1; i <= 9; ++i) d[i][1] = 1;    // 맨 앞에 있는 수의 경우 설정
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (!j) d[j][i] = d[j + 1][i - 1];    // j가 0인 경우
			else if (j == 9) d[j][i] = d[j - 1][i - 1];    // j가 9인 경우
			else d[j][i] = (d[j - 1][i - 1] + d[j + 1][i - 1]) % 1000000000;
		}
	}
	for (int i = 0; i <= 9; ++i) ans = (ans + d[i][N]) % 1000000000;
	cout << ans;
}