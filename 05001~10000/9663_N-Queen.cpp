#include <iostream>
#include <vector>
using namespace std;

int N, ans;
bool check;
vector<int> v;

void bt(int N) {
	if (v.size() == N) {    // N개의 퀸을 놓은 경우 ans 증가
		ans++;
		return;
	}
	for (int i = 0; i < N; ++i) {
		v.push_back(i);
		check = true;
		for (int j = 0; j < v.size() - 1; j++) {
			if (v[j] == v.back()) {    // 같은 열에 퀸이 존재하는 경우
				check = false; break;
			}
			if (abs(v[j] - v.back()) == abs((int)(j - (v.size() - 1)))) {    // 대각선에 퀸이 존재하는 경우
				check = false; break;
			}
		}
		if (check) bt(N);    // 배치 가능한 경우
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	bt(N);
	cout << ans;
}