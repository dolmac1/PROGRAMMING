#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end());
	int n_val = n;
	int result = 0;
	for (int i = 0;i < n;i++) {
		result = result + (n_val * arr[i]);
		n_val--;
	}
	cout << result << endl;
	return 0;
}
