#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.length()==4 || s.length()==6){//길이가 4,6인것만 확인하면됨
        for(int i=0;i<s.length();i++){//길이동안 돌면서
            if(s[i]>=48 && s[i]<=57){//0~9인경우에는 넘어가고 아닌경우에는 false로 바꿔줌
                
            }
            else{
                answer=false;
                break;
            }
        }
    }
    else{
        answer=false;
    }
    return answer;
}
