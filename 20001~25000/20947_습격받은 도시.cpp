#include <iostream>
using namespace std;

int N;
char mp[2010][2010], ans[2010][2010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) cin >> mp[i][j];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (mp[i][j] == 'O') {  // 건물인 경우
				int tmp = i - 1;
				while (tmp > 0 && mp[tmp][j] == '.' && !ans[tmp][j]) {  // up
					ans[tmp][j] = 1; --tmp;
				}
				tmp = i + 1;
				while (tmp <= N && mp[tmp][j] == '.' && !ans[tmp][j]) {  // down
					ans[tmp][j] = 1; ++tmp;
				}
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (mp[i][j] == 'O') {  // 건물인 경우
				int tmp = j - 1;
				while (tmp > 0 && mp[i][tmp] == '.' && ans[i][tmp] < 2) {  // left
					ans[i][tmp] = 2; --tmp;
				}
				tmp = j + 1;
				while (tmp <= N && mp[i][tmp] == '.' && ans[i][tmp] < 2) {  // right
					ans[i][tmp] = 2; ++tmp;
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (mp[i][j] == '.' && !ans[i][j]) mp[i][j] = 'B';  // 폭탄이 있어도 되는 경우
		}
	}
	for (int i = 1; i <= N; ++i) {  //  도시의 정보 출력
		for (int j = 1; j <= N; ++j) cout << mp[i][j];
		cout << endl;
	}
}