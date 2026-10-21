class Solution {
public:
    vector<vector<string>>res;
    vector<string>curr;
    bool isPalindrome(string s){
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(int start,string s){
        if(start==s.size()){
            res.push_back(curr);
            return;
        }
        for(int i=start;i<s.size();i++){
            string part=s.substr(start,i-start+1);
            if(isPalindrome(part)){
                curr.push_back(part);
                solve(i+1,s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(0,s);
        return res;
    }
};
