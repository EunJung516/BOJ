#include <iostream>
#include <algorithm>
using namespace std;

int n, m, u, sz, an, j;
pair<int, int> s[100001];  // 스택

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n; for (int i = 1; i <= n; ++i) {
		cin >> m;  // i번째 높이 입력
		u = s[sz].second;  // 앞의 높이 저장
		for (j = sz - 1; s[j].second > m; --j) {
			// j번째 높이가 저장된 높이(u)보다 작은 경우
			// 정답 갱신, u에 j번째 높이 저장
			if (s[j].second < u)
				an = max(an, (sz - j) * u), u = s[j].second;
		} an = max(an, (sz - j) * u);
		s[++sz] = { i,m };  // 스택에 현재 정보 저장
	}
	u = s[sz].second; for (int i = sz - 1; i >= 0; --i) {
		// j번째 높이가 저장된 높이(u)보다 작은 경우
		// 정답 갱신, u에 j번째 높이 저장
		if (s[i].second < u)
			an = max(an, (sz - i) * u), u = s[i].second;
	}
	cout << an;
}