#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int one_count = 0;
    string binary_n="";
    while(n!=0){
        if(n%2 == 0){
            binary_n="0"+binary_n;
        }
        else{
            binary_n="1"+binary_n;
            one_count++;
        }
        n/=2;
    }
    binary_n="0"+binary_n;
    cout<<binary_n<<" ";
    while(1){
        for(int i=binary_n.length()-1;i>=0;i--){
            if(binary_n[i] == '0'){
                binary_n[i]='1';
                break;
            }
            else{
                binary_n[i]='0';
            }
        }
        int imsi_count = 0;
        for(int i=0;i<binary_n.length();i++){
            if(binary_n[i] == '1'){
                imsi_count++;
            }
        }
        if(one_count == imsi_count){
            break;
        }
    }
    int mul_val = 1;
    for(int i=binary_n.length()-1;i>=0;i--){
        int bin = 0;
        if(binary_n[i]=='1'){
            bin=1;
        }
        answer = answer + (mul_val*bin); 
        mul_val*=2;
    }
    return answer;
}
