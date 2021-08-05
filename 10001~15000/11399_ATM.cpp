#include <iostream>
#include <algorithm>
using namespace std;

int N, ans, P[1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> P[i];
	sort(P, P + N); ans = P[0];
	for (int i = 1; i < N; ++i) {
		P[i] += P[i - 1];    // i번째 사람이 걸리는 시간 계산
		ans += P[i];
	}
	cout << ans;    //  걸리는 시간 합의 최솟값 출력
}