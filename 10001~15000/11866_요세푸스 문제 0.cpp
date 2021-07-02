#include <iostream>
#include <queue>
using namespace std;

int N, K, tmp;
queue<int> num;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) num.push(i);
    cout << '<';
    while (num.size() != 1) {    // 한 명 남을 때까지 반복
        tmp = K;
        while (--tmp) {    // K - 1번 반복
            num.push(num.front());
            num.pop();
        }
        cout << num.front() << ", ";    // 제거된 K번째 사람 번호 출력
        num.pop();
    }
    cout << num.front() << '>';
}