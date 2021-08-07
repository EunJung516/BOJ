#include <iostream>
#include <string>
using namespace std;

string str;
int st, chk, ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '+' || str[i] == '-') {    // 부호인 경우
			if(chk) ans -= stoi(str.substr(st, i - st));    // - 부호가 이전에 나타난 경우
			else ans += stoi(str.substr(st, i - st));    // - 부호가 이전에 나타나지 않은 경우
			st = i + 1;    // 시작점 갱신
			if (!chk && str[i] == '-') chk = true;    // - 부호가 처음 등장한 경우
		}
	}
	if(chk) ans -= stoi(str.substr(st));    // - 부호가 나타난 경우
	else ans += stoi(str.substr(st));    // - 부호가 나타나지 않은 경우

	cout << ans;    // 만들 수 있는 식의 최솟값 출력
}