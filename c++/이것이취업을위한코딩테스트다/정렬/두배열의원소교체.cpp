#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n, m;
	cin >> n >> m;
	vector<int> arr1;
	vector<int> arr2;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		arr1.push_back(a);
	}
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		arr2.push_back(a);
	}
	sort(arr1.begin(), arr1.end(),greater<>());
	sort(arr2.begin(), arr2.end());
	
	for (int i = 0;i < m;i++) {
		arr1.pop_back();
	}
	for (int i = 0;i < m;i++) {
		arr1.push_back(arr2[arr2.size() - 1]);
		arr2.pop_back();
	}
	int result = 0;
	for (int i = 0;i < arr1.size();i++) {
		result = result + arr1[i];
	}
	cout << result << endl;
	return 0;
}
