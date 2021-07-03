#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, n;
int board[101][101];
long long d[101][101];

long long dp(int i, int j) {
	if (i >= N || j >= N) return 0;    // 크기를 벗어나는 경우
	if (i == N - 1 && j == N - 1) return 1;    // 가장 오른쪽 아래 칸에 도착한 경우
	if (d[i][j] != -1) return d[i][j];    // 경로의 개수를 구한 경우
	if (board[i][j] == 0) return d[i][j] = 0;    // 종착점인 경우
	return d[i][j] = dp(i + board[i][j], j) + dp(i, j + board[i][j]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; memset(d, -1, sizeof d);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}
	cout << dp(0, 0);
}