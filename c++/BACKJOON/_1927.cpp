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
	priority_queue<int, vector<int>, greater<int>> number;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		if (k == 0) {
			if (number.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << number.top() << '\n';
				number.pop();
			}
		}
		else {
			number.push(k);
		}
	}
	return 0;
}
