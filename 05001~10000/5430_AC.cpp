#include <iostream>
#include <queue>
using namespace std;

int T, n;
string p, x;
bool chkR, chkError;
deque<int> dq;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T; while (T--) {
        dq.clear();
        cin >> p >> n >> x; chkR = chkError = true;
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] != '[' && x[i] != ']' && x[i] != ',') {
                if (x[i - 1] == '[' || x[i - 1] == ',') dq.push_back(x[i] - '0');
                else dq.back() = dq.back() * 10 + (x[i] - '0');
            }
        }
        for (auto& nxt : p) {
            if (nxt == 'R') chkR = !chkR;    // 함수 R
            else {    // 함수 D
                if(dq.empty()) {
                    cout << "error\n";
                    chkError = false;
                    break;
                }
                if (chkR) dq.pop_front();    // 뒤집어지지 않은 경우
                else dq.pop_back();    // 뒤집어진 경우
            }
        }

        if (chkError) {
            cout << '[';
            if (dq.empty());
            else if (chkR) {    // 뒤집어지지 않은 경우
                cout << dq.front(); dq.pop_front();
                while (!dq.empty()) {
                    cout << ',' << dq.front();
                    dq.pop_front();
                }
            }
            else {    // 뒤집어진 경우
                cout << dq.back(); dq.pop_back();
                while (!dq.empty()) {
                    cout << ',' << dq.back();
                    dq.pop_back();
                }
            }
            cout << "]\n";
        }
    }
}