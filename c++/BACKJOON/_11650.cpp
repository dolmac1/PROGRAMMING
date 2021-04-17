#include <iostream>
#include <algorithm>
//#include <string>
#include <vector>
//#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(2,0));
	for (int i = 0;i < n;i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0;i < arr.size();i++) {
		cout << arr[i][0] << " " << arr[i][1] << '\n';
	}

	return 0;
}
//vector 초기화 하는거 알아두자
//\n로 하면시간 더 짧다

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	vector<vector<int>> arr;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		vector<int> imsi;
		int x, y;
		cin >> x >> y;
		imsi.push_back(x);
		imsi.push_back(y);
		arr.push_back(imsi);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0;i < arr.size();i++) {
		cout << arr[i][0] << " " << arr[i][1] << '\n';
	}

	return 0;
}
*/
