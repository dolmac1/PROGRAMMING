#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int a=gcd(n,m);
    int b=n*m/a;
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}
