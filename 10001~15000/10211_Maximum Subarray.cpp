#include <iostream>
#include <algorithm>
using namespace std;

int T, N, an, X[1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		cin >> N; an = -1010; for (int i = 1; i <= N; ++i) {
			cin >> X[i]; X[i] += X[i - 1];
		}
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j <= N; ++j) an = max(an, X[j] - X[i]);  // an 갱신
		}
		cout << an << '\n';  // maximum subarray의 합 출력
	}
}