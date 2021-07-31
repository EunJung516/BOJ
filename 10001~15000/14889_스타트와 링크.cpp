#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, ans = 2e9, S[25][25], chk[25];

void bt(int v, int cnt) {
	chk[v] = true;    // 스타트 팀으로 지정
	if (cnt == N / 2) {
		int sum = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (chk[i] && chk[j]) sum += S[i][j];    // 스타트 팀의 능력치는 더하기
				if (!chk[i] && !chk[j]) sum -= S[i][j];    // 링크 팀의 능력치는 빼기
			}
		}
		ans = min(ans, abs(sum)); return;    // 두 팀의 능력치 차이의 최솟값 갱신
	}
	for (int i = v + 1; i <= N; ++i) {
		bt(i, cnt + 1); chk[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) cin >> S[i][j];
	}
	bt(1, 1); cout << ans;
}