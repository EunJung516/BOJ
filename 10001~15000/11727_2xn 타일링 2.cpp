#include <iostream>
using namespace std;

int n, d[1010]{ 0,1,3, };

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n; 
	for (int i = 3; i <= n; ++i) d[i] = (d[i - 1] + 2 * d[i - 2]) % 10007;  // 피보나치 수열 활용
	cout << d[n];
}