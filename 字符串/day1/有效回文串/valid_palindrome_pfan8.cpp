class Solution {
public:
    bool isPalindrome(string s) {
        int fpoint = 0;
        int bpoint = s.size()-1;
        while(fpoint < bpoint) {
            if(!isalnum(s[fpoint])) {
                fpoint++;
                continue;
            }
            if(!isalnum(s[bpoint])) {
                bpoint--;
                continue;
            }
            if(tolower(s[fpoint]) != tolower(s[bpoint]))
                return false;
            else {
                fpoint++;
                bpoint--;
            }
        }
        return true;
    }
};