#include <iostream>
#include <vector>
using namespace std;

int N, M, A, B, chk, num[2010];
vector<int> adj[2010];

void dfs(int a, int par) {
	num[a] = (num[par] == 1 ? 2 : 1);  // 부모와 다른 숫자를 저장
	for (int i : adj[a]) {
		if (!num[i]) dfs(i, a);  // 다루지 않은 경우
		else if (num[i] == num[a]) {  // 부모와 같은 숫자가 저장된 경우는, 이론이 성립할 수 없는 경우임
			chk = 1; return;
		}
		if (chk) return;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; while (M--) {
		cin >> A >> B; adj[A].push_back(B); adj[B].push_back(A);
	}
	num[0] = 1;
	for (int i = 1; i <= N; ++i) {
		if (!num[i]) {  // 다루지 않은 경우
			dfs(i, 0);
			if (chk) break;  // 이론이 성립할 수 없는 경우
		}
	}

	if (chk) cout << 0;  // 이론이 성립할 수 없는 경우
	else cout << 1;  // 이론이 성립할 수 있는 경우
}