#include <iostream>
#include <string>
using namespace std;

string S, A[110];
int N, d[110];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> S >> N; for (int i = 0; i < N; ++i) cin >> A[i];
	d[0] = 1;
	for (int i = 0; i < S.size(); ++i) {
		if (!d[i]) continue;  // 문자의 시작이 될 수 없는 경우
		for (int j = 0; j < N; ++j) {
			if (A[j] == S.substr(i, A[j].size())) d[i + A[j].size()] = 1;  // 문자의 시작이 될 수 있음을 저장
		}
	}
	cout << d[S.size()];
}