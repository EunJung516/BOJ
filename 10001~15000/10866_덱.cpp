#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, X; string str; deque<int> dq; cin >> N; while (N--) {
		cin >> str;
		if (str == "push_front") {    // push_front X
			cin >> X; dq.push_front(X);
		}
		else if (str == "push_back") {    // push_back X
			cin >> X; dq.push_back(X);
		}
		else if (str == "pop_front") {    // pop_front
			if (dq.empty()) cout << -1 << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {    // pop_back
			if (dq.empty()) cout << -1 << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (str == "size") {    // size
			cout << dq.size() << endl;
		}
		else if (str == "empty") {    // empty
			cout << dq.empty() << endl;
		}
		else if (str == "front") {    // front
			if (dq.empty()) cout << -1 << endl;
			else cout << dq.front() << endl;
		}
		else {    // back
			if (dq.empty()) cout << -1 << endl;
			else cout << dq.back() << endl;
		}
	}
}