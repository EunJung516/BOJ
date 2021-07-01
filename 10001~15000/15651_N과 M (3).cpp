#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ans;

void dfs(int idx) {
    ans.push_back(idx + 1);
    if (ans.size() == M) {    // 수열의 크기가 M일 경우, 출력
        for (int i = 0; i < M; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        dfs(i);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        dfs(i);
        ans.clear();
    }
}