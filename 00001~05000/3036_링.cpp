#include <iostream>
using namespace std;

int N, a, b, c, num[110];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> num[i];
	for (int i = 1; i < N; ++i) {
		a = num[0]; b = num[i]; c = a % b;
		while (c) {    // 유클리드 호제법을 활용한, 최대공약수 구하기
			a = b; b = c; c = a % b;
		}
		cout << num[0] / b << '/' << num[i] / b << '\n';
	}
}