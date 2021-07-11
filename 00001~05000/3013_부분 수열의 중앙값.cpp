#include <iostream>
using namespace std;

long long N, B, ans, idx;
long long A[100010], sum[100010];
// 왼쪽과 오른쪽의, 홀수 번째와 짝수 번째의 sum에 해당하는 값 개수 저장, 0행은 양수, 1행은 음수
long long cntEvenL[2][100010], cntEvenR[2][100010], cntOddL[2][100010], cntOddR[2][100010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> B;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i]; 
		if (A[i] == B) {    // B인 경우
			sum[i] = sum[i - 1]; idx = i;
			continue;
		}
		else if (A[i] > B) sum[i] = 1 + sum[i - 1];    // B보다 큰 경우
		else sum[i] = sum[i - 1] - 1;    // B보다 작은 경우

		if (sum[i] >= 0) {    // 해당 sum 값이 양수인 경우
			if (idx) {    // B 우측에 있는 경우
				if (i % 2) ++cntOddR[0][sum[i]];
				else ++cntEvenR[0][sum[i]];
			}
			else {    // B 좌측에 있는 경우
				if (i % 2) ++cntOddL[0][sum[i]];
				else ++cntEvenL[0][sum[i]];
			}
		}
		else {    // 해당 sum 값이 음수인 경우
			if (idx) {    // B 우측에 있는 경우
				if (i % 2) ++cntOddR[1][-sum[i]];
				else ++cntEvenR[1][-sum[i]];
			}
			else {    // B 좌측에 있는 경우
				if (i % 2) ++cntOddL[1][-sum[i]];
				else ++cntEvenL[1][-sum[i]];
			}
		}
	}
	ans = cntOddR[0][0];    // B 기준 우측의 sum이 0인 경우의 개수 저장
	if (sum[idx] >= 0) {    // B에 해당되는 인덱스의 sum이 양수인 경우
		if (idx % 2) ans += cntEvenL[0][sum[idx]];
		else ans += cntOddL[0][sum[idx]];
	}
	else {    // B에 해당되는 인덱스의 sum이 음수인 경우
		if (idx % 2) ans += cntEvenL[1][-sum[idx]];
		else ans += cntOddL[1][-sum[idx]];
	}

	for (int i = 0; i <= 100000; ++i) {    // 길이가 홀수이며, 중앙값이 B가 되는 경우 더해주기
		ans += cntEvenL[0][i] * cntOddR[0][i];
		ans += cntEvenL[1][i] * cntOddR[1][i];
		ans += cntOddL[0][i] * cntEvenR[0][i];
		ans += cntOddL[1][i] * cntEvenR[1][i];
	}
	cout << ans;
}