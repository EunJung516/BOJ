#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

char t;
ll N, a, p, tmp, cnt[123460];
vector<ll> edges[123460];

ll dfs(ll idx) {
	ll ans = 0;
	for (auto& i : edges[idx]) {
		tmp = dfs(i);
		ans += tmp;
	}
	if (cnt[idx] + ans <= 0) return 0;    // 모든 양이 다음 섬으로 갈 수 없는 경우
	else return cnt[idx] + ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 2; i <= N; ++i) {
		cin >> t >> a >> p; edges[p].push_back(i);
		if (t == 'S') cnt[i] = a;    // 양이 살고 있는 경우
		else cnt[i] = -a;    // 늑대가 살고 있는 경우
	}
	cout << dfs(1);
}