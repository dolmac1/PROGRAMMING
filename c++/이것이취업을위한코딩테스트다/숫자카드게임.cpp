#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int min_val[100] = { 0 };
	int a, b;
	cin >> a >> b;
	for (int i = 0;i < a;i++) {
		int min_vals = 999999;
		for (int j = 0;j < b;j++) {
			int k;
			cin >> k;
			if (k < min_vals) {
				min_vals = k;
			}
		}
		min_val[i] = min_vals;
	}
	int result = 0;
	for (int i = 0;i < a;i++) {
		if (result < min_val[i]) {
			result = min_val[i];
		}
	}
	cout << result << endl;
	return 0;
}

//
