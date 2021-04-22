#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
//#include <bitset>
using namespace std;

/*int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	bitset<4300000000> num_arr;
	num_arr.reset();
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		num_arr[k] = 1;
	}
	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int k;
		cin >> k;
		cout << num_arr[k] << '\n';
	}

	return 0;
}*/

bool binary_search(int a[], int num, int begin, int end) {
	while (end - begin >= 0) {
		int mid = (begin + end) / 2;
		if (a[mid] == num) {
			return true;
		}
		else if (a[mid] > num) {
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int num[100000];
	for (int i = 0;i < n;i++) {
		cin>>num[i];
	}
	int m;
	sort(num, num+n);
	cin >> m;
	for (int i = 0;i < m;i++) {
		int k;
		cin >> k;
		bool check = binary_search(num, k, 0, n-1);
		cout << check << '\n';
	}
	return 0;
}
