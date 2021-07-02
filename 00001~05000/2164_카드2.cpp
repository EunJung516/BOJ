#include <iostream>
#include <queue>
using namespace std;

int N;
bool check = true;
queue<int> cards;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cards.push(i);
    while (cards.size() != 1) {    // 카드가 한 장 남을 때까지 반복
        if (check) {    // 홀수 번째 시행은, 제일 위에 있는 카드를 바닥에 버리기
            check = false;
            cards.pop();
        }
        else {    // 짝수 번째 시행은, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮기기
            check = true;
            cards.push(cards.front());
            cards.pop();
        }
    }
    cout << cards.front();
}