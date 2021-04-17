#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

bool comp(char ch1, char ch2) {
	return ch1 > ch2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	string a;
	cin >> a;
	vector<char> a_arr;
	for (int i = 0; i < a.length();i++) {
		a_arr.push_back(a[i]);
	}
	sort(a_arr.begin(), a_arr.end(), comp);

	for (int i = 0;i < a_arr.size();i++) {
		cout << a_arr[i];
	}

	
	return 0;
}
