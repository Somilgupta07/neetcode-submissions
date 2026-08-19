class Solution {
public:
    bool same(int a[],int b[]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;

        int cnt1[26]={0};
        int cnt2[26]={0};

        for(char ch: s1){
            cnt1[ch-'a']++;
        }
        int k=s1.length();
        for(int i=0;i<k;i++){
            cnt2[s2[i]-'a']++;
        }
        if(same(cnt1,cnt2))return true;
        for(int i=k;i<s2.length();i++){
            cnt2[s2[i]-'a']++;
            cnt2[s2[i-k]-'a']--;

            if(same(cnt1,cnt2))return true;
        }
        return false;
    }
};
