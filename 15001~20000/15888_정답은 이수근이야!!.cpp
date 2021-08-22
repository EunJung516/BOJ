#include <iostream>
#include <cmath>
using namespace std;

int a, b, c, ans, sum, mul;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> a >> b >> c;
	if (b * b > 4 * a * c) {
		if (b % a || c % a) {  // 근이 정수가 아닌 경우
			cout << "둘다틀렸근"; return 0;
		}

		sum = -(b / a); mul = c / a;
		if (mul == 0) {  // 적어도 한 근이 0인 경우
			cout << "정수근"; return 0;
		}
		else if (mul < 0) {  // 한 근이 음수인 경우
			mul *= -1;
			for (int i = 1; i <= sqrt(mul); ++i) {
				if (!(mul % i)) {
					if (-i + mul / i == sum) {
						cout << "정수근"; return 0;
					}
					else if (i - mul / i == sum) {
						cout << "정수근"; return 0;
					}
				}
			}
			cout << "둘다틀렸근"; return 0;
		}
		else {
			for (int i = 1; i <= sqrt(mul); ++i) {
				if (!(mul % i)) {
					if (i + mul / i == sum) {  // 두 근이 모두 양수인 경우
						if (i == 1) {  // 한 근이 1인 경우
							cout << "정수근"; return 0;
						}

						ans = i;
						while (ans != 1) {
							if (ans % 2) {  // 2^K 로 표현되지 않는 경우
								cout << "정수근"; return 0;
							}
							ans /= 2;
						}

						ans = mul / i;
						while (ans != 1) {
							if (ans % 2) {  // 2^K 로 표현되지 않는 경우
								cout << "정수근"; return 0;
							}
							ans /= 2;
						}
						cout << "이수근"; return 0;  // 두 근 모두 2^K 로 표현되는 경우
					}
					else if (i + mul / i == -sum) {  // 두 근이 모두 음수인 경우
						cout << "정수근"; return 0;
					}
				}
			}
			cout << "둘다틀렸근"; return 0;  // 위 경우들를 모두 만족하지 않는 경우
		}
	}
	else cout << "둘다틀렸근";  // 허근 또는 중근인 경우
}