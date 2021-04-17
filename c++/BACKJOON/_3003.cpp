#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int arr[6] = { 1,1,2,2,2,8 };
	int white[6];
	for (int i = 0;i < 6;i++) {
		cin >> white[i];
		cout << arr[i] - white[i] << " ";
	}
	cout << endl;
	
	return 0;
}
