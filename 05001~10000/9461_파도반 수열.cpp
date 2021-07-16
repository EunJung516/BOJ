#include <iostream>
using namespace std;

long long T, N, d[110]{ 0,1,1,1, };

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		cin >> N;
		if (!d[N]) {    // P(N)을 구하지 않은 경우
            // i가 4보다 클 때, (i - 2)와 (i - 3)번째 원소의 합이 i번째 원소에 해당하는 값임
			for (int i = 4; i <= N; ++i) d[i] = d[i - 2] + d[i - 3];
		}
		cout << d[N] << '\n';
	}
}