#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    int a='a'; //97
    int z='z';
    int A='A'; //65
    int Z='Z';
    for(int i=0; i<s.length();i++){
        if(i==0 || s[i-1]==' '){
            if(s[i]>=a && s[i]<=z){
                s[i]=s[i]-97+65;
            }
            answer+=s[i];
        }
        else{
            if(s[i]>=A && s[i]<=Z){
                s[i]=s[i]-65+97;
            }
            answer+=s[i];
        }
    }
    return answer;
}
