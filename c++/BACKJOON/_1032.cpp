#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector<string> str_val;
	string result="";
	for (int i = 0;i < n;i++) {
		string str;
		cin >> str;
		str_val.push_back(str);
	}
	for (int i = 0;i < str_val[0].length();i++) {
		int same_val = 1;
		char a = str_val[0][i];
		for (int j = 1;j < str_val.size();j++) {
			if (str_val[j][i] != a) {
				same_val = 0;
				break;
			}
		}
		if (same_val == 0) {
			result += "?";
		}
		else {
			result += a;
		}
	}
	cout << result << endl;
	return 0;
}
