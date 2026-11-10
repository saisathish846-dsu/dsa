class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        backtrack(candidates, 0, target, path, result);
        return result;
    }

private:
    void backtrack(const vector<int>& c, int start, int remaining,
                   vector<int>& path, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < (int)c.size(); i++) {
            if (c[i] > remaining) break;   // sorted, so nothing later can fit
            path.push_back(c[i]);
            backtrack(c, i, remaining - c[i], path, result);  // i, not i+1: reuse allowed
            path.pop_back();
        }
    }
};