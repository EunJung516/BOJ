#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> m;  // 아이디 별 번호 부여
int t, f, cnt, p[200001], an[200001];  // an : 속한 인원
string a, b;

// 그룹의 대표 번호 반환
int fd(int u) { return (p[u] == u ? u : p[u] = fd(p[u])); }

// u와 v가 각각 속한 그룹 merge
void mg(int u, int v) {
	int ut = fd(u), vt = fd(v);
	if (ut != vt) {  // 속한 그룹이 다르다면 merge
		// 더 적은 대표 번호로 merge하고, 속한 인원만큼 더해주기
		if (ut > vt) p[ut] = vt, an[vt] += an[ut];
		else p[vt] = ut, an[ut] += an[vt];
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t; while (t--) {
		fill(an, an + 200001, 1); m = {}; cnt = 0;  // 초기화
		cin >> f; while (f--) {
			cin >> a >> b;
			// 아이디가 없는 경우라면 아이디에 번호 부여
			if (!m[a]) m[a] = ++cnt, p[cnt] = cnt;
			if (!m[b]) m[b] = ++cnt, p[cnt] = cnt;
			mg(fd(m[a]), fd(m[b]));  // 각각의 그룹 merge
			// 그룹에 속한 인원 출력
			cout << an[fd(m[a])] << '\n'; 
		}
	}
}