class Solution {
public:
    bool isValid(string s) {
        if(s == "") return true;
        stack<char> st;
        for(char c: s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if(!st.size()) {
                return false;
            } else {
                auto pre_c = st.top();
                st.pop();
                if(c==')' && pre_c=='(') continue;
                else if(c=='}' && pre_c=='{') continue;
                else if(c==']' && pre_c=='[') continue;
                else return false;
            }
        }
        if(st.size()) return false;
        return true;
    }
};