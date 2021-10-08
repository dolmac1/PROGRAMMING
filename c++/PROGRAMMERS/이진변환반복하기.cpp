#include <string>
#include <vector>
#include <iostream>
using namespace std;
int remove_zero(string s){
    int count = 0;
    string s_imsi = "";
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            count++;
        }
        else{
            s_imsi+="1";
        }
    }
    s = s_imsi;
    return count;
}
string bin_change(string s){
    int num = s.length();
    string result = "";
    while(num!=0){
        if(num%2==0){
            result = "0" + result;
        }
        else{
            result = "1" + result;
        }
        num/=2;
    }
    return result;
}
vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    while(s!="1"){
        int count = remove_zero(s);
        int ssize = s.length()-count;
        answer[1]+=count;
        s="";
        for(int i=0;i<ssize;i++){
            s+="1";
        }
        s=bin_change(s);
        answer[0]++;
    }
    return answer;
}
