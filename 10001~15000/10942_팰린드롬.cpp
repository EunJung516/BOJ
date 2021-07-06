#include <iostream>
#include <cstring>
using namespace std;

int N, M, S, E;
int num[2020];
int d[2020][2020];

bool solution(int S, int E) {
	if (S == E || S + 1 == E) return num[S] == num[E];    // 팰린드롬인 경우
	if (d[S][E] != -1) return d[S][E];    // 이미 확인한 경우, 결과 return
	if (num[S] == num[E]) return d[S][E] = solution(S + 1, E - 1);
	return 0;    // 팰린드롬이 아닌 경우
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(d, -1, sizeof d);
	cin >> N; 
	for (int i = 1; i <= N; ++i)
		cin >> num[i];
	cin >> M; while (M--) {
		cin >> S >> E;
		cout << solution(S, E) << '\n';
	}
}