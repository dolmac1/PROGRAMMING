#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0;i < n;i++) {
		arr.push_back(i + 1);
	}
	int erase_val = 0;
	cout << "<";
	for (int i = 0;i < arr.size();) {
		erase_val = (erase_val + k -1) % arr.size();
		cout << arr[erase_val];
		arr.erase(arr.begin() + erase_val);
		if (!arr.empty()) {
			cout << ", ";
		}
	}
	cout << ">";
	return 0;
}
