#include <iostream>
using namespace std;

long long N, ans;
long long len[100010], v[100010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> len[i];
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		if (i && v[i - 1] < v[i]) v[i] = v[i - 1];    // 이전 주유소의 리터당 가격이 싸다면, 이전 주유소의 리터당 가격으로 갱신
	}
	for (int i = 0; i < N - 1; ++i) ans += len[i] * v[i];
	cout << ans;
}