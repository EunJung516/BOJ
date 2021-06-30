#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int T, N, M, K, X, Y, ans;
int field[60][60];
bool visited[60][60];
int dir4[2][4]{ {0, -1, 0, 1}, {1, 0, -1, 0} };

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T; while (T--) {
        cin >> M >> N >> K; ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                field[i][j] = 0;
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < K; ++i) {
            cin >> X >> Y; field[Y][X] = 1;
        }


        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (field[i][j] == 0) continue;    // 배추가 없는 경우라면, continue
                if (visited[i][j] == true) continue;    // 방문한 경우라면, continue
                ans += 1;

                queue<pii> que;
                que.push({ i,j });
                visited[i][j] = true;

                while (!que.empty()) {
                    int curRow = que.front().first, curCol = que.front().second;
                    for (int k = 0; k < 4; ++k) {    // 이동 가능한 위치(상하좌우)들을 검사
                        int nxtRow = curRow + dir4[0][k];
                        int nxtCol = curCol + dir4[1][k];

                        if (nxtRow < 0 || nxtCol < 0 || nxtRow >= N || nxtCol >= M) continue;   // 제시된 위치를 벗어난 경우, continue
                        else if (visited[nxtRow][nxtCol] == true) continue;    // 방문한 위치라면, continue
                        else if (field[nxtRow][nxtCol] == 0) continue;    // 배추가 없는 위치라면, continue
                        else {
                            visited[nxtRow][nxtCol] = true;
                            que.push({ nxtRow,nxtCol });
                        }
                    }
                    que.pop();
                }
            }
        }

        cout << ans << '\n';
    }
}