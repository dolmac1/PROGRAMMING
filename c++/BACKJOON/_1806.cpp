#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s;
	int answer = 99999999;
	cin >> n >> s;
	vector<int> num_arr;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		num_arr.push_back(k);
	}
	int pre_idx = 0;
	int post_idx = 0;
	int sum = num_arr[0];
	while (post_idx < n && pre_idx <= post_idx) {
		if (sum == s) {
			int length = post_idx - pre_idx + 1;
			if (length == 1) {
				answer = 1;
				break;
			}
			if (answer > length) {
				answer = length;
			}
			post_idx++;
			sum += num_arr[post_idx];
		}
		else if (sum > s) {
			int length = post_idx - pre_idx + 1;
			if (length == 1) {
				answer = 1;
				break;
			}
			if (answer > length) {
				answer = length;
			}
			sum -= num_arr[pre_idx];
			pre_idx++;
			if (pre_idx > post_idx && pre_idx < n) {
				post_idx = pre_idx;
				sum = num_arr[post_idx];
			}
		}
		else {
			post_idx++;
			if (post_idx >= n) {
				break;
			}
			sum += num_arr[post_idx];
		}
	}
	if (answer == 99999999) {
		cout << 0 << endl;
	}
	else {
		cout << answer << endl;
	}
	return 0;
}
