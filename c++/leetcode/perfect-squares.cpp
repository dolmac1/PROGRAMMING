class Solution {
public:
    int numSquares(int n) {
        if(n==1){
            return 1;
        }
        int dp[10001];
        for(int i=0;i<=n;i++){
            dp[i] = i;
        }
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};

// https://leetcode.com/problems/perfect-squares
