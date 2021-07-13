#include <iostream>
#include <vector>
using namespace std;

long long N, M, ptr1, ptr2;
int A[1000010], B[1000010];
vector<int> ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < M; ++i) cin >> B[i];
	while (1) {    // 투포인터 활용
		if (ptr1 == N && ptr2 == M) break;
		if (ptr1 == N) {
			while (ptr2 != M) {
				ans.push_back(B[ptr2]);
				++ptr2;
			}
			break;
		}
		if (ptr2 == M) {
			while (ptr1 != N) {
				ans.push_back(A[ptr1]);
				++ptr1;
			}
			break;
		}
		if (A[ptr1] <= B[ptr2]) {
			ans.push_back(A[ptr1]);
			++ptr1;
			continue;
		}
		if (A[ptr1] > B[ptr2]) {
			ans.push_back(B[ptr2]);
			++ptr2;
			continue;
		}
	}
	for (auto& i : ans) cout << i << ' ';
}