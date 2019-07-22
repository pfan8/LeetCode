class Solution {
/**
 *  DFS
 *  时间复杂度：O(n^n)，每行循环n次，总共循环n行
 *  空间复杂度：O(n^3)，res存储多个n^2解
 */
private:
    vector<vector<string>> res;
    vector<string> board;

    void solve(vector<int>& pos, int depth, int n) {
        if(depth == n) {
            res.push_back(board);
        } else {
            for(int i = 0; i < n; i++) {
                pos.push_back(i);
                if(valid(pos, depth)) {
                        board[depth][i] = 'Q';
                        solve(pos, depth + 1, n);
                        board[depth][i] = '.';
                }
                pos.pop_back();
            } 
        }
    }
    
    bool valid(vector<int>& pos, int depth) {
        for(int i = 0; i < depth; i++) {
            if(abs(pos[i] - pos[depth]) == depth - i || pos[i] ==                         pos[depth])
                return false;
        }
        return true;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        if(!n) return res;
        string row(n, '.');
        for(int i = 0; i < n; i++) board.push_back(row);
        vector<int> pos; //存储皇后位置
        solve(pos, 0, n);
        return res;
    }
};