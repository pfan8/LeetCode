class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        // 用stack做one-pass
        // 时间复杂度：O(n)
        // 空间复杂度：O(n)
        int res = 0, n = A.size(), mod = 1e9+7, k, j;
        stack<int> st;
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && A[st.top()]>(i==n?0:A[i])) {
                j = st.top();
                st.pop();
                k = st.empty() ? -1 : st.top();
                res = (res + A[j] * (i-j) * (j-k)) % mod;
            }
            st.push(i);
        }
        return res;
    }
};