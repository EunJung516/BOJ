#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, x, y, an = 1010, mp[1010][1010], s[1010][1010];
vector<int> X, Y;
vector<pair<int, int>> tmp;
map<int, int> idxX, idxY;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> x >> y; X.push_back(x); Y.push_back(y); tmp.push_back({ y, x });
	}
	sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());

	for (int i = 0; i < X.size(); ++i) idxX[X[i]] = i + 1;  // x축 인덱스 설정
	for (int i = 0; i < Y.size(); ++i) idxY[Y[i]] = i + 1;  // y축 인덱스 설정

	for (auto& i : tmp) mp[idxY[i.first]][idxX[i.second]] = 1;
	for (int i = 1; i <= Y.size(); ++i) {
		for (int j = 1; j <= X.size(); ++j) {
			s[i][j] = mp[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];  // 누적합 계산
		}
	}
	for (int i = 1; i <= Y.size(); ++i) {
		for (int j = 1; j <= X.size(); ++j) {
			int s1 = s[i][j], s2 = s[i][X.size()] - s1, s3 = s[Y.size()][j] - s1, s4 = s[Y.size()][X.size()] - s1 - s2 - s3;
			an = min(an, max(s1, max(s2, max(s3, s4))));  // an 갱신
		}
	}
	cout << an;
}