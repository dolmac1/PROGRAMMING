#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	int x = 1;
	int y = 1;
	cin >> n;
	cin.ignore();
	string input_val;
	getline(cin,input_val);
	for(int i=0;i<input_val.length();i=i+2) {
		switch (input_val[i]) {
			case 'L':
				y--;
				if (y == 0) {
					y = 1;
				}
				break;
			case 'R':
				y++;
				if (y > n) {
					y = n;
				}
				break;
			case 'U':
				x--;
				if (x == 0) {
					x = 1;
				}
				break;
			case 'D':
				x++;
				if (x > n) {
					x = n;
				}
				break;
			default:
				break;

		}
	}
	cout << x << " " << y << endl;
	return 0;
}
