#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

int N, num[110], a, b, c;
map<int, int> mp;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> num[i];
	sort(num, num + N);
	for (int i = 1; i < N; ++i) num[i - 1] = num[i] - num[i - 1];    // 앞 원소와 뒤 원소의 차이 저장
	for (int i = 1; i < N - 1; ++i) {    // (N - 2)번 반복
		for (int j = 1; j < N - i; ++j) {
			a = num[j]; b = num[j - 1]; c = a % b;
			while (c) {
				a = b; b = c; c = a % b;
			}
			num[j - 1] = b;    // 앞 원소와 뒤 원소의 최대공약수 저장
		}
	}

	mp[num[0]] = 1;    // 최종적인 최대공약수 저장
	for (int i = 2; i <= sqrt(num[0]); ++i) {    // 최대공약수의 약수 저장
		if (!(num[0] % i)) {
			mp[i] = 1; mp[num[0] / i] = 1;
		}
	}
	for (auto& i : mp) cout << i.first << ' ';    // 가능한 M 모두 출력
}