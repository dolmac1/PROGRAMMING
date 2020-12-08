#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int num = 1;
	int order = 0;
	while (num) {
		int num2 = num;
		while (num2) {
			if (num2 % 1000 == 666) {
				order++;
				break;
			}
			num2 = num2 / 10;
		}
		if (order == N) {
			cout << num << endl;
			break;
		}
		else {
			num++;
		}
	}
	return 0;
}
