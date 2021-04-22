#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int find_loc(vector<pair<int, int>> a, int b) {
	int loc = -1;
	for (int i = 0;i < a.size();i++) {
		if (a[i].first == b) {
			loc = i;
			break;
		}
	}
	return loc;
}
int find_min_loc(vector<pair<int, int>> a) {
	int min_val = a[0].second;
	int min_loc = 0;
	for (int i = 1; i < a.size();i++) {
		if (min_val > a[i].second) {
			min_loc = i;
			min_val = a[i].second;
		}
	}
	return min_loc;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> arr;
	for (int i = 0; i < m;i++) {
		int k;
		cin >> k;
		int loc_k = find_loc(arr, k);
		if (loc_k != -1) {
			arr[loc_k].second++;
		}
		else {
			pair<int, int> push_val;
			if (arr.size() < n) {
				push_val.first = k;
				push_val.second = 1;
				arr.push_back(push_val);
			}
			else {
				int min_loc = find_min_loc(arr);
				arr.erase(arr.begin()+min_loc);
				push_val.first = k;
				push_val.second = 1;
				arr.push_back(push_val);
			}
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0;i < arr.size();i++) {
		cout << arr[i].first << " ";
	}
	cout << '\n';
	return 0;
}
