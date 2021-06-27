#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> st; int K, num, sum = 0; cin >> K; while (K--) {
		cin >> num;
		if (num == 0) st.pop(); // 최근에 작성한 수 지우기
		else st.push(num);		// 수 저장
	}
	while (!st.empty()) {		// 적힌 수의 총합 구하기
		sum += st.top(); st.pop();
	}
	cout << sum;
}