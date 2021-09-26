#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n==1 || n==2){
        return 1;
    }
    else{
        int a,b,c;
        b=1;
        c=1;
        for(int i=2;i<n;i++){
            a=b;
            b=c;
            c=(a+b)%1234567;
        }
        answer = c;
    }
    return answer;
}
