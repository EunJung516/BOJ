#include <iostream>
using namespace std;
typedef long long ll;

ll N, tmp, cnt5, cnt2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	cnt5 = N / 5; cnt2 = N / 2;
	while (cnt5) {    // 5로 몇 번 나누어지는지 구하기
		tmp += cnt5; cnt5 /= 5;
	} cnt5 = tmp;
	tmp = 0;
	while (cnt2) {    // 2로 몇 번 나누어지는지 구하기
		tmp += cnt2; cnt2 /= 5;
	} cnt2 = tmp;
	cout << (cnt5 < cnt2 ? cnt5 : cnt2);    // 뒤에 있는 0의 개수 출력
}