#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int k = 0;
	for (int i = 0;i < 2 * n - 1;i++) {
		if (i < n) {
			k++;
			for (int j = 0;j < k;j++) {
				cout << "*";
			}
		}
		else {
			k--;
			for (int j = 0;j < k;j++) {
				cout << "*";
			}
		}
		cout << endl;
		
	}
	return 0;
}
