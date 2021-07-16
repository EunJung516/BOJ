#include <iostream>
#include <algorithm>
using namespace std;

long long N, rgb[3][1010], d[3][1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
	for (int i = 0; i < 3; ++i) d[i][1] = rgb[i][1];    // 1번 집 비용 설정
	for (int i = 2; i <= N; ++i) {
        // 앞에 있는 집과 색깔을 다르게 하여 최소 비용을 저장
		d[0][i] = min(d[1][i - 1], d[2][i - 1]) + rgb[0][i];
		d[1][i] = min(d[0][i - 1], d[2][i - 1]) + rgb[1][i];
		d[2][i] = min(d[0][i - 1], d[1][i - 1]) + rgb[2][i];
	}
	cout << min(d[0][N], min(d[1][N], d[2][N]));
}