#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using tup = tuple<int, int, int>;

int V, E, A, B, C, ans, cnt;
int par[10010];
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
	cin >> V >> E; 
	for (int i = 1; i <= V; ++i) par[i] = i;
	while (E--) {
		cin >> A >> B >> C;
		edge.push(make_tuple(C, A, B));
	}
	
	while (!edge.empty() || cnt < V - 1) {
		int weight = get<0>(edge.top()),
			a = get<1>(edge.top()),
			b = get<2>(edge.top());
		edge.pop();

		if (find(a) == find(b)) continue;    // 정점이 연결된 경우
		merge(a, b);
		ans += weight;    // 가중치 추가
		++cnt;
	}
	cout << ans;    // 최소 스패닝 트리의 가중치를 출력
}