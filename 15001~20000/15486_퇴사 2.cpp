#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> T, P, d;

int dp(int idx) {
	if (idx > N) return (int)-1e9;    // 상담할 수 없는 경우
	if (idx == N) return 0;    // 주어진 기간에 상담이 끝나는 경우
	if (d[idx] != -1) return d[idx];    // 해당 날의 최대 수익이 이미 구해진 경우
	return d[idx] = max(dp(idx + 1), dp(idx + T[idx]) + P[idx]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; T = vector<int>(N); P = vector<int>(N); d = vector<int>(N, -1);
	for (int i = 0; i < N; i++)
		cin >> T[i] >> P[i];
	cout << dp(0);
}