#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int A, B, C, tmp1, tmp2, T; cin >> T; while (T--) {
		cin >> A >> B;
		tmp1 = max(A, B), tmp2 = min(A, B);
		do {     // 유클리드 호제법으로 최대공약수 구하기
			C = tmp1 % tmp2;
			tmp1 = tmp2; tmp2 = C;
		} while (C);
		C = tmp1;
		cout << A * B / C << '\n';
	}
}