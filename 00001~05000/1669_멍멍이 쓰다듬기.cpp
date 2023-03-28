#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	long long x, y; cin >> x >> y; y -= x;  // 입력 후 y에 키 차이 저장
	if (y == 0) { cout << 0; return 0; }  // 같을 경우 0을 반환
	for (int i = 1;; ++i) {  // 차례대로 키 키우기
		for (int j = 2; j > 0; --j) {
			// 첫날과 마지막날은 1만큼만 클 수 있으므로
			// 앞과 뒤, 총 이틀을 확인
			y -= i; if (y <= 0) { cout << 2 * i - j + 1; return 0; }  // 쓰다듬을 수 있는 경우
		}
	}
}