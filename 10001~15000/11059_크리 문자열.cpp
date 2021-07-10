#include <iostream>
using namespace std;

string str;
int ans, mid;
int num[1010], sum[1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {    // 누적 합 계산
		num[i + 1] = str[i] - '0'; sum[i + 1] = num[i + 1] + sum[i];
	}
	if (str.size() % 2) ans = str.size() - 1;    // 문자열 크기가 홀수인 경우
	else ans = str.size();    // 문자열 크기가 짝수인 경우
	while (ans) {
		mid = ans / 2;
		for (int i = 1; i + ans - 1 <= str.size(); ++i) {
			if ((sum[i + mid - 1] - sum[i - 1]) == (sum[i + ans - 1] - sum[i + mid - 1])) {    // 크리 문자열인 경우
				cout << ans; return 0;
			}
		}
		ans -= 2;
	}
}