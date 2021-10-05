#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	vector<vector<int>> rgb_price;
	for (int i = 0;i < m;i++) {
		vector<int> imsi;
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		imsi.push_back(aa);
		imsi.push_back(bb);
		imsi.push_back(cc);
		rgb_price.push_back(imsi);
	}
	for (int i = 1;i < m;i++) {
		rgb_price[i][0] = min(rgb_price[i - 1][1] + rgb_price[i][0], rgb_price[i - 1][2] + rgb_price[i][0]);
		rgb_price[i][1] = min(rgb_price[i - 1][0] + rgb_price[i][1], rgb_price[i - 1][2] + rgb_price[i][1]);
		rgb_price[i][2] = min(rgb_price[i - 1][0] + rgb_price[i][2], rgb_price[i - 1][1] + rgb_price[i][2]);
	}
	int result = min(rgb_price[rgb_price.size() - 1][0], min(rgb_price[rgb_price.size() - 1][1], rgb_price[rgb_price.size() - 1][2]));
	cout << result << '\n';

	return 0;
}
