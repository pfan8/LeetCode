class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // 记录每个字符开始的子串数量
        // 时间复杂度：O(n)
        // 空间复杂度：O(1)
        auto size = p.length();
        if(!size) return 0;
        int alphas[26] = {0};
        for(int index=0, i=0; index < size;) {
            i = index+1;
            while(i<size && p[i]-'a'==(p[i-1]-'a'+1)%26) i++;
            for(int j=index,id=0; j < i; j++) {
                id = p[j]-'a';
                alphas[id] = max(alphas[id], i-j);
            }
            index = i;
        }
        int res = 0;
        for(auto n : alphas) res += n;
        return res;
    }
};