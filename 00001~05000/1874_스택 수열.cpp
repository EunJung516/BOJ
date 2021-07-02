#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, n, num = 1;
string ans;
vector<int> v;
stack<int> sub;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n; v.push_back(n);
    }

    for (int i = 0; i < N; i++) {
        while (1) {
            if (!sub.empty() && v[i] == sub.top()) {
                ans += "-\n";
                sub.pop();
                break;
            }
            else {
                if (num > N) {
                    // sub에 N보다 큰 숫자를 넣으려고 하는 경우는 불가능한 경우이므로
                    // NO를 출력하고 종료
                    cout << "NO"; return 0;
                }
                sub.push(num);
                ans += "+\n";
                ++num;
            }
        }
    }
    cout << ans;
}