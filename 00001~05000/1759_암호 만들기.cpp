#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C, cntV, cntC;
string ans;
vector<char> c;

bool checkV(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;    // 모음인 경우
	else return false;    // 자음인 경우
}

void bt(int v) {
	if (v  == C) return;
	if (checkV(c[v])) ++cntV;    // 모음인 경우, cntV 증가
	else ++cntC;    // 자음인 경우, cntC 증가
	string tmp = ans;
	ans += c[v];    // c[v]를 추가시키기
	if (cntV + cntC == L && cntV > 0 && cntC > 1) cout << ans << '\n';    // 가능성 있는 암호인 경우 출력
	bt(v + 1);

	if (checkV(c[v])) --cntV;    // 모음인 경우, cntV 감소
	else --cntC;    // 자음인 경우, cntC 감소
	ans = tmp;    // 이전 ans를 ans에 저장
	bt(v + 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> L >> C; c.resize(C );
	for (int i = 0; i < C; ++i) cin >> c[i];
	sort(c.begin(), c.end()); bt(0);
}