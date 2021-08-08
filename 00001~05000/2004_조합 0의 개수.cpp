#include <iostream>
using namespace std;
typedef long long ll;

ll n, m, ans, cnt5, cnt2;

ll count5(ll i) {    // 5로 몇 번 나누어지는지 구하기
	ll tmp5 = i / 5, tmp = 0;
	while (tmp5) {
		tmp += tmp5; tmp5 /= 5;
	}
	return tmp;
}

ll count2(ll i) {    // 2로 몇 번 나누어지는지 구하기
	ll tmp2 = i / 2, tmp = 0;
	while (tmp2) {
		tmp += tmp2; tmp2 /= 2;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	cnt5 = count5(n) - count5(m) - count5(n - m);
	cnt2 = count2(n) - count2(m) - count2(n - m);
	cout << (cnt5 < cnt2 ? cnt5 : cnt2);
}