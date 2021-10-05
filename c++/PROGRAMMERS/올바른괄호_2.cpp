#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    stack<char> imsi_stack;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            imsi_stack.push('(');
        }
        else{
            if(imsi_stack.empty()){
                answer = false;
                break;
            }
            else{
                imsi_stack.pop();
            }
        }
    }
    if(!imsi_stack.empty()){
        answer = false;
    }
    return answer;
}
