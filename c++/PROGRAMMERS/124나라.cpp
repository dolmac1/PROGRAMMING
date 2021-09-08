#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while(1){
        int mok;
        mok = n%3;
        n/=3;
        
        switch(mok){
            case 0:
                answer = "4"+answer;
                n--;
                break;
            case 1:
                answer = "1"+answer;
                break;
            case 2:
                answer = "2"+answer;
                break;
        }
        if (n==0){
            break;
        }
    }
    return answer;
}
