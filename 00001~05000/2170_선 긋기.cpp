#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, x, y, last, length, tmp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    vector<vector<int>> lines(N, vector<int>(2));
    for (int i = 0; i < N; i++)
        cin >> lines[i][0] >> lines[i][1];
    sort(lines.begin(), lines.end());

    last = lines[0][1];    // 선의 도착점
    for (int i = 1; i < N; i++) {
        if (lines[i][0] <= last) {
            // 선이 겹치고, 도착점의 위치가 기존 도착점의 위치보다 클 경우, 기존 도착점을 변경
            if(lines[i][1] > last) last = lines[i][1];
        }
        else {
            length += last - lines[tmp][0];    // 총 길이에 선의 길이 추가
            tmp = i;    // 새로운 선의 시작점의 인덱스 설정
            last = lines[tmp][1];    // 새로운 선의 도착점 설정
        }
    }
    cout << length + last - lines[tmp][0];
}