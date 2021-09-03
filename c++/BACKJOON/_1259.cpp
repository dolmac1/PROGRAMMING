//펠린드롬 b1
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		string input_val;
		cin >> input_val;
		if (input_val == "0") {
			break;
		}
		int pel_ok = 1;
		for (int i = 0;i < input_val.length() / 2;i++) {
			if (input_val[i] != input_val[input_val.length() - 1 - i]) {
				pel_ok = 0;
				break;
			}
		}
		if (pel_ok == 1) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}
