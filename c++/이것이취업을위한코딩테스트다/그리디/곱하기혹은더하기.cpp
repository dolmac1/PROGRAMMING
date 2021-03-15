#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	string num_arr;
	cin >> num_arr;
	int result = 0;
	for (int i = 0;i < num_arr.length();i++) {
		int num = num_arr[i] - '0';
		if (result * num > result + num) {
			result = result * num;
		}
		else {
			result = result + num;
		}
	}
	cout << result << endl;
	return 0;
}
