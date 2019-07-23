class Solution {
public:
    string reverseWords(string s) {
        // 时间复杂度 O(n)
        // 空间复杂度 O(n)
        reverse(s.begin(), s.end());
        
        string res = "", partial = "";
        for (char c : s) {
            if (c == ' ') {
                if (partial != "") {
                    reverse(partial.begin(), partial.end());
                    res += partial + ' ';
                    partial = "";
                }
            } else {
                partial += c;
            }
        }
        reverse(partial.begin(), partial.end());
        res += partial;
        if (res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }
};