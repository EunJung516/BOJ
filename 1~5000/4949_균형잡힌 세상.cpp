#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	bool check; string str; getline(cin, str); while (str != ".") {
		check = true; stack<char> st;

		for (unsigned int i = 0; i < str.size(); i++) {
			if (str[i] == '(') st.push('(');					// '('인 경우
			else if (str[i] == ')') {							// ')'인 경우
				if (!st.empty() && st.top() == '(') st.pop();
				else {
					cout << "no" << endl; check = false; break;
				}
			}
			else if (str[i] == '[') st.push('[');				// '['인 경우
			else if (str[i] == ']') {							// ']'인 경우
				if (!st.empty() && st.top() == '[') st.pop();
				else {
					cout << "no" << endl; check = false; break;
				}
			}
		}
		if (check && !st.empty()) cout << "no" << endl;
		else if (check) cout << "yes" << endl;					// 균형을 이루고 있는 경우
		getline(cin, str);
	}
}