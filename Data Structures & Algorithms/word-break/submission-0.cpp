class Solution {
public:
    bool solve(int i,string& s, unordered_set<string>& words,vector<int>& dp){
        if(i==s.length())return true;
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<s.length();j++){
            string word=s.substr(i,j-i+1);
            if(words.find(word)!=words.end()){
                if(solve(j+1,s,words,dp)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>words;
        for(string word: wordDict){
            words.insert(word);
        }
        vector<int>dp(s.length(),-1);
        return solve(0,s,words,dp);
    }
};
