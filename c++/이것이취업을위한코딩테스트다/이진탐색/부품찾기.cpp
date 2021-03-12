#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string search(vector<int>& input_vec, int begin, int end, int find_val) {
	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (input_vec[mid] == find_val) {
			return "yes";
		}
		else if (input_vec[mid] < find_val) {
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return "no";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector<int> input_val;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		input_val.push_back(k);
	}
	sort(input_val.begin(), input_val.end());
	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int k;
		cin >> k;
		string result = search(input_val, 0, n - 1, k);
		cout << result << " ";

	}
	cout << endl;
	return 0;
}
