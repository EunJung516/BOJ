#include <iostream>
#include <stack>
using namespace std;

int N;
int A[1000010];
stack<int> st;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
        while (!st.empty() && A[st.top()] < A[i]) {    // A[i]가 오큰수인 경우에 A[i] 저장
            A[st.top()] = A[i];
            st.pop();
        }
		st.push(i);
	}
	while (!st.empty()) {    // 오큰수가 없는 경우에는 -1 저장
		A[st.top()] = -1;
		st.pop();
	}
	for (int i = 0; i < N; ++i)
		cout << A[i] << ' ';
}