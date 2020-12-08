#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int a = 0;a < tcase;a++) {
		string words;
		cin >> words;
		int finalcheck = 0;
		for (int b = 0;b < words.length()-1;b++) {
			if (words[b] < words[b + 1]) {
				finalcheck = 1;
			}
		}
		if (finalcheck == 1) {
			next_permutation(words.begin(), words.end());
		}
		cout << words << endl;
	}
	return 0;
}
