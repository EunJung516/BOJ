#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int a, b; while (cin >> a >> b) {
		if (!a && !b) break;
		if (b % a == 0) cout << "factor\n";    // 첫 번째 숫자가 두 번째 숫자의 약수인 경우
		else if (a % b == 0) cout << "multiple\n";    // 첫 번째 숫자가 두 번째 숫자의 배수인 경우
		else cout << "neither\n";
	}
}