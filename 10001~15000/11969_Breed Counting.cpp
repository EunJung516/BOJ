#include <iostream>
using namespace std;

int N, Q, tmp, a, b, s[4][100010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) {
		cin >> tmp; ++s[tmp][i];
		for (int j = 1; j <= 3; ++j) s[j][i] += s[j][i - 1];
	}
	while (Q--) {
		cin >> a >> b;
		for (int i = 1; i <= 3; ++i) cout << s[i][b] - s[i][a - 1] << ' ';  // breed 1, 2, 3 순서대로 출력
		cout << '\n';
	}
}