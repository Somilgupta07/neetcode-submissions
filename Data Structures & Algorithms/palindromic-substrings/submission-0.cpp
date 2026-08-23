class Solution {
public:
    int expand(string s,int left,int right){
        int cnt=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            ans+=expand(s,i,i);
            ans+=expand(s,i,i+1);
        }
        return ans;
    }
};
