#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int count;
	cin >> count;
	int result = 0;
	for (int i = 0;i < count;i++) {
		string word;
		cin >> word;
		int init[26] = { 0 };
		for (int j = 0;j < word.length();j++) {
			if (word[j] == word[j + 1]) {

			}
			else {
				if (init[word[j] - 97] == 0) {
					init[word[j] - 97]++;

				}
				else {
					goto a;
				}
			}
		}
		result++;
	a: {}
	}
	cout << result << endl;
	return 0;
}
