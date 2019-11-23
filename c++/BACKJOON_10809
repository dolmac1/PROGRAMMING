#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string data;
	cin >> data;
	int num[26];
	for (int i = 0;i < 26;i++) {
		num[i] = -1;
	}
	for (int i = 0;i < data.length();i++) {
		int k = data[i] - 97;
		if (num[k] == -1) {
			num[k] = i;
		}
	}
	for (int i = 0;i < 26;i++) {
		cout << num[i] << " ";
	}
	return 0;
}
