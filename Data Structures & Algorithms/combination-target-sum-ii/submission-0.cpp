class Solution {
   public:
    vector<vector<int>> res;
    vector<int> curr;
    void solve(vector<int>& candidates, int target, int i) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (i == candidates.size() || target < 0) {
            return;
        }

        curr.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1);
        curr.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        solve(candidates, target, i + 1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return res;
    }
};
