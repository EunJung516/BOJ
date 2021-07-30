#include <iostream>
using namespace std;

int N, maxV = -2e9, minV = 2e9;
int A[15], num[4];

void bt(int idx, int ans, int p1, int p2, int p3, int p4) {
	if (idx > N) {
		if (maxV < ans) maxV = ans;    // 최댓값인 경우
		if (minV > ans) minV = ans;    // 최솟값인 경우
		return;
	}
	if (p1 > 0) bt(idx + 1, ans + A[idx], p1 - 1, p2, p3, p4);    // 덧셈 가능한 경우
	if (p2 > 0) bt(idx + 1, ans - A[idx], p1, p2 - 1, p3, p4);    // 뺄셈 가능한 경우
	if (p3 > 0) bt(idx + 1, ans * A[idx], p1, p2, p3 - 1, p4);    // 곱셈 가능한 경우
	if (p4 > 0) bt(idx + 1, ans / A[idx], p1, p2, p3, p4 - 1);    // 나눗셈 가능한 경우
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	for (int i = 0; i < 4; ++i) cin >> num[i];
	bt(2, A[1], num[0], num[1], num[2], num[3]);
	cout << maxV << '\n' << minV;
}