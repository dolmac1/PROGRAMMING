#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int m, n;
	cin >> m >> n;
	vector<int> arr;
	for (int i = 0;i < m;i++) {
		int k;
		cin >> k;
		arr.push_back(k);
	}
	int return_val = 0;
	for (int i = 0;i < m;i++) {
		int result = arr[i];
		if (result == n) {
			return_val++;
		}
		else {
			for (int j = i + 1;j < m;j++) {
				result += arr[j];
				if (result == n) {
					return_val++;
					break;
				}
			}
		}
		
	}
	cout << return_val << endl;
	return 0;
}
