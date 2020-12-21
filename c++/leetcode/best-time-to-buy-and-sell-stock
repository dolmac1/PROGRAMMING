class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int min_val = prices[0];
        int result = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-min_val > result){
                result = prices[i] - min_val;
            }
            else if(min_val > prices[i]){
                min_val = prices[i];
            }
        }
        return result;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock
