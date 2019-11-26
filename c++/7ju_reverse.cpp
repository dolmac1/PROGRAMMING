#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int a = 0;a < tcase;a++) {
		int number1;
		int number2=0;
		cin >> number1;
		int number1a = number1;
		for (;number1 != 0;) {
			number2 = number2 * 10;
			number2 = number2 + (number1 % 10);
			number1 = number1 / 10;
		}
		int numbersum = number1a + number2;
		int numbersuma = numbersum;
		int numbersumb = 0;
		for (;numbersum != 0;) {
			numbersumb = numbersumb * 10;
			numbersumb = numbersumb + (numbersum % 10);
			numbersum = numbersum / 10;
		}
		if (numbersuma == numbersumb) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}