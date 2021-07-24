#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A, B, C, nxt, ndist, check;
long long dist[505];
vector<pair<int, int>> edges[505];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; fill(dist, dist + N + 1, 1e18);
	while (M--) {
		cin >> A >> B >> C; edges[A].push_back({ B,C });
	}
	dist[1] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (auto& k : edges[j]) {
				nxt = k.first;  ndist = k.second;
				if (dist[j] != 1e18 && dist[nxt] > dist[j] + ndist) {
					dist[nxt] = dist[j] + ndist;
					if (i == N) {    // N번 째에 갱신 가능하다면, 무한히 오래 전으로 되돌릴 수 있는 경우
						check = true; break;
					}
				}
			}
			if (check) break;
		}
		if (check) break;
	}

	if (check) cout << "-1\n";    // 무한히 오래 전으로 되돌릴 수 있는 경우
	else {
		for (int i = 2; i <= N; ++i) {
			if (dist[i] == 1e18) cout << "-1\n";    // 가는 경로가 없는 경우
			else cout << dist[i] << '\n';
		}
	}
}