#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int N, cnt;
string str, tmp;
map<string, int> mp;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; cnt = pow(2, N);
	cin >> str; cout << str << '\n'; mp[str] = 1; --cnt;
	while (cnt) {  // 모든 경우를 다룰 때까지
		for (int i = 0; i < N; ++i) str[i] = (str[i] == '0' ? '1' : '0');  // 모든 바리에이션 전환
		if (!mp[str]) {  // 전환된 경우를 아직 다루지 않은 경우
			--cnt;
			cout << str << '\n'; mp[str] = 1; continue;
		}

		for (int i = N - 1; i >= 0; --i) {  // 한 곳씩 바리에이션 전환
			tmp = str; tmp[i] = (tmp[i] == '0' ? '1' : '0');
			if (!mp[tmp]) {  // 전환된 경우를 아직 다루지 않은 경우
				--cnt;
				cout << tmp << '\n'; mp[tmp] = 1; str = tmp; break;
			}
		}
	}
}