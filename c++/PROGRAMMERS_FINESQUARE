using namespace std;
int gcd(int a, int b){ //최대공약수 구하는 함수
    while(b!=0){
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}
long long solution(int w,int h) {
    long long w_long = w;
    long long h_long = h;
    long long answer = 1;
    long long minus_val = (w+h) - gcd(w,h); //접히는 부분의 갯수를 구하는 공식
    answer = w_long * h_long - minus_val; //전체 사각형중 접히는 부분것을 빼줌
    return answer;
}
