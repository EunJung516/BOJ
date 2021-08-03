#include <iostream>
using namespace std;

int n, m, c, a, b, par[1000010];

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
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) par[i] = i;
	while (m--) {
		cin >> c >> a >> b;
		if (c) {
			if (find(a) == find(b)) cout << "YES\n";    // 두 원소가 같은 집합에 포함된 경우
			else cout << "NO\n";    // 두 원소가 같은 집합에 포함되지 않은 경우
		}
		else merge(a, b);    // 집합 합치기
	}
}