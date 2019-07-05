class Solution {
public:
    string reverseWords(string s) {
        // 时间复杂度 O(n)
        // 空间复杂度 O(n)
        string res = "";
        int pos = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                pos = i;
                while(++i < s.length() && s[i] != ' ') {}
                res = s.substr(pos,i-pos) + " " + res;
            }
        }
        return res.substr(0,res.length()-1);
    }
};