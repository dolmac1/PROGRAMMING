#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> big;
	priority_queue<int, vector<int>, less<int>> small;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		if (small.empty()) {
			small.push(k);
		}
		else if (big.size() == small.size()) {
			small.push(k);
		}
		else {
			big.push(k);
		}
		if (!big.empty() && !small.empty() && !(small.top() <= big.top())) {
			int a = small.top();
			int b = big.top();
			small.pop();
			big.pop();
			big.push(a);
			small.push(b);
		}
		cout << small.top() << '\n';

	}
	return 0;
}
