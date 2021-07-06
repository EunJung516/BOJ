#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, W, V;
int d[100010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(d, -1, sizeof d);
	cin >> N >> K;
	d[0] = 0;
	for (int i = 0; i < N; ++i) {
		cin >> W >> V;
		for (int j = K; j >= W; --j)    // 이전 경우에서 더 큰 가치를 도출할 수 있는지 확인
			if (d[j - W] != -1) d[j] = max(d[j - W] + V, d[j]);
	}
	cout << *max_element(d, d + K + 1);
}