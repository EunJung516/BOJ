#include <iostream>
using namespace std;

int main() {
	string A, B; cin >> A >> B;
	for (int i = 0; i < 100000; i++) {    // A & B
		if (A[i] == '1' && B[i] == '1') cout << 1;
		else cout << 0;
	}
	cout << endl;

	for (int i = 0; i < 100000; i++) {    // A | B
		if (A[i] == '0' && B[i] == '0') cout << 0;
		else cout << 1;
	}
	cout << endl;

	for (int i = 0; i < 100000; i++) {    // A ^ B
		if ((A[i] == '1' && B[i] == '0') || (A[i] == '0' && B[i] == '1')) cout << 1;
		else cout << 0;
	}
	cout << endl;

	for (int i = 0; i < 100000; i++) {    // ~A
		if (A[i] == '1') cout << 0;
		else cout << 1;
	}
	cout << endl;

	for (int i = 0; i < 100000; i++) {    // ~B
		if (B[i] == '1') cout << 0;
		else cout << 1;
	}
}