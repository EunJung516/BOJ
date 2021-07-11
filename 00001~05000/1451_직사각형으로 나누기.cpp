#include <iostream>
using namespace std;

char ch;
long long N, M, ans, sum1, sum2, sum3;
long long num[110][110], sum[110][110];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> ch; num[i][j] = ch - '0';
			sum[i][j] = num[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (i == N && j == M) continue;
			sum1 = sum[i][j];
			if (i == N) {    // (1, 1) 위치를 포함한 사각형의 하단의 우측 x 좌표가 N인 경우
				for (int k = j + 1; k < M; ++k) {    // ||| 형태로 직사각형을 나눈 경우
					sum2 = sum[N][k] - sum1;
					sum3 = sum[N][M] - sum1 - sum2;
					if (ans < sum1 * sum2 * sum3) ans = sum1 * sum2 * sum3;
				}
				for (int k = 1; k < N; ++k) {    // |: 형태로 직사각형을 나눈 경우
					sum2 = sum[k][M] - sum[k][j];
					sum3 = sum[N][M] - sum1 - sum2;
					if (ans < sum1 * sum2 * sum3) ans = sum1 * sum2 * sum3;
				}
			}
			else if (j == M) {    // (1, 1) 위치를 포함한 사각형의 하단의 우측 y 좌표가 M인 경우
				for (int k = i + 1; k < N; ++k) {    // 가로로 삼등분한 경우
					sum2 = sum[k][M] - sum1;
					sum3 = sum[N][M] - sum1 - sum2;
					if (ans < sum1 * sum2 * sum3) ans = sum1 * sum2 * sum3;
				}
				for (int k = 1; k < M; ++k) {    // 위의 직사각형 아래에 두 개의 직사각형으로 나눈 경우
					sum2 = sum[N][k] - sum[i][k];
					sum3 = sum[N][M] - sum1 - sum2;
					if (ans < sum1 * sum2 * sum3) ans = sum1 * sum2 * sum3;
				}
			}
			else {
				sum2 = sum[i][M] - sum1;    // 아래 직사각형 위에 두 개의 직사각형으로 나눈 경우
				sum3 = sum[N][M] - sum1 - sum2;
				if (ans < sum1 * sum2 * sum3) ans = sum1 * sum2 * sum3;

				sum2 = sum[N][j] - sum1;    // :| 형태로 직사각형을 나눈 경우
				sum3 = sum[N][M] - sum1 - sum2;
				if (ans < sum1 * sum2 * sum3) ans = sum1 * sum2 * sum3;
			}
		}
	}
	cout << ans;
}