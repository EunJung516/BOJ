#include <iostream>
using namespace std;

bool solved;
int cnt, mp[10][10];
pair<int, int> v[85];

void bt(int idx) {
	if (solved || idx == cnt) return;
	for (int i = 1; i < 10; ++i) {
		bool chk = false;
		mp[v[idx].first][v[idx].second] = i;
		for (int j = 0; j < 9; ++j) {
			if (j != v[idx].first && mp[j][v[idx].second] == i) {    // 같은 열에 i가 있는 경우
				chk = true; break;
			}
			if (j != v[idx].second && mp[v[idx].first][j] == i) {    // 같은 행에 i가 있는 경우
				chk = true; break;
			}
		}
		int y = v[idx].first / 3 * 3, x = v[idx].second / 3 * 3;
		for (int j1 = 0; j1 < 3; ++j1) {    // 위치한 3x3 정사각형 안에 i가 있는 경우
			for (int j2 = 0; j2 < 3; ++j2) {
				if (y + j1 == v[idx].first && x + j2 == v[idx].second) continue;
				if (mp[y + j1][x + j2] == i) {
					chk = true; break;
				}
			}
			if (chk) break;
		}
		if (chk) continue;
		
		if (idx + 1 == cnt) {    // 최종 모습을 출력
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) cout << mp[i][j] << ' ';
				cout << '\n';
			}
			solved = true; return;
		}
		bt(idx + 1);
	}
	mp[v[idx].first][v[idx].second] = 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> mp[i][j];
			if (!mp[i][j]) {    // 빈 칸인 경우
				v[cnt].first = i; v[cnt].second = j; ++cnt;
			}
		}
	}
	bt(0);
}