#include <iostream>
#include <stack>
using namespace std;

int N, M, chk;
string str;
stack<char> st;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; while (N--) {
		cin >> M >> str; chk = 1;
		for (int i = 0; i < M; ++i) {
			if (str[i] == '>') st.push('>');  // > 인 경우
			else {  // < 인 경우
				if (st.size()) st.pop();  // 스택에 > 이 존재하는 경우
				else {  // 스택에 > 이 존재하지 않은 경우
					cout << "illegal\n";
					chk = 0; break;
				}
			}
		}
		if (st.size()) {  // 스택에 > 이 남아있는 경우
			cout << "illegal\n";
			while (st.size()) st.pop();
		}
		else if (chk) cout << "legal\n";
	}
}