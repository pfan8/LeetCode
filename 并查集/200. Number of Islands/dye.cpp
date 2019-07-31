class Solution {
private:
    void dye(vector<vector<char>>& grid, int row, int col) {
        if(row >= grid.size() 
            || row < 0
            || col >= grid[0].size()
            || col < 0) 
            return;
        if(grid[row][col] == '0') return;
        grid[row][col] = '0';
        dye(grid, row+1, col);
        dye(grid, row-1, col);
        dye(grid, row, col+1);
        dye(grid, row, col-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // 染色法
        int num = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    num++;
                    dye(grid, i, j);
                }
            }
        }
        return num;
    }
};