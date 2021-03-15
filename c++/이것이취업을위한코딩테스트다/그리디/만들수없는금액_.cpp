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
	vector<int> money;
	int sum = 0;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		sum += k;
		money.push_back(k);
	}
	sort(money.begin(), money.end());
	int target = 1;
	for (int i = 0;i <= sum;i++) {
		if (target < money[i]) break;
		target += money[i];
	}
	cout << target << endl;
	return 0;
}
