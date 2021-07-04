#include <iostream>
#include <queue>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> positive;    // 양수
priority_queue<int> negative;    // 음수

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; while (N--) {
		cin >> x;
		if (x == 0) {    // 절댓값이 가장 작은 값을 출력하고 그 값을 제거
			if (positive.empty() && negative.empty()) cout << "0\n";
			else {
				if (positive.empty()) {    // 저장된 양수가 없는 경우
					cout << negative.top() << '\n'; negative.pop();
				}
				else if (negative.empty()) {    // 저장된 음수가 없는 경우
					cout << positive.top() << '\n'; positive.pop();
				}
				else {
					if (positive.top() + negative.top() < 0) {    // 절댓값이 가장 작은 값이 양수인 경우
						cout << positive.top() << '\n'; positive.pop();
					}
					else {
						cout << negative.top() << '\n'; negative.pop();
					}
				}
			}
		}
		else if (x > 0) positive.push(x);
		else negative.push(x);
	}
}