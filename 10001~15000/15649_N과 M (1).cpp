#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ans;

void dfs(int idx, vector<int>& visited) {
    visited[idx] = 1;
    ans.push_back(idx + 1);
    if (ans.size() == M) {    // 수열의 크기가 M일 경우, 출력
        for (int i = 0; i < M; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        visited[idx] = 0;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            dfs(i, visited);
            visited[i] = 0;
            ans.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        vector<int> visited(N);    // 중복 확인하기 위한 벡터
        dfs(i, visited);
        ans.clear();
    }
}