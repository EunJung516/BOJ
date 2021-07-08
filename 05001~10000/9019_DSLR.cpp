#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, A, B, num;
string str;
bool visited[10010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		memset(visited, 0, sizeof visited);
		queue<pair<int, string>> q;
		cin >> A >> B; visited[A] = 1;
		q.push({ A,"" });

		while (!q.empty()) {
			if (q.front().first == B) {    // B로 변환된 경우
				cout << q.front().second << '\n'; break;
			}

			num = q.front().first; str = q.front().second;
			if (!visited[num * 2 % 10000]) {    // D를 수행한 값에 도출되지 않은 경우
				visited[num * 2 % 10000] = 1; q.push({ num * 2 % 10000, str + 'D' });
			}
			if (!visited[(10000 + num - 1) % 10000]) {    // S를 수행한 값에 도출되지 않은 경우
				visited[(10000 + num - 1) % 10000] = 1; q.push({ (10000 + num - 1) % 10000, str + 'S' });
			}
			if (!visited[num * 10 % 10000 + num / 1000]) {    // L를 수행한 값에 도출되지 않은 경우
				visited[num * 10 % 10000 + num / 1000] = 1; q.push({ num * 10 % 10000 + num / 1000, str + 'L' });
			}
			if (!visited[num / 10 + num % 10 * 1000]) {    // R를 수행한 값에 도출되지 않은 경우
				visited[num / 10 + num % 10 * 1000] = 1; q.push({ num / 10 + num % 10 * 1000, str + 'R' });
			}
			q.pop();
		}
	}
}