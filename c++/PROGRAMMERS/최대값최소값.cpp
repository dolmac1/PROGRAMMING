#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> num;
    string imsi="";
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            imsi+=s[i];
        }
        else{
            int number = stoi(imsi);
            num.push_back(number);
            imsi="";
        }
    }
    int number = stoi(imsi);
    num.push_back(number);
    sort(num.begin(),num.end());
    answer=to_string(num[0])+" "+to_string(num[num.size()-1]);
    return answer;
}
