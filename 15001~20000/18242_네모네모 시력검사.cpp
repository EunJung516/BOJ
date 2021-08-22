#include <iostream>
using namespace std;

char mp[110][110];
int N, M, chk = 1;
pair<int, int> st, en;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> mp[i][j];
			if (chk == 1 && mp[i][j] == '#') {
				chk = 2; st = { i,j };  // 색칠된 곳의 윗변의 왼쪽 꼭짓점 저장
			}
			else if (chk == 2 && mp[i][j] == '#') {
				en = { i,j };  // 색칠된 곳의 아랫변의 오른쪽 꼭짓점 갱신
			}
		}
		if (chk == 2) chk = 0;
	}

	int len = en.second - st.second;  // 변의 길이 계산
	if (mp[st.first][st.second + len / 2] == '.') cout << "UP";  // 색칠하지 않은 변이 위쪽일 때
	else if(mp[st.first + len / 2][st.second] == '.') cout << "LEFT";  // 색칠하지 않은 변이 왼쪽일 때
	else if(mp[en.first + len / 2][en.second] == '.') cout << "RIGHT";  // 색칠하지 않은 변이 오른쪽일 때
	else if(mp[st.first + len][st.second + len / 2] == '.') cout << "DOWN";  // 색칠하지 않은 변이 아래쪽일 때
}