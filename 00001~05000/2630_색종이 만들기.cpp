#include <iostream>
#include <queue>
using namespace std;

int N, cntW, cntB, y, x, cnt, chk;
int mp[130][130];
queue<pair<int, pair<int, int>>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) cin >> mp[i][j];
	}
	
	q.push({ N,{1,1} });
	while (!q.empty()) {
		cnt = q.front().first, y = q.front().second.first, x = q.front().second.second;
		chk = false; q.pop();
		for (int i = 1; i < cnt; ++i) {
			for (int j = 0; j < cnt; ++j) {
				if (mp[y + j][x + i - 1] != mp[y + j][x + i]) {    // 가로선에 다른 색깔이 있는 경우
					chk = true; break;
				}
			} if (chk) break;
			if (mp[y + i - 1][x] != mp[y + i][x]) {    // x열을 기준으로 세로선에 다른 색깔이 있는 경우
				chk = true; break;
			}
		}
		if (cnt != 1 && chk) {    // 칸의 수가 1이 아니고, 다른 색깔이 있는 경우
			q.push({ cnt / 2, {y, x} });
			q.push({ cnt / 2, {y + cnt / 2, x} });
			q.push({ cnt / 2, {y, x + cnt / 2} });
			q.push({ cnt / 2, {y + cnt / 2, x + cnt / 2} });
		}
		else {
			if (mp[y][x]) ++cntB;    // 색깔이 파란색인 경우
			else ++cntW;    // 색깔이 하얀색인 경우
		}
	}
	cout << cntW << '\n' << cntB;
}