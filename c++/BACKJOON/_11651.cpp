#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0;i < n;i++) {
		pair<int, int> imsi;
		cin >> imsi.second >> imsi.first;
		arr.push_back(imsi);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0;i < n;i++) {
		cout << arr[i].second << " " << arr[i].first << "\n";
	}

	return 0;
}
