#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char a, char b){
    int num1 = a;
    int num2 = b;
    return num1 > num2;
}

string solution(string s) {
    string answer = "";
    int k = s.length();
    sort(s.begin(), s.end(),cmp);
    answer = s;
    return answer;
}
