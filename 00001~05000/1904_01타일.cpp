#include <iostream>
using namespace std;

long long N, d[1000010]{ 0,1,2, };    // 동적 계획법 활용

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
    // 피보나치 수 활용
	for (int i = 3; i <= N; ++i) d[i] = (d[i - 1] + d[i - 2]) % 15746;
	cout << d[N];
}