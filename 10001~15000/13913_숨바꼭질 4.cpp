#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N, K, location, cnt;
int visited[100010], path[100010];
queue<pair<int, int>> q;
stack<int> st;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K; visited[N] = 1;
	q.push({ N,0 });
	while (!q.empty()) {
		location = q.front().first; cnt = q.front().second + 1;
		if (location == K) {    // 수빈이가 동생을 찾은 경우
			cout << cnt - 1 << '\n';
            // 지나온 경로를 st에 저장
			for (int i = K; i != N; i = path[i]) st.push(i);
			st.push(N);
			while (!st.empty()) {
				cout << st.top() << ' '; st.pop();
			}
			return 0;
		}

		if (K < location) {    // K가 현재 위치보다 작을 경우
			if (location - 1 >= 0 && !visited[location - 1]) {    // X - 1로 이동
				visited[location - 1] = 1; q.push({ location - 1,cnt });
				path[location - 1] = location;
			}
		}
		else if (1.5 * location > K) {    // K가 location의 1.5배보다 작을 경우
			if (location - 1 >= 0 && !visited[location - 1]) {    // X - 1로 이동
				visited[location - 1] = 1; q.push({ location - 1,cnt });
				path[location - 1] = location;
			}
			if (location + 1 <= 100000 && !visited[location + 1]) {    // X + 1로 이동
				visited[location + 1] = 1; q.push({ location + 1,cnt });
				path[location + 1] = location;
			}
		}
		else {    // K가 현재 위치보다 클 경우
			if (location - 1 >= 0 && !visited[location - 1]) {    // X - 1로 이동
				visited[location - 1] = 1; q.push({ location - 1,cnt });
				path[location - 1] = location;
			}
			if (location + 1 <= 100000 && !visited[location + 1]) {    // X + 1로 이동
				visited[location + 1] = 1; q.push({ location + 1,cnt });
				path[location + 1] = location;
			}
			if (location * 2 <= 100000 && !visited[location * 2]) {    // 2 * X의 위치로 이동
				visited[location * 2] = 1; q.push({ location * 2,cnt });
				path[location * 2] = location;
			}
		}
		q.pop();
	}
}