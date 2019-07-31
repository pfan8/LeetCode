class UnionFind {
public:
    vector<int> set;
    vector<int> parent;
    
    UnionFind(int n): set(n), parent(n) {
        for(int i = 0; i < n; i++) {
            set[i] = i;
            parent[i] = i;
        }
    }
    
    int f(int x) {
        if(parent[x] == -1) return -1; // 为了最后计数
        if(parent[x] != x) {
            // 路径压缩
            parent[x] = f(parent[x]);
        }
        return parent[x];
    }
    
    void u(int x1, int x2) {
        int p1 = f(x1);
        int p2 = f(x2);
        if(p1 == p2) return;
        
        // 优先级：row > col
        if(set[p1] < set[p2]) parent[p2] = p1;
        else if(set[p1] > set[p2]) parent[p1] = p2;
        // 没有else，因为不可能相等
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 并查集
        // 时间复杂度：O(m*n)
        // 空间复杂度：O(m*n)，grid和set，parent相同空间，以及存储结果的set
        if(!grid.size()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        UnionFind uf(row*col);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1') {
                    if(i && grid[i-1][j]=='1') {
                        uf.u((i-1)*col+j, i*col+j);
                    }
                    if(j && grid[i][j-1]=='1') {
                        uf.u(i*col+j-1, i*col+j);
                    }    
                } else {
                    uf.parent[i*col+j] = -1;
                }
            }
        }
        unordered_set<int> set;
        for(int i = 0; i < row*col; i++) {
            set.insert(uf.f(i));
        }
        return set.find(-1) == set.end() ? 1 : set.size()-1; //排除parent为-1的值
    }
};