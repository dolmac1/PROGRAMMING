class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int loop_count = 0;
        for(int i=s.length()-1;i>=0;i--){
            int add_num = 1;
            for(int j=0;j<loop_count;j++){
                add_num = add_num * 26;
            }
            result = result + (add_num * (s[i]-64));
            loop_count++;
        }
        return result;
    }
};

//https://leetcode.com/problems/excel-sheet-column-number
