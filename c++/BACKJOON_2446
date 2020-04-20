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
	int k = 2*n-1;
	int l = 0;
	for (int i = 0;i < 2 * n - 1;i++) {
		if (i < n-1) {
			for (int ii = 0;ii < l;ii++) {
				cout << " ";
			}
			for (int j = 0;j < k;j++) {
				cout << "*";
			}
			l++;
			k = k - 2;
		}
		else {
			for (int ii = 0;ii < l;ii++) {
				cout << " ";
			}
			for (int j = 0;j < k;j++) {
				cout << "*";
			}
			l--;
			k = k + 2;
		}
		cout << endl;
		
	}
	return 0;
}
