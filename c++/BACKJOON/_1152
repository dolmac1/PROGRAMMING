#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string a = {};
	getline(cin, a);
	int k = 1;
	for (int b = 0;b < a.length();b++) {
		if (a.at(b)==' ') {
			k++;
		}
	}
	if (a.at(0) == ' ') {
		k--;
	}
	if (a.at(a.length() - 1) == ' ') {
		k--;
	}
	cout << k << endl;
	return 0;
}
