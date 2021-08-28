#include <iostream>
using namespace std;

long long N, d[2][100];

void dp(int a) {
	if (a == 1) {
		d[0][1] = d[1][1] = 1; return;
	}
	dp(a - 1);
	d[0][a] = d[0][a - 1] + d[1][a - 1];  // 0인 경우
	d[1][a] = d[0][a - 1];  // 1인 경우
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; dp(N); cout << d[1][N];
}