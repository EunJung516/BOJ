#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M, power;
string name;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map<int, string> names;    // 전투력과 해당 칭호 저장
    vector<int> powers;    // 전투력 저장
    for (int i = 0; i < N; i++) {
        cin >> name >> power;
        if (names.find(power) == names.end()) names[power] = name;    // 저장되지 않은 전투력일 경우 저장
        powers.push_back(power);
    }
    sort(powers.begin(), powers.end());
    powers.erase(unique(powers.begin(), powers.end()), powers.end());    // powers에서 중복되는 전투력 제거

    int size = powers.size();
    while (M--) {    // power에 해당되는 칭호 출력
        cin >> power;
        int st = 0, end = size - 1, mid;

        while (st <= end) {
            mid = (st + end) / 2;
            if (mid == 0) {
                if (powers[0] >= power) {
                    cout << names[powers[mid]] << '\n';
                    break;
                }
                else st = mid + 1;
            }
            else if ((powers[mid - 1] < power && powers[mid] >= power)) {
                cout << names[powers[mid]] << '\n';
                break;
            }
            else if (powers[mid] < power) st = mid + 1;
            else end = mid - 1;
        }
    }
}