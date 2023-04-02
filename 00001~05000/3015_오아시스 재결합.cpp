// 아직 풀지 못한 문제입니다
#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, u, c = 1, an, s[500001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n; s[0] = 2147483648; for (int i = 1; i <= n; ++i) {
		cin >> m; u = lower_bound(s, s + c, m, greater<long long>()) - s;
		while(u != c)
		an += (u == c ? c : c - u + 1);
		while (c && s[c] < m) --c;
		s[++c] = m;
	}
	cout << an;
}