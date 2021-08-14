#include <iostream>
using namespace std;

int N, mp[2200][2200], ans[3];

void qt(int y, int x, int cnt) {
	int chk = 0;
	int dir9[2][9]{ {0,0,0,cnt / 3,cnt / 3,cnt / 3,cnt / 3 * 2,cnt / 3 * 2,cnt / 3 * 2},
		{0,cnt / 3,cnt / 3 * 2,0,cnt / 3,cnt / 3 * 2,0,cnt / 3,cnt / 3 * 2} };
	for (int i = 1; i < cnt; ++i) {
		for (int j = 0; j < cnt; ++j) {  // 가로선에 대해서 다른 값이 있는 경우
			if (mp[y + j][x + i - 1] != mp[y + j][x + i]) {
				chk = 1; break;
			}
		} if (chk) break;
		if (mp[y + i - 1][x] != mp[y + i][x]) {  // 세로선에 대해서 다른 값이 있는 경우
			chk = 1; break;
		}
	}
	if (chk) {  // 다른 값이 있는 경우
		for (int i = 0; i < 9; ++i) qt(y + dir9[0][i], x + dir9[1][i], cnt / 3);
	}
	else ++ans[mp[y][x] + 1];  // 해당 값으로만 채워진 종이의 개수 증가
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> mp[i][j];
	}
	qt(0, 0, N);
	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2] << '\n';  // 종이의 개수 출력
}