#include <iostream>
#include <map>
using namespace std;

string st1, st2;
int t, n, ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t; while (t--) {
		cin >> n; map<string, int> mp; ans = 1;
		while (n--) {
			cin >> st1 >> st2; ++mp[st2];    // 해당하는 종류의 가짓수 증가
		}
		for (auto& i : mp) ans *= (i.second + 1);
		cout << ans - 1 << '\n';    // 알몸인 상태 제외한 경우의 수 출력
	}
}