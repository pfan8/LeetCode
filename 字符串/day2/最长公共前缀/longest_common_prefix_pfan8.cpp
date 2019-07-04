class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        size_t min_len = INT_MAX;
        for(string s : strs) {
            min_len = min(min_len, s.size());
        }
        int word = 0;
        for(;(word < strs.size()) && (min_len > 0);) {
            if(strs[0].substr(0,min_len) == strs[word].substr(0,min_len)) {
                word++;
            } else {
                min_len--;
            }
        }
        return strs[0].substr(0,min_len);
    }
};