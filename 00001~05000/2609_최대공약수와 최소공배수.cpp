#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int a, b, c; cin >> a >> b;
	c = min(a, b);
	while (a % c || b % c) --c;    // 최대공약수 구하기
	cout << c << '\n' << a * b / c;
}