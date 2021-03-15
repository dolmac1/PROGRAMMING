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
	int chnum = 1;
	for (int i = 1;i < input_arr.size();i++) {
		if (input_arr[i] != input_arr[i - 1]) {
			chnum++;
		}
	}
	cout << chnum / 2 << endl;
	return 0;
}
