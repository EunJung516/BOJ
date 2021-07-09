#include <iostream>
#include <queue>
using namespace std;

int N, K, location, cnt, ans;
int visited[100010];
bool check;
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	q.push({ N,0 });
	while (!q.empty()) {
		location = q.front().first; cnt = q.front().second + 1;
		if (location == K) ++ans;    // 수빈이가 동생을 찾은 경우
		else if (location > K) {    // K가 현재 위치보다 작을 경우
			if (location - 1 >= 0) {    // X - 1로 이동
				if (!visited[location - 1]) {    // 이전에 도착하지 않은 경우, 도착까지의 최단시간 저장
					visited[location - 1] = cnt; q.push({ location - 1,cnt });
				}
				else if (visited[location - 1] == cnt) q.push({ location - 1,cnt });    // 최단시간과 같은 시간에 도착한 경우
			}
		}
		else if (1.5 * location > K) {    // K가 location의 1.5배보다 작을 경우
			if (location - 1 >= 0) {
				if (!visited[location - 1]) {
					visited[location - 1] = cnt; q.push({ location - 1,cnt });
				}
				else if (visited[location - 1] == cnt) q.push({ location - 1,cnt });
			}
			if (location + 1 <= 100000) {
				if (!visited[location + 1]) {
					visited[location + 1] = cnt; q.push({ location + 1,cnt });
				}
				else if (visited[location + 1] == cnt) q.push({ location + 1,cnt });
			}
		}
		else {    // K가 현재 위치보다 클 경우
			if (location - 1 >= 0) {    // X - 1로 이동
				if (!visited[location - 1]) {
					visited[location - 1] = cnt; q.push({ location - 1,cnt });
				}
				else if (visited[location - 1] == cnt) q.push({ location - 1,cnt });
			}
			if (location + 1 <= 100000) {    // X + 1로 이동
				if (!visited[location + 1]) {
					visited[location + 1] = cnt; q.push({ location + 1,cnt });
				}
				else if (visited[location + 1] == cnt) q.push({ location + 1,cnt });
			}
			if (location * 2 <= 100000) {    // 2 * X의 위치로 이동
				if (!visited[location * 2]) {
					visited[location * 2] = cnt; q.push({ location * 2,cnt });
				}
				else if (visited[location * 2] == cnt) q.push({ location * 2,cnt });
			}
		}
		q.pop();
	}
	cout << visited[K] << '\n' << ans;
}