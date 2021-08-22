#include <iostream>
using namespace std;

char c;
int N, M, ans, A[55][55], B[55][55];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> c; A[i][j] = c - '0';
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> c; B[i][j] = c - '0';
		}
	}

	for (int i = 1; i <= N; ++i) {  // 왼쪽 위부터 확인
		if (i + 2 > N) break;
		for (int j = 1; j <= M; ++j) {
			if (j + 2 > M) break;
			if (A[i][j] != B[i][j]) {  // 다를 경우 뒤집기
				++ans;
				for (int k1 = 0; k1 < 3; ++k1) {
					for (int k2 = 0; k2 < 3; ++k2) A[i + k1][j + k2] = 1 - A[i + k1][j + k2];
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (A[i][j] != B[i][j]) {  // A를 B로 바꿀 수 없는 경우
				cout << "-1\n"; return 0;
			}
		}
	}
	cout << ans;
}