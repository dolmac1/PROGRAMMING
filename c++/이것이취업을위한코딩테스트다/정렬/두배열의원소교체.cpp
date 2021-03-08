#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n, m;
	cin >> n >> m;
	int arr1[100000];
	int arr2[100000];
	int result = 0;
	for (int i = 0;i < n;i++) {
		cin >> arr1[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> arr2[i];
	}
	sort(arr1, arr1+n);
	sort(arr2, arr2+n, greater<>());
	int change = 0;
	for (int i = 0;i < n;i++) {
		if (arr1[i] < arr2[i]) {
			arr1[i] = arr2[i];
			change++;
		}

		if (change == m) {
			i = n;
		}
	}

	for (int i = 0;i < n;i++) {
		result = result + arr1[i];
	}
	
	cout << result << endl;
	
	return 0;
}
