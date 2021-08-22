#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	long long T, A, B; cin >> T;
	for (long long i = 1; i <= T; ++i) {
		cin >> A >> B; cout << "Case #" << i << ": " << A + B << '\n';  // A + B 출력
	}
}