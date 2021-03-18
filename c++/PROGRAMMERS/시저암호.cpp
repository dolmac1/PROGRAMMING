#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            answer+=s[i];
            continue;
        }
        if(s[i]>='a'&&s[i]<='z'){
            answer+= (s[i]-'a'+n)%26 + 'a';
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            answer+= (s[i]-'A'+n)%26 + 'A';
        }
        
    }
    return answer;
}
