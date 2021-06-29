#include <iostream>
#include <vector>
#include <map>
using namespace std;

int T, N, K, X, Y, W, D;

void solution(map<int,int>& buildings, map<int, bool>& check, vector<vector<int>>& subBuild, int W) {
    if (subBuild[W - 1].size() == 0 || check[W]) return;

    check[W] = true;    // 건설시간 계산된 빌딩임을 나타내도록 확인
    for (int i = 0; i < subBuild[W - 1].size(); i++) {    // 건설하기 전에 건설해야 할 건물의 건설시간 계산
        solution(buildings, check, subBuild, subBuild[W - 1][i]);
    }

    // 건설하기 전에 건설해야 할 건물들 중 최대 건설시간을 해당 건설시간에 추가
    int max = buildings[subBuild[W - 1][0]];
    for (int i = 0; i < subBuild[W - 1].size(); i++) {
        if (max < buildings[subBuild[W - 1][i]]) max = buildings[subBuild[W - 1][i]];
    }
    buildings[W] += max;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T; while (T--) {
        cin >> N >> K; 
        map<int, int> buildings;    // 건설시간 저장
        map<int, bool> check;    // 해당 건물의 총 건설시간을 계산했는지 확인
        vector<vector<int>> subBuild(N);    // 건설하기 전에 건설해야 할 건물들을 저장
        for (int i = 1; i <= N; i++) {
            cin >> D; buildings[i] = D; check[i] = false;
        }
        while (K--) {
            cin >> X >> Y; subBuild[Y-1].push_back(X);
        }
        cin >> W;
        solution(buildings, check, subBuild, W);
        cout << buildings[W] << endl;
    }
}