#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, X, st, en, mid;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; vector<int> v(N);
	for (auto& i : v) cin >> i;
	sort(v.begin(), v.end());
	cin >> M; while (M--) {    // 이분 탐색 활용한 수 찾기
		cin >> X;
		st = 0; en = N - 1; 
		while (st <= en) {
			mid = (st + en) / 2;
			if (X == v[mid]) break;
			else if (X < v[mid]) en = mid - 1;
			else st = mid + 1;
		}
		if (X == v[mid]) cout << "1\n";
		else cout << "0\n";
	}
}