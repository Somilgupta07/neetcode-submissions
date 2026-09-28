class Solution {
public:
    vector<string>ans;
    void solve(string& s, unordered_set<string>& dict,
               int index, string current) {
                if(index==s.size()){
                    current.pop_back();
                    ans.push_back(current);
                    return;
                }

                for(int i=index;i<s.size();i++){
                    string word=s.substr(index,i-index+1);
                    if(dict.find(word)!=dict.end()){
                        solve(s,dict,i+1,current+word+" ");

                    }
                }
               }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict;
        for(string word:wordDict){
            dict.insert(word);
        }
        solve(s,dict,0,"");
        return ans;
    }
};