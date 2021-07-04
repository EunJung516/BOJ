#include <iostream>
#include <queue>
using namespace std;

int N, n;
priority_queue<int, vector<int>, greater<int>> big;    // 중간값을 기준으로 큰 수
priority_queue<int> small;    // 작은 수

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; while (N--) {
		cin >> n;
		if (!big.empty() && big.top() < n) big.push(n);
		else small.push(n);

        // big의 크기와 small의 크기가 같거나, small의 크기가 1만큼 더 큰 경우로 맞추기
		if (small.size() != big.size() && small.size() < big.size() + 1) {
			small.push(big.top()); big.pop();
		}
		else if (small.size() > big.size() + 1) {
			big.push(small.top()); small.pop();
		}

		cout << small.top() << '\n';
	}
}