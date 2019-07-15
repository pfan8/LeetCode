/* 时间复杂度 O(n)
 * 空间复杂度 O(1)
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int votesum = 0;
        int candidate = 0;
        for(int x : nums) {
            if(!votesum) {
                candidate = x;
                votesum++;
            } else {
                if(x == candidate) votesum++;
                else votesum--;
            }
        }
        return candidate;
    }
};