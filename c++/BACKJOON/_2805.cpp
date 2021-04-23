#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int binary_search(vector<int> x, int y) {
	int begin = 0;
	int end = 1000000000;
	int result = -1;
	while (begin<=end) {
		int mid = (begin + end) / 2;
		long long add_len = 0;
		for (int i = 0;i < x.size();i++) {
			if (x[i] <= mid) {
				
			}
			else {
				add_len = add_len + x[i] - mid;
			}
		}
		if (add_len >= y) {
			result = mid;
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> tree_len;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		tree_len.push_back(k);
	}
	int a = binary_search(tree_len, m);
	cout << a << endl;
	return 0;
}
