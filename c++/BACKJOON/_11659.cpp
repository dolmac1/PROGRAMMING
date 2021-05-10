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
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	vector<int> sum;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		arr.push_back(k);
		if (i == 0) {
			sum.push_back(k);
		}
		else {
			sum.push_back(k + sum[i - 1]);
		}
	}
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			cout << sum[b - 1] << "\n";
		}
		else {
			cout << sum[b - 1] - sum[a - 2] << "\n";
		}
	}
	return 0;
}
