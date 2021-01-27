#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string board[50];
string whiteFirst[8] = {
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" }
};
string blackFirst[8] = {
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" }
};

int wb(int x, int y)
{
	int count = 0;
	for (int i = x; i < x + 8; i++)
		for (int j = y; j < y + 8; j++)
			if (board[i][j] != whiteFirst[i - x][j - y])
				count++;
	return count;
}
int bw(int x, int y)
{
	int count = 0;
	for (int i = x; i < x + 8; i++)
		for (int j = y; j < y + 8; j++)
			if (board[i][j] != blackFirst[i - x][j - y])
				count++;
	return count;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int M, N;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	int result = 100000;
	for (int i = 0; i + 7 < N; i++)
		for (int j = 0; j + 7 < M; j++)
			result = min(result, min(wb(i, j), bw(i, j)));
	cout << result << endl;
	return 0;
}
