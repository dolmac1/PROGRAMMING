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
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	cout << arr[k - 1] << endl;
	return 0;
}
