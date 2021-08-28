#include <iostream>
#include <algorithm>
using namespace std;

int N, an, A[1010], d[1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) {
		d[i] = A[i];
		for (int j = 0; j < i; ++j) {
			if (A[i] > A[j]) d[i] = max(d[i], d[j] + A[i]);  // i에서의 최대 합 갱신
		}
		an = max(an, d[i]);  // 최대 합 갱신
	}
	cout << an;
}