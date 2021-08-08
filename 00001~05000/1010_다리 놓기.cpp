#include <iostream>
using namespace std;

int T, N, M, tmp;
long long c[33][33];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; c[0][0] = 1;
	while (T--) {
		cin >> N >> M;
		if (tmp < M) {    // 구하지 않은 이항 계수인 경우
			for (int i = tmp + 1; i <= M; ++i) {        // 파스칼의 삼각형을 활용한 이항 계수 구하기
				for (int j = 0; j <= i; ++j) {
					if (!j || j == i) c[i][j] = 1;
					else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
				}
			}
			tmp = M;    // 구한 이항 계수의 범위 갱신
		}
		cout << c[M][N] << '\n';    // 다리를 지을 수 있는 경우의 수 출력
	}
}