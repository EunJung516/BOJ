#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans = 2000000010, ptr1, ptr2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; vector<int> A(N);
	for (auto& i : A) cin >> i;
	sort(A.begin(), A.end());    // 정렬
	while (1) {
		if (A[ptr1] - A[ptr2] >= M && ans > A[ptr1] - A[ptr2]) ans = A[ptr1] - A[ptr2];
		if (ptr1 == N - 1 && ptr2 == N - 1) break;    // ptr1과 ptr2 모두 N - 1인 경우
		if (ptr1 == N - 1) {    // ptr1이 N - 1인 경우
			do {
				++ptr2;
			} while (ptr2 <= N - 2 && A[ptr1] - A[ptr2 + 1] >= M);
			if (A[ptr1] - A[ptr2] >= M && ans > A[ptr1] - A[ptr2]) ans = A[ptr1] - A[ptr2];
			break;
		}
		if (ptr1 == ptr2) {    // ptr1과 ptr2가 같은 곳을 가르킬 경우
			do{
				++ptr1;
			} while (ptr1 <= N - 2 && A[ptr1] - A[ptr2] < M);
			continue;
		}

		if (A[ptr1] - A[ptr2] >= M) {
			do {
				++ptr2;
			} while (ptr2 < ptr1 && A[ptr1] - A[ptr2 + 1] >= M);
		}
		if (A[ptr1] - A[ptr2] < M) {
			do {
				++ptr1;
			} while (ptr1 <= N - 2 && A[ptr1] - A[ptr2] < M);
		}
	}
	cout << ans;
}