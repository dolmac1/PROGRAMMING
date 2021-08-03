#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> money;
	int result = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		int money_val;
		cin >> money_val;
		money.push(money_val);
	}

	while (!money.empty()) {
		int mon = money.top();
		money.pop();
		int money_count = k / mon;
		result += money_count;
		k = k - (mon * money_count);
	}
	cout << result << endl;

	return 0;
}
