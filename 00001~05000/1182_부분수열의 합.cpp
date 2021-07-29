#include <iostream>
using namespace std;

int N, S, cnt, sum, num[25];

void dfs(int v) {
	if (v > N) return;
	if (sum + num[v] == S) ++cnt;    // 어떤 수열의 원소의 합이 S가 되는 경우
	dfs(v + 1);    // sum에 num[v]를 포함시키지 않은 경우

	sum += num[v];
	dfs(v + 1);    // sum에 num[v]를 포함시킨 경우
	sum -= num[v];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> S;
	for (int i = 1; i <= N; ++i) cin >> num[i];
	dfs(1); cout << cnt;
}