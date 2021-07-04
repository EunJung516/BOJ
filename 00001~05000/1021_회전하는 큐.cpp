#include <iostream>
#include <deque>
using namespace std;

int N, M, ans, location, cnt;
deque<int> dq, locations;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; while (M--) {
		cin >> location; locations.push_back(location);
	}
	for (int i = 1; i <= N; ++i) dq.push_back(i);

	while (!locations.empty()) {
		if (dq.front() == locations.front()) {   // 1번 연산
			dq.pop_front(); locations.pop_front();
			continue;
		}

		cnt = 0;
		for (deque<int>::iterator iter = dq.begin(); iter != dq.end(); ++iter) {
			if (*iter == locations.front()) break;
			++cnt;
		}
		if (cnt <= dq.size() / 2) {    // 2번 연산
			ans += cnt;
			while (cnt--) {
				dq.push_back(dq.front()); dq.pop_front();
			}
		}
		else {    // 3번 연산
			cnt = dq.size() - cnt;
			ans += cnt;
			while (cnt--) {
				dq.push_front(dq.back()); dq.pop_back();
			}
		}
	}
	cout << ans;
}