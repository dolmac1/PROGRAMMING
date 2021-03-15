#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector<int> stats;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		stats.push_back(k);
	}
	sort(stats.begin(), stats.end());
	int result = 0;
	int count = 0;
	for (int i = 0;i < stats.size();i++) {
		count += 1;
		if (count == stats[i]) {
			result++;
			count = 0;
		}
		
	}
	cout << result << endl;
	return 0;
}
