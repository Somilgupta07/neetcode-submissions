class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& prices, int i, int canBuy) { 
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][canBuy]!=-1){
            return dp[i][canBuy];
        }

        int profit=0;
        if(canBuy==1){
            int buy=-prices[i]+solve(prices,i+1,0);
            int skip=solve(prices,i+1,1);
            profit=max(buy,skip);

        }else{
            int sell=prices[i]+solve(prices,i+2,1);
            int hold=solve(prices,i+1,0);
            profit=max(sell,hold);
        }
        return dp[i][canBuy]=profit;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return solve(prices,0,1);

    }
};
