#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using tup = tuple<int, int, int>;

int N, M, A, B, C, ans, cnt;
int par[100010];
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
	cin >> N >> M; 
	for (int i = 1; i <= N; ++i) par[i] = i;
	while (M--) {
		cin >> A >> B >> C;
		edge.push(make_tuple(C, A, B));
	}
	
	while (!edge.empty() && cnt < N - 2) {    // 한 집을 제외한 나머지 집을 모두 연결할 때까지 반복
		int weight = get<0>(edge.top()),
			a = get<1>(edge.top()),
			b = get<2>(edge.top());
		edge.pop();

		if (find(a) == find(b)) continue;    // 도시가 연결된 경우
		merge(a, b);
		ans += weight;    // 유지비 추가
		++cnt;
	}
	cout << ans;    // 유지비 최솟값 출력
}