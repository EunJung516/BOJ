#include <iostream>
using namespace std;

int N, K, d[1010][1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K; d[0][0] = 1;
	for (int i = 1; i <= N; ++i) {    // 파스칼의 삼각형을 활용한 이항 계수 구하기
		for (int j = 0; j <= i; ++j) {
			if (!j || j == i) d[i][j] = 1;
			else d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
		}
	}
	cout << d[N][K];    // 이항 계수를 10007로 나눈 나머지 출력
}