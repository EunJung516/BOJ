#include <iostream>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	// 4로 나누고 그 만큼 long 출력 후 int 한 번 출력
	cin >> n; n /= 4; for (int i = 0; i < n; ++i) cout << "long "; cout << "int";
}