class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>res;
        for(string str: strs){
            string key=str;
            sort(key.begin(),key.end());

            mp[key].push_back(str);
        }
        for(auto& it: mp){
            res.push_back(it.second);
    
        }
        return res;
    }

};
