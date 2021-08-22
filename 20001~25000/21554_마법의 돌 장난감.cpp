#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, cnt, idx, tmp;
vector<pair<int, int>> ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; vector<int> v(N);
	for (auto& i : v) cin >> i;
	for (int i = 0; i < N; ++i) {
		if (i + 1 != v[i]) {  // 제자리에 없을 경우, '조작' 하기
			idx = find(v.begin(), v.end(), i + 1) - v.begin();
			for (int j = 0; j < ceil((idx - i) / 2.0); ++j) {
				tmp = v[i + j];
				v[i + j] = v[idx - j];
				v[idx - j] = tmp;
			}
			ans.push_back({ i + 1, idx + 1 });
			++cnt;
			if (cnt > 100) {
				cout << -1; return 0;
			}
		}
	}
	cout << cnt << '\n';
	for (auto& i : ans) cout << i.first << ' ' << i.second << '\n';
}