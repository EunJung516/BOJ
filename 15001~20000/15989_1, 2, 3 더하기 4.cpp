#include <iostream>
#include <vector>
using namespace std;

int T, n;
int d[10001]{ 1, };

int main() {
	cin >> T;
    // 1, 2, 3의 합으로 나타내는 방법의 수 구하기
	for (int i = 1; i <= 3; ++i) {
		for (int j = i; j <= 10000; ++j) {
			d[j] += d[j - i];
		}
	}
	while (T--) {
		cin >> n;
		cout << d[n] << '\n';
	}
}