#include <iostream>
#include <algorithm>
using namespace std;

long long n, num[505][505], d[505][505];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) cin >> num[i][j];
	}
	for (int i = 1; i <= n; ++i) d[n][i] = num[n][i];    // 맨 아래층 수 설정
	for (int i = n - 1; i > 0; --i) {    // 맨 아래 층에서 해당 층까지의 총합 최댓값 구하기
		for (int j = 1; j <= i; ++j) d[i][j] = max(d[i + 1][j], d[i + 1][j + 1]) + num[i][j];
	}
	cout << d[1][1];
}