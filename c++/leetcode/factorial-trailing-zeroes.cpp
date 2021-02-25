class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
		while(n){
            result = result + n / 5;
            n = n / 5;
        }        
        return result;
    }
};

// https://leetcode.com/problems/factorial-trailing-zeroes/
