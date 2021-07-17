#include <iostream>
#include <algorithm>
using namespace std;

int n, amount[10010], d[3][10010];
// d의 0행은 해당 열의 번호 포도주를 마시지 않은 경우
// d의 1행은 해당 열의 번호 포도주를 마셨지만 이전 열의 번호 포도주를 마시지 않은 경우
// d의 2행은 해당 열의 번호와 이전 열의 번호 포도주를 연달아 마신 경우

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> amount[i];
	d[1][1] = amount[1];    // 1번 포도주
	d[0][2] = d[1][1]; d[1][2] = amount[2]; d[2][2] = amount[1] + amount[2];    // 2번 포도주
	for (int i = 3; i <= n; ++i) {
		d[0][i] = max(d[0][i - 1], max(d[1][i - 1], d[2][i - 1]));
		d[1][i] = d[0][i - 1] + amount[i];
		d[2][i] = d[1][i - 1] + amount[i];
	}
	cout << max(d[0][n], max(d[1][n], d[2][n]));
}