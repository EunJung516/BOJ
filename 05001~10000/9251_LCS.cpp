#include <iostream>
#include <algorithm>
using namespace std;

string s1, s2;
int idx1, idx2, d[1010][1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			if (s1[i] == s2[j]) d[j + 1][i + 1] = d[j][i] + 1;    // 글자가 같은 경우
			else d[j + 1][i + 1] = max(d[j + 1][i], d[j][i + 1]);
		}
	}
	cout << d[s2.size()][s1.size()];    // 최종 LCS의 길이 출력
}