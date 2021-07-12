#include <iostream>
using namespace std;

long long a, b, c;
long long ans[25][25][25], visited[25][25][25];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return ans[0][0][0];
	else if (a > 20 || b > 20 || c > 20) {
		if (visited[20][20][20]) return ans[20][20][20];    // w(20, 20, 20)를 이전에 계산 한 경우
		else {
			visited[20][20][20] = 1;
			return ans[20][20][20] = w(20, 20, 20);
		}
	}
	else if (a < b && b < c) {
		if (!visited[a][b][c - 1]) {    // w(a, b, c - 1)를 이전에 계산하지 않은 경우
			visited[a][b][c - 1] = 1;
			ans[a][b][c - 1] = w(a, b, c - 1);
		}
		if (!visited[a][b - 1][c - 1]) {    // w(a, b - 1, c - 1)를 이전에 계산하지 않은 경우
			visited[a][b - 1][c - 1] = 1;
			ans[a][b - 1][c - 1] = w(a, b - 1, c - 1);
		}
		if (!visited[a][b - 1][c]) {    // w(a, b - 1, c)를 이전에 계산하지 않은 경우
			visited[a][b - 1][c] = 1;
			ans[a][b - 1][c] = w(a, b - 1, c);
		}
		return ans[a][b][c - 1] + ans[a][b - 1][c - 1] - ans[a][b - 1][c];
	}
	else {
		if (!visited[a - 1][b][c]) {    // w(a - 1, b, c)를 이전에 계산하지 않은 경우
			visited[a - 1][b][c] = 1;
			ans[a - 1][b][c] = w(a - 1, b, c);
		}
		if (!visited[a - 1][b - 1][c]) {    // w(a - 1, b - 1, c)를 이전에 계산하지 않은 경우
			visited[a - 1][b - 1][c] = 1;
			ans[a - 1][b - 1][c] = w(a - 1, b - 1, c);
		}
		if (!visited[a - 1][b][c - 1]) {    // w(a - 1, b, c - 1)를 이전에 계산하지 않은 경우
			visited[a - 1][b][c - 1] = 1;
			ans[a - 1][b][c - 1] = w(a - 1, b, c - 1);
		}
		if (!visited[a - 1][b - 1][c - 1]) {    // w(a - 1, b - 1, c - 1)를 이전에 계산하지 않은 경우
			visited[a - 1][b - 1][c - 1] = 1;
			ans[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
		}
		return ans[a - 1][b][c] + ans[a - 1][b - 1][c] + ans[a - 1][b][c - 1] - ans[a - 1][b - 1][c - 1];
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ans[0][0][0] = visited[0][0][0] = 1;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
}