#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M, st = 0, en = 1000000000, mid, sum, ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; vector<int> v(N);
	for (auto& i : v) cin >> i;

	while (st <= en) {    // 이분 탐색 활용
		mid = (st + en) / 2; sum = 0;
		for (auto& i : v) {    // 절단된 나무 길이의 합 계산
			if (i > mid) sum += i - mid;
		}

		if (sum >= M) {    // 절단된 나무 길이의 합이 M 이상인 경우
			st = mid + 1;
			ans = max(ans, mid);
		}
		else en = mid - 1;
	}
	cout << ans;
}