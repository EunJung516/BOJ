#include <iostream>
using namespace std;

int n, k, a, an[100010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k; while (n--) {
		cin >> a; ++an[a];
		for (int i = 1; i <= k - a; ++i) an[i + a] = an[i + a] + an[i];
	}
	cout << an[k];
}