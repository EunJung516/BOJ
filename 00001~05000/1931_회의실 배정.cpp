#include <iostream>
#include <algorithm>
using namespace std;

int N, ans, endT;
pair<int, int> p[100010];    // first는 끝나는 시간, second는 시작 시간

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> p[i].second >> p[i].first;
	sort(p, p + N);    // 끝나는 시간 기준으로 정렬
	for (int i = 0; i < N; ++i) {
		if (endT <= p[i].second) {    // 시간이 겹치지 않은 경우
			endT = p[i].first; ++ans;
		}
	}
	cout << ans;    // 회의 최대 개수 출력
}