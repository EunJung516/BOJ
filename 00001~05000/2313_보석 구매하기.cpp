#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;
typedef pair<PI, ll> PII;

ll n, l, tmp, tmpS, ans, L[1010], sum[1010];
PII p;
vector<PII> v;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n; while (n--) {
		cin >> l; tmpS = -10010; fill(sum, sum + l + 1, 0);
		for (int i = 1; i <= l; ++i) {
			cin >> L[i]; sum[i] = L[i] + sum[i - 1];  // 누적합 계산
		}
		for (int i = 0; i < l; ++i) {
			for (int j = i + 1; j <= l; ++j) {
				tmp = sum[j] - sum[i];
				if (tmpS < tmp) {  // 이전의 합보다 큰 경우
					tmpS = tmp; p = { {i + 1,j},j - i };
				}
				else if (tmpS == tmp && p.second > (j - i)) p = { {i + 1,j},j - i };  // 이전의 합의 최대값과 같고, 보석의 개수가 더 적은 경우
			}
		}
		ans += tmpS; v.push_back(p);
	}

	cout << ans << '\n';
	for (auto& i : v) cout << i.first.first << ' ' << i.first.second << '\n';
}