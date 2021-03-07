#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
