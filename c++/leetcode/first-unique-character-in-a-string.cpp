class Solution {
public:
    int firstUniqChar(string s) {
        int alpha[26] = {0};
        for(int i=0;i<s.length();i++){
            alpha[s[i]-97]++;
        }
        for(int i=0;i<s.length();i++){
            if(alpha[s[i]-97]==1){
                return i;
            }
        }
        return -1;
    }
};

//https://leetcode.com/problems/first-unique-character-in-a-string
