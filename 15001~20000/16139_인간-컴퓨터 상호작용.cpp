#include <iostream>
using namespace std;

string S;
char ch;
int q, a, l, r, s[30][200010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> S >> q;
	for (int i = 0; i < S.size(); ++i) {
		++s[S[i] - 'a'][i + 1];
		for (int j = 0; j <= 25; ++j) s[j][i + 1] += s[j][i];  // 누적합 계산
	}
	while (q--) {
		cin >> ch >> l >> r; cout << s[ch - 'a'][r + 1] - s[ch - 'a'][l] << '\n';
	}
}