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
	int n;
	cin >> n;
	vector<int> num_arr;
	int max_val = -1001;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		if (i == 0) {
			num_arr.push_back(k);
		}
		else {
			if (k > num_arr[i - 1] + k) {
				num_arr.push_back(k);
			}
			else {
				num_arr.push_back(num_arr[i - 1] + k);
			}
		}
		max_val = max(max_val, num_arr[i]);
	}
	cout << max_val << endl;
	return 0;
}
