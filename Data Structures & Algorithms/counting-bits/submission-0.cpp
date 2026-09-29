class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        //i&1 tells whether the last bit is 1 or not
        //i>>1-> no after removing the bit
        for(int i=0;i<=n;i++){
            dp[i]=dp[i>>1]+(i&1);
        }
        return dp;
    }
};
