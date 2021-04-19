#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(0);
	int n;
	cin >> n;
	for (int i = 2;i <= n;i++) {
		arr.push_back(9999999);
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3]+1);
		}
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2]+1);
		}
		arr[i] = min(arr[i], arr[i - 1] + 1);
	}
	cout << arr[n] << endl;
	return 0;
}
