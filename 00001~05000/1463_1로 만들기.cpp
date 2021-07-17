#include <iostream>
#include <queue>
using namespace std;

int N, tmp, d[1000010];
queue<int> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; q.push(N); d[N] = 0;
	while (!q.empty()) {
		tmp = q.front();
		if (tmp == 1) {    // 1인 경우, 연산 횟수의 최솟값 출력하고 종료
			cout << d[tmp]; return 0;
		}
		if (tmp % 3 == 0 && tmp / 3 && !d[tmp / 3]) {    // X가 3으로 나누어 떨어지고, 3으로 나눈 경우를 다루지 않은 경우
			d[tmp / 3] = d[tmp] + 1; q.push(tmp / 3);
		}
		if (tmp % 2 == 0 && tmp / 2 && !d[tmp / 2]) {    // X가 2로 나누어 떨어지고, 2로 나눈 경우를 다루지 않은 경우
			d[tmp / 2] = d[tmp] + 1; q.push(tmp / 2);
		}
		if (tmp - 1 && !d[tmp - 1]) {    // 1을 뺀 경우를 다루지 않은 경우
			d[tmp - 1] = d[tmp] + 1; q.push(tmp - 1);
		}
		q.pop();
	}
}