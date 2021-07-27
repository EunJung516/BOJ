#include <iostream>
using namespace std;

int N;
char par, l, r, ch;
int adj[30][2];

void preorder(int idx) {    // 전위 순회
	ch = 'A' + idx; cout << ch;
	if (adj[idx][0]) preorder(adj[idx][0]);
	if (adj[idx][1]) preorder(adj[idx][1]);
}

void inorder(int idx) {    // 중위 순회
	if (adj[idx][0]) inorder(adj[idx][0]);
	ch = 'A' + idx; cout << ch;
	if (adj[idx][1]) inorder(adj[idx][1]);
}

void postorder(int idx) {    // 후위 순회
	if (adj[idx][0]) postorder(adj[idx][0]);
	if (adj[idx][1]) postorder(adj[idx][1]);
	ch = 'A' + idx; cout << ch;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; while (N--) {
		cin >> par >> l >> r;
		if (l != '.') adj[par - 'A'][0] = l - 'A';    // 왼쪽 자식 노드가 있는 경우
		if (r != '.') adj[par - 'A'][1] = r - 'A';    // 오른쪽 자식 노드가 있는 경우
	}
	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0);
}