#include <iostream>
using namespace std;

int N;
string ans, str;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N; cin >> ans; while (--N) {
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (ans[i] == '?') continue;    // ans[i]가 '?'인 경우
            else if (ans[i] != str[i]) ans[i] = '?';    // ans[i]와 str[i]가 다른 경우
        }
    }
    cout << ans;
}