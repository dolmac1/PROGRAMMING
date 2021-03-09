#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int binary_search(vector<int> input_val, int begin, int end, int find_val) {
	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (input_val[mid] == find_val) {
			return 1;
		}
		else if (input_val[mid] > find_val) {
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	int m;
	cin >> n;
	vector<int> input_vec;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		input_vec.push_back(k);
	}
	sort(input_vec.begin(), input_vec.end());

	cin >> m;
	vector<int> result;
	for (int i = 0;i < m;i++) {
		int aa;
		cin >> aa;
		result.push_back(aa);
	}
	for (int i = 0;i < m;i++) {
		if (binary_search(input_vec, 0, n-1, result[i]) == 1) {
			cout << "yes ";
		}
		else {
			cout << "no ";
		}
	}
	
	return 0;
}
