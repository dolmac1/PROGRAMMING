#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	long long a, b;
	cin >> a >> b;
	long long result = (a + b) * (a - b);
	cout << result << endl;
	return 0;
}
