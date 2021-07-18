#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, st, en, mid, ans, cnt;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; vector<int> v(2 * N), square(N);
	for (int i = 0; i < N; ++i) {    // 칸 별 길이 저장
		cin >> v[i]; square[i] = v[i];
	}
	for (int i = N; i < 2 * N; ++i) v[i] = i - N + 1;    // 1부터 N까지 저장
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	st = 0, en = v.size() - 1, ans = 0;
	while (st <= en) {
		mid = (st + en) / 2; cnt = 0;
		for (auto& i : square) {
			if (i >= v[mid]) {
				if (++cnt == v[mid]) break;
			}
			else if (cnt) cnt = 0;
		}

		if (cnt == v[mid]) {    // square이 가능한 경우
			ans = max(ans, v[mid]);
			st = mid + 1;
		}
		else en = mid - 1;
	}
	cout << ans;
}