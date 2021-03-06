#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b, c;
	int number;
	int result = 0;
	int max_num = 0;
	int max_num2 = 0;
	cin >> a >> b >> c;
	for (int i = 0;i < a;i++) {
		cin >> number;
		if (number >= max_num) {
			max_num2 = max_num;
			max_num = number;
		}
	}
	for (int i = 0;i < b;i++) {
		if (i != 0 && i%c == 0) {
			result = result + max_num2;
		}
		else {
			result = result + max_num;
		}
	}

	cout << result << endl;

	
	return 0;
}
