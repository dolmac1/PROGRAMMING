#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	int result = 0;
	while (a != 1) {
		if (a%b == 0) {
			a = a / b;
		}
		else {
			a = a - 1;
		}
		result++;
	}
	cout << result << endl;
	return 0;
}

//
