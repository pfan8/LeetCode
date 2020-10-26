class Solution {
public:
    string largestNumber(vector<int>& nums) {
        /*
            基数排序:这里只关注高位顺次大小，而不做长度补齐，比如 50 > 400
            时间复杂度：O(n^2)
            空间复杂度：O(n)
        */
        if(!nums.size()) return "0";
        bool all_zero_flag = true;
        for(auto num: nums) {
            if(num) {
                all_zero_flag = false;
                break;
            }
        }
        if(all_zero_flag) return "0";
        vector<int> buckets[10];
        int bit = 0;
        int length = 0;
        for(int n: nums) {
            string str_n = to_string(n);
            bit = int(str_n[0] - '0');
            length = str_n.length();
            auto iter = buckets[bit].begin();
            for(; iter != buckets[bit].end(); iter++) {
                int val = *iter;
                int val_length = to_string(val).length();
                int temp = n;
                if(length != val_length) {
                    while(val_length > 0) {
                        val_length--;
                        temp *= 10;
                    }
                    temp += val;
                    int templ = length;
                    while(templ > 0) {
                        templ--;
                        val *= 10;
                    }
                    val += n;
                }
                if(temp >= val) {
                    buckets[bit].insert(iter, n);
                    break;
                }
            }
            if(iter == buckets[bit].end()) buckets[bit].push_back(n);
        }
        string res;
        for(int i=9; i>=0; i--) {
            for(int n: buckets[i]) {
                res += to_string(n);
            }
        }
        return res;
    }
};