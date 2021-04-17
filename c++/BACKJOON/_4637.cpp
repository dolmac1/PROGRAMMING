#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int i = 1;
	int check_num[10000] = { 0 };
	while (1) {
		if (i >= 10000) {
			break;
		}
		else {
			if (check_num[i] == 0) {
				cout << i << endl;
			}
			int check_this_d = i;
			int imsi_i = i;
			while (imsi_i) {
				check_this_d += (imsi_i % 10);
				imsi_i /= 10;
			}
			if (check_this_d < 10000) {
				check_num[check_this_d] = 1;

			}
		}
		i++;
	}
	return 0;
}
