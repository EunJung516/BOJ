#include <iostream>
using namespace std;

int n, m, a, b, par[500010];

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
	for (int i = 1; i < n; ++i) par[i] = i;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		if (find(a) == find(b)) {    // 사이클이 완성된 경우
			cout << i; return 0;
		}
		merge(a, b);
	}
	cout << 0;    // 처리한 이후에도 종료되지 않은 경우
}