#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N; vector<int> v(N);
	for (auto& i : v) cin >> i;
	sort(v.begin(), v.end());
	cout << v[0] * v[N - 1];    // N은 진짜 약수의 최솟값과 최댓값의 곱
}