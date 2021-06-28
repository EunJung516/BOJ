#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, X; string str; queue<int> q; cin >> N; while (N--) {
		cin >> str;
		if (str == "push") {    // push X
			cin >> X; q.push(X);
		}
		else if (str == "pop") {    // pop
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (str == "size") {    // size
			cout << q.size() << endl;
		}
		else if (str == "empty") {    // empty
			cout << q.empty() << endl;
		}
		else if (str == "front") {    // front
			if (q.empty()) cout << -1 << endl;
			else cout << q.front() << endl;
		}
		else {    // back
			if (q.empty()) cout << -1 << endl;
			else cout << q.back() << endl;
		}
	}
}