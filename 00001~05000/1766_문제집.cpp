#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B, cur, cnt[32010];
vector<int> v[32010];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie();
	cin >> N >> M; while (M--) {
		cin >> A >> B; v[A].push_back(B);
        ++cnt[B];  // 문제 풀기 전에, 풀어야 할 문제 수 증가
	}
	for (int i = 1; i <= N; ++i) {
		if (!cnt[i]) q.push(i);  // 이전에 풀어야 할 문제가 없는 경우
	}
	while (q.size()) {
		cur = q.top(); q.pop(); cout << cur << ' ';
		for (int i : v[cur]) {
			--cnt[i];  // 문제 풀기 전에, 풀어야 할 문제 수 감소
            if (!cnt[i]) q.push(i);  // 이전에 풀어야 할 문제를 다 푼 경우
		}
	}
}