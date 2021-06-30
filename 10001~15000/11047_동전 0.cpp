#include <iostream>
#include <vector>
using namespace std;

int N, K, A, cnt, ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K; vector<int> coins; while (N--) {
        cin >> A; coins.push_back(A);
    }
    for (int i = coins.size() - 1; i >= 0; i--) {
        if (coins[i] > K) continue;    // 동전의 가치가 현재 K 값보다 크다면 continue
        cnt = K / coins[i]; ans += cnt;
        K -= cnt * coins[i];
        if (K == 0) {
            cout << ans; return 0;    // 가치의 합이 K가 된 경우, 개수를 출력하고 종료
        }
    }
}