//나이순 정렬 s5

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
		return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	pair<int, string> input_val;
	vector<pair<int, string>> vec;
	for (int i = 0;i < n;i++) {
		cin >> input_val.first >> input_val.second;
		vec.push_back(input_val);
	}
	stable_sort(vec.begin(), vec.end(), cmp);
	for (int i = 0;i < n;i++) {
		cout << vec[i].first << " " << vec[i].second << '\n';
	}

	return 0;
}
