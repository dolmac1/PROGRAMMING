// 숫자카드2 s4
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
	int n,m;
	vector<int> input_vec, result_vec;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		input_vec.push_back(a);
	}
	sort(input_vec.begin(), input_vec.end());
	cin >> m;
	for (int i = 0;i < m;i++) {
		int a;
		cin >> a;
		int result = upper_bound(input_vec.begin(), input_vec.end(), a) - lower_bound(input_vec.begin(), input_vec.end(), a);
		result_vec.push_back(result);
	}
	for (int i = 0;i < result_vec.size();i++) {
		cout << result_vec[i] << " ";
	}

	return 0;
}
