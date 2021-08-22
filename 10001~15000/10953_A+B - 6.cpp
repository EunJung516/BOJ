#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; string str; cin >> T; while (T--) {
		cin >> str; cout << str[0] - '0' + str[2] - '0' << '\n';  //  A + B 출력
	}
}