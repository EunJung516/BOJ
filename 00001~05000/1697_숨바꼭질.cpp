#include <iostream>
#include <queue>
using namespace std;

int N, K, location, cnt;
bool visited[100010];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K; visited[N] = 1;
	q.push({ N,0 });
	while (!q.empty()) {
		if (q.front().first == K) {    // 수빈이가 동생을 찾은 경우
			cout << q.front().second; return 0;
		}

		location = q.front().first; cnt = q.front().second + 1;
		if (location - 1 >= 0 && !visited[location - 1]) {
			visited[location - 1] = 1; q.push({ location - 1,cnt });    // X - 1로 이동
		}
		if (location + 1 <= 100000 && !visited[location + 1]) {
			visited[location + 1] = 1; q.push({ location + 1,cnt });    // X + 1로 이동
		}
		if (location * 2 <= 100000 && !visited[location * 2]) {
			visited[location * 2] = 1; q.push({ location * 2,cnt });    // 2 * X의 위치로 이동
		}
		q.pop();
	}
}