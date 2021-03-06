#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a;
	cin >> a;
	int x = a[0]-96;
	int y = a[1]-48;
	int result = 0;
	int resultx[8] = { -2,-2,-1,-1, 1, 1, 2, 2 };
	int resulty[8] = { -1,+1,-2,+2,-2,+2,-1,+1 };
	for (int i = 0;i < 8;i++) {
		resultx[i] += x;
		resulty[i] += y;
		if ((resultx[i] >= 1 && resulty[i] >= 1)&&(resultx[i]<=8 && resulty[i]<=8)) {
			result++;
		}
	}
	cout << result << endl;
	return 0;
}
