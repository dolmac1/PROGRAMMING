#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int count[26] = { 0 };
	string val;
	cin >> val;
	for (int i = 0;i < val.length();i++) {
		val[i] = tolower(val[i]);
		count[(int)val[i] - 97]++;

	}
	int max = 0;
	int loc = 0;
	int same = 0;
	for (int i = 0;i < 26;i++) {
		if (count[i] > max) {
			max = count[i];
			loc = i;
			same = 1;
		}
		else if (count[i] == max) {
			same++;
		}
	}
	if (same == 1) {
		char result = (char)(loc + 65);
		cout << result << endl;
	}
	else {
		cout << "?" << endl;
	}
}
