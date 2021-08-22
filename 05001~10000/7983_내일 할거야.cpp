#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> PI;

int n, ans;
PI t[1000010];

bool compare(PI a, PI b) {
	return a > b ? true : false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> t[i].second >> t[i].first;
	sort(t, t + n, compare);  // 제출일을 기준으로 내림차순으로 정렬

	ans = t[0].first - t[0].second;
	for (int i = 1; i < n; ++i) {
		if (ans > t[i].first) ans = t[i].first - t[i].second;  // 제출일보다 더 뒤에 있는 경우
		else ans -= t[i].second;
	}
	cout << ans;
}