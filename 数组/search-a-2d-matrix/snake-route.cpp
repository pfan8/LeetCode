/* 从左下角开始找，因为只要比当前位置的元素小，则该位置的右下角都不用比较了
*  先向右移动，当碰到target比元素小时，变为向上移动，当碰到target比元素大时再向右移动，如此循环
*  时间复杂度：O(m+n)
*  空间复杂度：O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = 0;
        int direction = 1; // 0 for row, 1 for column
        for (; row >= 0 && col < matrix[0].size();) {
            if(direction) {
                if(target == matrix[row][col]) {
                    return true;
                } else if(target > matrix[row][col]) {
                    col++;
                } else {
                    row--;
                    direction = 0;
                }
            } else {
                if(target == matrix[row][col]) {
                    return true;
                } else if(target < matrix[row][col]) {
                    row--;
                } else {
                    col++;
                    direction = 1;
                }
            }
        }
        return false;
    }
};