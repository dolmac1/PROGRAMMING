#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    for(int i=0;i<seoul.size();i++){//서울 배열을 크기만큼 확인하면서
        if(seoul[i].compare("Kim")==0){//Kim이 있을 경우에
            answer="김서방은 "+to_string(i)+"에 있다";//출력
            break;
        }
    }
    return answer;
}
