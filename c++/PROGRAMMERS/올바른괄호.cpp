#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    stack<char> myStack;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            myStack.push('(');
        }
        else{
            if(myStack.empty()){
                answer=false;
                break;
            }
            else{
                myStack.pop();
            }
        }
    }
    if(!myStack.empty()){
        answer = false;
    }
    return answer;
}

//플그 래벨2
