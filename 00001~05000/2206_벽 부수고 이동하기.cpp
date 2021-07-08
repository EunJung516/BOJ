#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int, int>;

int ROW, COL;
char field[1010][1010];
bool visited[1010][1010], abnormal[1010][1010];    // 일반적인 방문된 경우, 벽 부수고 이동해서 방문된 경우
int dir4[2][4]{ {-1,1,0,0},{0,0,-1,1} };

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> ROW >> COL;
    for (int i = 1; i <= ROW; ++i) {
        for (int j = 1; j <= COL; ++j) {
            cin >> field[i][j];
        }
    }

    queue<tup> que;
    que.push({ 1,1,1,1 });
    visited[1][1] = true;

    while (!que.empty()) {
        tup cur = que.front(); que.pop();

        int cur_row = get<0>(cur), cur_col = get<1>(cur), cur_dist = get<2>(cur), check = get<3>(cur);

        if (cur_row == ROW && cur_col == COL) {
            cout << cur_dist;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nxt_row = cur_row + dir4[0][i], nxt_col = cur_col + dir4[1][i];

            if (nxt_row < 1 || nxt_col < 1 || nxt_row > ROW || nxt_col > COL) continue;
            if (field[nxt_row][nxt_col] == '1') {    // 벽인 경우
                if (check && !abnormal[nxt_row][nxt_col]) {    // 아직 벽을 부수지 않았고, 벽 부셔서 방문되지 않은 경우
                    abnormal[nxt_row][nxt_col] = true;
                    que.push({ nxt_row,nxt_col,cur_dist + 1,0 });
                    continue;
                }
                else continue;
            }
            if ((!check && abnormal[nxt_row][nxt_col]) || (check && visited[nxt_row][nxt_col] == true)) continue;

            if (check) {    // 벽을 부수지 않은 경우
                visited[nxt_row][nxt_col] = true;
                que.push({ nxt_row,nxt_col,cur_dist + 1,check });
            }
            else {    // 벽을 부순 경우
                abnormal[nxt_row][nxt_col] = true;
                que.push({ nxt_row,nxt_col,cur_dist + 1,check });
            }
        }
    }
    cout << -1;
}