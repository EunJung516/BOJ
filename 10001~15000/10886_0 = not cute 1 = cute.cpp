#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, ans = 0; cin >> n; while (n--) {
		cin >> m; ans += (m == 0 ? -1 : 1);  // 0일 경우 감소, 1일 경우 증가
	}
	if (ans > 0) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";
}