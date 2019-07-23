class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        int swap_point = 0;
        int diff_count = 0; // 检查A,B中不同的字符个数
        int diff_prev = -1; // 记录之前不同的位置
        map<char,int> double_map; // map用于查看是否存在相同的字符对
        bool flag = false; // 是否存在相同或者可交换的字符对
        for(; swap_point < A.size(); swap_point++) {
            if(!flag) {
                if(double_map.find(A[swap_point]) != double_map.end()) {
                    flag = true;
                } else {
                    double_map[A[swap_point]] = 1;
                }
            }
            if(A[swap_point] != B[swap_point]) {
                diff_count ++;
                if(diff_count > 2) {
                    // 不同的字符超过2个
                    return false;
                } else if(diff_prev != -1) {
                    // 检查不同的字符对是否可以交换，不行则返回false
                    if((A[diff_prev] != B[swap_point]) || 
                        (A[swap_point] != B[diff_prev])) {
                        return false;
                    } else {
                        flag = true;
                    }
                } else {
                    diff_prev = swap_point;
                }
            }
        } 
        // 不相同的字符在最末尾
        if(swap_point == A.size()-1) {
            return false;
        }
        if(swap_point == A.size()) {
            if(flag) {
                // 遍历完，全部相同，并且存在可交换的字符对
                return true;
            } else {
                // 遍历完，全部相同，但没有能交换的字符对
                return false;
            }
        }
        return true;
    }
};