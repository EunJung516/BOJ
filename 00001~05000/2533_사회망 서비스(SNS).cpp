#include <iostream>
#include <vector>
using namespace std;

int N, u, v, ans;
int d[1000001];
vector<vector<int>> edges;

void solution(int prevIdx, int idx) {
	if (prevIdx != 0 && edges[idx].size() == 1) {    
        // 친구가 prevIdx밖에 없고 prevIdx가 얼리 아답터 아닌 경우, prevIdx를 얼리 아답터로 설정
		if (d[prevIdx] == 0) {
			++ans;
			d[prevIdx] = 1;
		}
		return;
	}

	int cnt = 0;
	for (int i = 0; i < edges[idx].size(); ++i) {
		if (edges[idx][i] == prevIdx) continue;    // prevIdx인 경우, continue
		solution(idx, edges[idx][i]);
		if (d[edges[idx][i]] == 1) ++cnt;   // 친구가 얼리 아답터라면 cnt 증가
	}
	if (prevIdx == 0 && cnt != edges[idx].size() && d[idx] == 0) {    // 모든 친구가 얼리 아답터가 아닌 경우
		++ans;
		d[idx] = 1;
	}
	else if (prevIdx != 0 && cnt != edges[idx].size() - 1 && d[idx] == 0) {    // prevIdx 제외한 모든 친구가 얼리 아답터가 아닌 경우
		++ans;
		d[idx] = 1;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; edges = vector<vector<int>>(N + 1, vector<int>());
	while (--N) {    // 에지 저장
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}	
	solution(0, 1);
	cout << ans;
}