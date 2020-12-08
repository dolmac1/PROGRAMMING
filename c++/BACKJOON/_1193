#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int X;
	cin >> X;
	if (X == 1)
	{
		cout << 1 << "/" << 1 << "\n";
		return 0;
	}
	int sum = 1;
	long long cnt = 0;
	int num = 1;
	while (1)
	{
		sum++;
		cnt += num;
		if (cnt >= X)
			break;
		num++;
	}
	int child = 1, parent = 1;
	if (sum % 2)
		child = sum - 1;
	else
		parent = sum - 1;
	while (1)
	{
		if (cnt == X)
			break;
		if (sum % 2)
		{
			parent++;
			child--;
		}
		else
		{
			child++;
			parent--;
		}
			cnt--;
	}
	cout << child << "/" << parent << "\n";
	return 0;
}
