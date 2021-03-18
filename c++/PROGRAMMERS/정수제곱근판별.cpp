#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long imsi = sqrt(n);
    if(imsi*imsi == n){
        answer = (imsi+1)*(imsi+1);
    }
    else{
        answer=-1;
    }
    return answer;
}
