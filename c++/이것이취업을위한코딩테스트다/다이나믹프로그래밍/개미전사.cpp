#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	int result[100];
	int arr[100];
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	result[0] = arr[0];
	result[1] = max(arr[0], arr[1]);
	for (int i = 2;i < n;i++) {
		result[i] = max(result[i - 1], result[i - 2] + arr[i]);
	}
	cout << result[n-1] << endl;;
	return 0;
}
