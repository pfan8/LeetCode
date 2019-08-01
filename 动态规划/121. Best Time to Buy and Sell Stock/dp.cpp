class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            DP：假设第i-1天的sum是能获得的累计收益，profit是第i天能获得的收益
            sum += profit，如果profit大于sum，则重新赋值sum，说明找到新的买点
            用maxprofit记录sum的最大值，不能返回sum，因为最后可能会减小
            时间复杂度：O(n)
            空间复杂度：O(n)
        */
        if(prices.size() < 2) return 0;
        int sum = 0, max_profit = 0;
        int profit;
        for(int i = 1; i < prices.size(); i++) {
            profit = prices[i] - prices[i-1];
            sum += profit;
            if(profit > sum) sum = profit;
            if(sum > max_profit) max_profit = sum;
        }
        return max_profit;
    }
};