#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, sum, ans, ptr1, ptr2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		cin >> N >> M; sum = ans = ptr1 = ptr2 = 0;
		vector<int> A(N), B(M);
		for (auto& i : A) cin >> i;
		for (auto& i : B) cin >> i;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		while (1) {    // 투포인터 활용
			if (ptr1 == N) break; 
			if (ptr2 == M) {
				ans += sum * (N - ptr1);
				break;
			}
			if (A[ptr1] <= B[ptr2]) {
				ans += sum;
				++ptr1;
				continue;
			}
			else {    // A[ptr1] > B[ptr2]인 경우
				++sum; ++ptr2;
				continue;
			}
			
		}
		cout << ans << '\n';
	}
}