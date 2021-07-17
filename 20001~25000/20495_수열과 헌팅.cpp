#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a, b, st, en, mid, target, ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	vector<int> minV(N), maxV(N);
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		minV[i] = a - b; maxV[i] = a + b;    // i번째 원소의 최솟값, 최댓값 저장
		v[i] = { minV[i],maxV[i] };
	}
	sort(minV.begin(), minV.end());
	sort(maxV.begin(), maxV.end());

	for (int i = 0; i < N; ++i) {
		st = 0, en = N - 1, target = v[i].first, ans = N;
		while (st <= en) {    // i번째 원소가 있을 수 있는 인덱스의 최솟값 구하기
			mid = (st + en) / 2;
			if (maxV[mid] >= target) {
				ans = min(ans, mid + 1);
				en = mid - 1;
			}
			else st = mid + 1;
		}
		cout << ans << ' ';

		st = 0, en = N - 1, target = v[i].second, ans = 1;
		while (st <= en) {    // i번째 원소가 있을 수 있는 인덱스의 최댓값 구하기
			mid = (st + en) / 2;
			if (minV[mid] <= target) {
				ans = max(ans, mid + 1);
				st = mid + 1;
			}
			else en = mid - 1;
		}
		cout << ans << "\n";
	}
}