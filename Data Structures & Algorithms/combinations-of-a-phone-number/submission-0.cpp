class Solution {
   public:
    vector<string> ans;
    map<char, string> mp = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    void solve(string& digits, int index, string current) {
        if (index == digits.length()) {
            ans.push_back(current);
            return;
        }

        string letters = mp[digits[index]];
        for (char ch : letters) {
            current.push_back(ch);

            solve(digits, index + 1, current);

            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        solve(digits, 0, "");
        return ans;
    }
};
