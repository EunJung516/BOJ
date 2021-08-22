#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

int chk, alph[30];
string str, tmp, tmp2;
char ch;
stack<string> st;
stack<char> oper;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while (1) {
		getline(cin, str);
		if (str == "") break;

		chk = 0; tmp = "";
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '{') chk = 1;  // { 인 경우
			else if (chk) {
				if (str[i] == '}') {  // } 인 경우
					if (oper.size() && oper.top() == '*') {  // 이전 연산자가 * 인 경우
						memset(alph, 0, sizeof alph);
						tmp2 = st.top(); st.pop();
						for (int i = 0; i < tmp2.size(); ++i) alph[tmp2[i] - 'A'] = 1;
						for (int i = 0; i < tmp.size(); ++i) alph[tmp[i] - 'A'] += 1;
						tmp2 = "";
						for (int i = 0; i < 27; ++i) {
							if (alph[i] == 2) tmp2 += 'A' + i;  // 겹치는 경우
						}
						st.push(tmp2); oper.pop();
					}
					else st.push(tmp);   // 이전 연산자가 * 이 아닌 경우
					chk = 0; tmp = "";
				}
				else tmp += str[i];
			}
			else {
				if (str[i] == ')') {  // ) 인 경우
					memset(alph, 0, sizeof alph);
					while (oper.top() != '(') {  // ( 를 만날 때까지 반복
						ch = oper.top(); oper.pop();
						tmp2 = st.top(); st.pop();
						if (ch == '+') {  // + 인 경우
							for (int i = 0; i < tmp2.size(); ++i) {
								if (!alph[tmp2[i] - 'A']) alph[tmp2[i] - 'A'] = 1;
							}
						}
						else if (ch == '-') {  // - 인 경우
							for (int i = 0; i < tmp2.size(); ++i) {
								if (!alph[tmp2[i] - 'A']) alph[tmp2[i] - 'A'] = -1;
							}
						}
					}
					tmp2 = st.top(); st.pop();
					for (int i = 0; i < tmp2.size(); ++i) {  // 마지막 문자열 처리
						if (!alph[tmp2[i] - 'A']) alph[tmp2[i] - 'A'] = 1;
					}

					tmp2 = "";
					for (int i = 0; i < 27; ++i) {
						if (alph[i] == 1) tmp2 += 'A' + i;
					}
					st.push(tmp2); oper.pop();
				}
				else oper.push(str[i]);
			}
		}

		memset(alph, 0, sizeof alph);
		while (oper.size()) {
			ch = oper.top(); oper.pop();
			tmp = st.top(); st.pop();
			if (ch == '+') {  // + 인 경우
				for (int i = 0; i < tmp.size(); ++i) {
					if (!alph[tmp[i] - 'A']) alph[tmp[i] - 'A'] = 1;
				}
			}
			else if (ch == '-') {  // - 인 경우
				for (int i = 0; i < tmp.size(); ++i) {
					if (!alph[tmp[i] - 'A']) alph[tmp[i] - 'A'] = -1;
				}
			}
		}
		tmp = st.top(); st.pop();
		for (int i = 0; i < tmp.size(); ++i) {  // 마지막 문자열 처리
			if (!alph[tmp[i] - 'A']) alph[tmp[i] - 'A'] = 1;
		}
		cout << '{';
		for (int i = 0; i < 27; ++i) {
			if (alph[i] == 1) {
				ch = 'A' + i; cout << ch;
			}
		}
		cout << "}\n";
	}
}