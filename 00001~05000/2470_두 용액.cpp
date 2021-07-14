#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ptr1, ptr2, sum = 2000000010;
pair<int, int> ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; vector<int> v(N);
	for (auto& i : v) cin >> i;
	sort(v.begin(), v.end()); ptr2 = N - 1;
	while (1) {
		if (ptr1 == ptr2) break;    // 두 포인터가 같은 곳을 가르키면 반복문 탈출
		if (sum > abs(v[ptr1] + v[ptr2])) {
			sum = abs(v[ptr1] + v[ptr2]);
			ans.first = v[ptr1]; ans.second = v[ptr2];
		}
		if (v[ptr1] >= 0) {    // ptr1가 가르키는 곳이 양수인 경우
			if (sum > abs(v[ptr1] + v[ptr1 + 1])) {
				ans.first = v[ptr1]; ans.second = v[ptr1 + 1];
			}
			break;
		}
		if (v[ptr2] <= 0) {    // ptr2가 가르키는 곳이 음수인 경우
			if (sum > abs(v[ptr2] + v[ptr2 - 1])) {
				ans.first = v[ptr2 - 1]; ans.second = v[ptr2];
			}
			break;
		}

		if (v[ptr1] + v[ptr2] == 0) {
			cout << v[ptr1] << ' ' << v[ptr2];
			return 0;
		}
		else if (v[ptr1] + v[ptr2] > 0) --ptr2;
		else if (v[ptr1] + v[ptr2] < 0) ++ptr1;
	}
	cout << ans.first << ' ' << ans.second;
}