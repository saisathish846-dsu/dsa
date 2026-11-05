class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (size_t len = 0; len < strs[0].size(); len++) {
            char c = strs[0][len];
            for (size_t k = 1; k < strs.size(); k++) {
                if (len >= strs[k].size() || strs[k][len] != c)
                    return strs[0].substr(0, len);
            }
        }
        return strs[0];
    }
};

