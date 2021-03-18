#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int loc=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            answer+=s[i];
            loc=0;
            continue;
        }
        if(loc%2==0){
            if(s[i]>='a'&&s[i]<='z'){
                s[i]=s[i]-'a'+'A';
            }            
        }
        else{
            if(s[i]>='A'&&s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
        answer+=s[i];
        loc++;
    }
    return answer;
}
