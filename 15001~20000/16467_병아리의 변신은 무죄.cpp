#include <iostream>
#include <cstring>
using namespace std;

long long t, k, n, a[15][15], b[15][15], d[28][15][15], mod = 100000007;

void dp(int u, int v) {  // u : 거듭제곱 지수, v : 깊어진 깊이 (dp 배열 저장용)
	if (u == 1) {  // 지수가 1인 경우
		// K가 0이 아닌 경우, 기본 행렬 저장
		if (k) for (int i = 0; i < k + 2; ++i) for (int j = 0; j < k + 2; ++j) d[v][i][j] = a[i][j];
		else d[v][0][0] = 2;  // K가 0인 경우
		return;
	}

	dp(u / 2, v + 1);  // 분할정복
	if (k) {  // K가 0이 아닌 경우, 행렬 계산
		for (int i = 0; i < k + 2; ++i) {
			for (int j = 0; j < k + 2; ++j) {
				for (int l = 0; l < k + 2; ++l) {
					d[v][i][j] += d[v + 1][i][l] * d[v + 1][l][j] % mod;
				}
			}
		}
	}
	else d[v][0][0] = d[v + 1][0][0] * d[v + 1][0][0] % mod;  // K가 0인 경우

	if (u & 1) {  // 홀수인 경우
		if (k) {  // K가 0이 아닌 경우, 행렬 한 번 더 곱해주기
			memset(b, 0, sizeof(b));
			for (int i = 0; i < k + 2; ++i) {
				for (int j = 0; j < k + 2; ++j) {
					for (int l = 0; l < k + 2; ++l) {
						b[i][j] += d[v][i][l] * a[l][j] % mod;
					}
				}
			}
			for (int i = 0; i < k + 2; ++i) for (int j = 0; j < k + 2; ++j) d[v][i][j] = b[i][j];
		}
		else d[v][0][0] *= 2, d[v][0][0] %= mod;  // K가 0인 경우
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t; while (t--) {  // 테스트 케이스
		memset(a, 0, sizeof(a)); memset(d, 0, sizeof(d)); cin >> k >> n;  // 초기화 및 입력
		if (k == 0) {  // K가 0인 경우
			dp(n, 0); cout << d[0][0][0] % mod << '\n'; continue;  // 2^N 출력
		}

		// 행렬 초기화
		a[0][0] = a[0][k] = 1; for (int i = 0; i < k + 1; ++i) a[i + 1][i] = 1;
		if (n <= k) cout << "1\n";  // N이 K 이하인 경우
		else if (n == k + 1) cout << "2\n";  // N이 K + 1인 경우
		else {
			dp(n - k - 1, 0);  // 행렬을 (N - K - 1)번 거듭제곱
			n = d[0][0][0] * 2 % mod; for (int i = 1; i < k + 2; ++i) n += d[0][0][i] % mod;  // N일 후 병아리 수 계산
			cout << n % mod << '\n';  // 출력
		}
	}
}