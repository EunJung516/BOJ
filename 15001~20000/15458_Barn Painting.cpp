#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll N, K, tmp, d[100010][3], color[100010];
vector<ll> adj[100010];

void dp(ll a, ll par) {
	d[a][0] = d[a][1] = d[a][2] = 1;
	for (ll i : adj[a]) {
		if (i == par) continue;
		dp(i, a);
		tmp = (d[i][1] + d[i][2]) % mod;
		d[a][0] *= tmp; d[a][0] %= mod;  // a의 1번 색상의 경우의 수 계산

		tmp = (d[i][0] + d[i][2]) % mod;
		d[a][1] *= tmp; d[a][1] %= mod;  // a의 2번 색상의 경우의 수 계산

		tmp = (d[i][0] + d[i][1]) % mod;
		d[a][2] *= tmp; d[a][2] %= mod;  // a의 3번 색상의 경우의 수 계산
	}
	if (color[a]) {  // a가 이미 칠해진 경우
		for (ll i = 1; i <= 3; ++i) {
			if (i != color[a]) d[a][i - 1] = 0;  // a에 칠해지지 않은 색깔의 경우의 수를 0으로 저장
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i < N; ++i) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	while (K--) {
		int x, y; cin >> x >> y; color[x] = y;
	}
	dp(1, 0); cout << (d[1][0] + d[1][1] + d[1][2]) % mod;  // 1번의 가능한 경우의 총 합을 mod로 나눈 값 출력
}