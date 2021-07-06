#include <iostream>
#include <vector>
using namespace std;

int N, root, ans, par;
vector<int> child[55];

void dfs(int i) {
	if (i == N) return;    // 제거된 노드인 경우
	if (child[i].empty()) {    // 리프 노드인 경우
		++ans;
		return;
	}
	for (auto& next : child[i]) {
		if (next == N && child[i].size() == 1) ++ans;    // 제거된 노드만을 자식으로 가진 경우
		else dfs(next);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> par;
		if (~par) child[par].push_back(i);
		else root = i;    // -1인 경우 root에 저장
	}
	cin >> N;
	dfs(root);
	cout << ans;
}