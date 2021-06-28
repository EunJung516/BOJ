#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N, n, sum = 0, count = 0; vector<int> v, numbers; map<int, int> counts; cin >> N; while (N--) {
		cin >> n; v.push_back(n); sum += n;
		if (counts.find(n) != counts.end()) counts[n]++;    // counts에 존재하는 값이라면 해당 값의 count 수 늘려주기
		else counts[n] = 1;    // counts에 존재하지 않는 값이라면 값을 넣어주기
	}
	sort(v.begin(), v.end());

	map<int, int >::iterator iter;
	for (iter = counts.begin(); iter != counts.end(); iter++) {    // numbers에 최빈값 넣어주기
		if (count < iter->second) {
			numbers.clear();
			numbers.push_back(iter->first);
			count = iter->second;
		}
		else if (count == iter->second) numbers.push_back(iter->first);
	}

	cout << round(sum / (double)v.size()) << '\n'    // 산술평균
		<< v[v.size() / 2] << '\n'    //  중앙값
		<< (numbers.size() == 1 ? numbers[0] : numbers[1]) << '\n'    // 최빈값
		<< v.back() - v.front();    // 범위
}