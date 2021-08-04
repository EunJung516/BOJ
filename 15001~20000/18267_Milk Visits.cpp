#include <iostream>
using namespace std;

char C;
int N, M, X, Y, A, B, par[100010];
string ans, str;

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}
void merge(int a, int b) {
	int a_root = find(a), b_root = find(b);
	if (a_root != b_root) par[a_root] = b_root;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> str;
	for (int i = 1; i <= N; ++i) par[i] = i;
	while (--N) {
		cin >> X >> Y;
		if (str[X - 1] == str[Y - 1]) merge(X, Y);    // 같은 종류의 우유라면 병합
	}
	while (M--) {
		cin >> A >> B >> C;
		if (find(A) == find(B) && str[A - 1] != C) ans += "0";    // 원치 않은 우유의 종류만 있다면 0
		else ans += "1";    // 위 경우를 제외한 경우는 모두 1
	}
	cout << ans;
}