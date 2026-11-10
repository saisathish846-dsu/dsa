class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if (c[i] > remaining) break;                  // sorted, nothing later fits
            if (i > start && c[i] == c[i - 1]) continue;  // skip duplicate at same level
            path.push_back(c[i]);
            backtrack(c, i + 1, remaining - c[i], path, result);  // i+1: use each once
            path.pop_back();
        }
    }
};