class Solution {
public:
    int countPrimes(int n) {
        bitset<5000000> prime;
        prime.set();
        int result = 0;
        if(n==0 || n==1){
            return 0;
        }
        else{
            prime.reset(0);
            prime.reset(1);
            for(int i=2;i<sqrt(n);i++){    
                for(int j=i+i;j<n;j += i){
                    prime.set(j,false);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(prime[i]==1){
            result++;
            }
        }
        
        
        return result;
    }
};

// https://leetcode.com/problems/count-primes/
