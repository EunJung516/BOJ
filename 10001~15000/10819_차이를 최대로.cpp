#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A, ans, sum;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N; vector<int> idxs(N), numbers(N); 
    for (int i = 0; i < N; i++) {
        cin >> A; idxs[i] = i; numbers[i] = A;
    }

    do { // 가능한 인덱스들의 모든 순서에 대해서 계산
        sum = 0;
        for (int i = 0; i < N - 1; i++) {
            if (numbers[idxs[i]] > numbers[idxs[i + 1]]) sum += numbers[idxs[i]] - numbers[idxs[i + 1]];
            else sum += numbers[idxs[i + 1]] - numbers[idxs[i]];
        }
        if (ans < sum)ans = sum;
    } while (next_permutation(idxs.begin(), idxs.end()));
    cout << ans;
}