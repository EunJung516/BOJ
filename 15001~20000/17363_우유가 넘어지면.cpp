#include <iostream>
#include <vector>
using namespace std;

int N, M;
char n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M; vector<vector<char>> strings(M, vector<char>(N));
    for (int i = 0; i < N; i++) {    // 돌려진 문자 저장
        for (int j = 0; j < M; j++) {
            cin >> n;
            if (n == '.') strings[j][i] = '.';
            else if (n == 'O') strings[j][i] = 'O';
            else if (n == '-') strings[j][i] = '|';
            else if (n == '|') strings[j][i] = '-';
            else if (n == '/') strings[j][i] = '\\';
            else if (n == '\\') strings[j][i] = '/';
            else if (n == '^') strings[j][i] = '<';
            else if (n == '<') strings[j][i] = 'v';
            else if (n == 'v') strings[j][i] = '>';
            else if (n == '>') strings[j][i] = '^';
        }
    }

    for (int i = M - 1; i >= 0; i--) {    // 왼쪽으로 넘어뜨렸을 때의 결과 출력
        for (int j = 0; j < N; j++) {
            cout << strings[i][j];
        }
        cout << '\n';
    }
}