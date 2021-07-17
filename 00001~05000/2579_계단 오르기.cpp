#include <iostream>
#include <algorithm>
using namespace std;

int N, score[303], d[3][303];
// d의 0행은 해당 열의 계단을 밟지 않은 경우
// d의 1행은 해당 열의 계단을 밟지만 해당 열의 윗계단을 밟지 않은 경우
// d의 2행은 해당 열의 계단과 해당 열의 윗계단을 연달아 밟은 경우

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> score[i];
	d[1][N] = score[N];    // N번째 계단
	d[0][N - 1] = score[N]; d[2][N - 1] = score[N] + score[N - 1];    // N - 1번째 계단
	for (int i = N - 2; i >= 1; --i) {
		d[0][i] = max(d[1][i + 1], d[2][i + 1]);
		d[1][i] = d[0][i + 1] + score[i];
		d[2][i] = d[1][i + 1] + score[i];
	}
	cout << max(d[0][1], max(d[1][1], d[2][1]));
}