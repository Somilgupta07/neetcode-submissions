class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26]={0};
        int left=0;
        int maxFreq=0;
        int ans=0;

        for(int right=0;right<s.length();right++){
            cnt[s[right]-'A']++;

            maxFreq=max(maxFreq,cnt[s[right]-'A']);
            int windowSize=right-left+1;
            int replacements=windowSize-maxFreq;
            if(replacements>k){
                cnt[s[left]-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);

        }
        return ans;
    }
};
