#include <iostream>
#include <queue>
using namespace std;

int N, x;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; while (N--) {
		cin >> x;
		if (x == 0) {    // 가장 큰 값을 출력하고 그 값을 제거
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << '\n'; pq.pop();
			}
		}
		else if (x > 0) {
			pq.push(x);
		}
	}
}