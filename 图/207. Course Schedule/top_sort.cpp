class Solution {
//  拓扑排序
//  时间复杂度：O(m*n^2)，m为课程数，n为边数
//  空间复杂度：O(m+n)
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int degree[numCourses];
        for(int i = 0; i < numCourses; i++) degree[i] = -1;
        auto size = prerequisites.size();
        int from,to;
        for(int i = 0; i < size; i++) {
            from = prerequisites[i][0];
            to = prerequisites[i][1];
            if(degree[from] == -1) degree[from] = 0;
            if(degree[to] == -1) degree[to] = 1;
            else degree[to]++;
        }
        int head;
        vector<vector<int>>::iterator it;
        while(size > 1) {
            // 找度为0的点，如果不存在，则返回false
            head = -1;
            for(int i = 0; i < numCourses; i++) {
                if(!degree[i]) {
                    head = i;
                    degree[i] = -1;
                    break;
                }
            }
            if(head == -1) return false;
            // 更新degree，并删除from为head的边
            for(it = prerequisites.begin();
                it != prerequisites.end();) {
                from = (*it)[0];
                to = (*it)[1];
                if(from == head) {
                    degree[to]--;
                    it = prerequisites.erase(it);
                    size--;
                } else {
                    it++;
                }
            }
        }
        return true;
    }
};