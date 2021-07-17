#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; vector<int> A(N);
	for (auto& i : A) cin >> i;
	sort(A.begin(), A.end());
	while (M--) {
		cin >> D;
		if (binary_search(A.begin(), A.end(), D)) {    // D가 존재하는 경우
			cout << lower_bound(A.begin(), A.end(), D) - A.begin() << '\n';    // 위치 출력
		}
		else cout << "-1\n";    // D가 존재하지 않은 경우
	}
}