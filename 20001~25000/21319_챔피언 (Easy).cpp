#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, st, en, mid, ans = 200010, power, idx;
vector<long long> idxs;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		if (!i) idxs.push_back(0);    // 첫 번째 선수인 경우
		else if (v[i - 1] != v[i]) idxs.push_back(i);    // 앞 선수와 전투력이 다른 경우
	}

	st = 0, en = idxs.size() - 1;
	while (st <= en) {
		mid = (st + en) / 2; 
        power = v[idxs[mid]] + idxs[mid];    // 자신의 전투력과 앞에 있는 선수들을 이겨서 얻은 전투력의 합
		idx = idxs[mid] + 1;
		while (idx < N) {
			if (power > v[idx]) {
				++power; ++idx;
			}
			else break;
		}
		if (idx == N) {    // 챔피언이 될 수 있는 경우
			en = mid - 1;
			ans = min(ans, mid);
		}
		else st = mid + 1;
	}
	
	if (ans == 200010) cout << -1;    // 아무도 챔피언이 될 수 없는 경우
	else {
		for (int i = ans; i < idxs.size(); ++i) cout << idxs[i] + 1 << ' ';
	}
}