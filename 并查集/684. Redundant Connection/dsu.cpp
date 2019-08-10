class Solution {
    // ???DSU???????parent?????????????
    // ??????O(n)
    // ??????O(n)
private:
    int find(vector<int> &parents,int x) {
        // ????
        if(parents[x] != x)
            parents[x] = find(parents, parents[x]);
        return parents[x];
    }
    
    void uni(vector<int> &parents, int p1, int p2) {
        if(p1 < p2) parents[p2] = p1;
        else parents[p1] = p2; //p1,p2???????????????
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size()+1);
        for(int i = 0; i < parents.size(); i++) parents[i] = i;
        int p1,p2;
        for(auto edge: edges) {
            p1 = find(parents, edge[0]);
            p2 = find(parents, edge[1]);
            if(p1 == p2)
                return edge;
            else
                uni(parents, p1, p2);
        }
        return edges[0];
    }
};