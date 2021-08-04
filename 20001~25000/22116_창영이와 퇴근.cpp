#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using tup = tuple<int, int, int>;

int N, ans;
int mp[1010][1010], par[1000010];
priority_queue<tup, vector<tup>, greater<tup>> edge;

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
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> mp[i][j];
			par[i * N + j] = i * N + j;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i + 1 < N) edge.push(make_tuple(abs(mp[i][j] - mp[i + 1][j]), i * N + j, (i + 1) * N + j));    // 오른쪽에 인접한 칸과의 경사 저장
			if (j + 1 < N) edge.push(make_tuple(abs(mp[i][j] - mp[i][j + 1]), i * N + j, i * N + j + 1));    // 아래에 인접한 칸과의 경사 저장
		}
	}
	while (!edge.empty()) {
		int len = get<0>(edge.top()), a = get<1>(edge.top()), b = get<2>(edge.top());
		edge.pop();
		merge(a, b);
		ans = len;    // 경사 저장
		if (find(0) == find(N * N - 1)) break;    // 집에 도착할 수 있는 경우
	}
	cout << ans;    // 최대 경사의 최솟값 출력
}