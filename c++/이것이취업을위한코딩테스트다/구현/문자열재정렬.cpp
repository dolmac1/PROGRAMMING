#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	string input_arr;
	cin >> input_arr;
	vector<char> input_val;
	for (int i = 0;i < input_arr.length();i++) {
		input_val.push_back(input_arr[i]);
	}
	sort(input_val.begin(), input_val.end());
	int sum = 0;
	for (int i = 0;i < input_val.size();i++) {
		int number = input_val[i] - '0';
		if (number >= 0 && number <= 9) {
			sum += number;
		}
		else {
			cout << input_val[i];
		}
	}
	cout << sum << endl;
	return 0;
}
