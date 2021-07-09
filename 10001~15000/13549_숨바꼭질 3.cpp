#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, K, location, cnt;
int visited[100010];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K; visited[N] = 0;
	q.push({ N,0 });
	memset(visited, -1, sizeof visited);
	while (!q.empty()) {
		location = q.front().first; cnt = q.front().second;
		if (location == K) {    // 수빈이가 동생을 찾은 경우
			if (visited[K] == -1) visited[K] = cnt;    // 이전에 도착하지 않은 경우, 시간 저장
			else if (visited[K] > cnt) visited[K] = cnt;    // 저장된 시간보다 더 적은 시간에 도착할 수 있는 경우
		}
		else if (K < location) {    // K가 현재 위치보다 작을 경우
			if (location - 1 >= 0 && (visited[location - 1] == -1 || visited[location - 1] > cnt + 1)) {    // X - 1로 이동
				visited[location - 1] = cnt + 1; q.push({ location - 1,cnt + 1 });
			}
		}
		else if (1.5 * location > K) {    // K가 location의 1.5배보다 작을 경우
			if (location - 1 >= 0 && (visited[location - 1] == -1 || visited[location - 1] > cnt + 1)) {    // X - 1로 이동
				visited[location - 1] = cnt + 1; q.push({ location - 1,cnt + 1 });
			}
			if (location + 1 <= 100000 && (visited[location + 1] == -1 || visited[location + 1] > cnt + 1)) {    // X + 1로 이동
				visited[location + 1] = cnt + 1; q.push({ location + 1,cnt + 1 });
			}
		}
		else {    // K가 현재 위치보다 클 경우
			if (location - 1 >= 0 && (visited[location - 1] == -1 || visited[location - 1] > cnt + 1)) {    // X - 1로 이동
				visited[location - 1] = cnt + 1; q.push({ location - 1,cnt + 1 });
			}
			if (location + 1 <= 100000 && (visited[location + 1] == -1 || visited[location + 1] > cnt + 1)) {    // X + 1로 이동
				visited[location + 1] = cnt + 1; q.push({ location + 1,cnt + 1 });
			}
			if (location * 2 <= 100000 && (visited[location * 2] == -1 || visited[location * 2] > cnt)) {    // 2 * X의 위치로 이동
				visited[location * 2] = cnt; q.push({ location * 2,cnt });
			}
		}
		q.pop();
	}
	cout << visited[K];
}