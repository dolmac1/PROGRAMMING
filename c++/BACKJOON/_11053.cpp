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
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		num_arr.push_back(k);
	}
	vector<int> result_arr;
	result_arr.push_back(1);
	for (int i = 1;i < n;i++) {
		int max_result = 0;
		int max_loc = 0;
		for (int j = 0;j < i;j++) {
			if (num_arr[i] > num_arr[j]) {
				if (result_arr[j] > max_result) {
					max_result = result_arr[j];
					max_loc = j;
				}
			}
		}
		int push_val = max_result + 1;
		result_arr.push_back(push_val);
	}
	sort(result_arr.begin(), result_arr.end());

	cout << result_arr[n - 1] << endl;

	return 0;
}
