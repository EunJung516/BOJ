#include <iostream>
using namespace std;

char ch;
int N, mp[65][65];

void qt(int y, int x, int cnt) {
	int ny, nx, chk = 0;
	if (cnt == 1) cout << mp[y][x];
	else {
		for (int i = 1; i < cnt; ++i) {
			for (int j = 0; j < cnt; ++j) {  // 가로선에 대해서 다른 값이 있는 경우
				if (mp[y + j][x + i - 1] != mp[y + j][x + i]) {
					chk = true; break;
				}
			} if (chk) break;
			if (mp[y + i - 1][x] != mp[y + i][x]) {  // 세로선에 대해서 다른 값이 있는 경우
				chk = true; break;
			}
		}
		if (chk) {  // 다른 값이 있는 경우
			cout << '(';
			qt(y, x, cnt / 2);
			qt(y, x + cnt / 2, cnt / 2);
			qt(y + cnt / 2, x, cnt / 2);
			qt(y + cnt / 2, x + cnt / 2, cnt / 2);
			cout << ')';
		}
		else cout << mp[y][x];
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> ch; mp[i][j] = ch - '0';
		}
	}
	qt(0, 0, N);
}