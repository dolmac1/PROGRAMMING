#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int result = 0;
	int hour = 0;
	int min = 0;
	int sec = 0;
	for (;hour <= n;) {
		sec++;
		if (sec == 60) {
			sec = 0;
			min++;
		}
		if (min == 60) {
			min = 0;
			hour++;
		}
		if (sec % 10 == 3 || sec / 10 == 3 || min % 10 == 3 || min / 10 == 3 || hour % 10 == 3 || hour / 10 == 3) {
			result++;
		}
	}
	cout << result << endl;
	return 0;
}
