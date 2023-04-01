#include <iostream>
using namespace std;

int n, m, tmp, par[201];

int find(int u) {  // 현재 속한 그룹의 대표 번호 반환
	return (par[u] == u ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {  // 그룹끼리 합치기
	int ut = find(u), vt = find(v);
	if (ut != vt) par[ut] = vt;
}

int main() {
	// 입력 및 초기화
	cin >> n >> m; for (int i = 1, k; i <= n; ++i) par[i] = i;
	for (int i = 1, k; i <= n; ++i) for (int j = 1; j <= n; ++j) {
		cin >> k; if (k) merge(i, j);  // 연결돼있다면 그룹 합치기
	}

	cin >> n; tmp = find(n); while (--m) {
		cin >> n; 
		if (tmp != find(n)) {  // 다른 그룹에 속한다면 여행 불가능
			cout << "NO"; return 0;
		}
	}
	cout << "YES";
}