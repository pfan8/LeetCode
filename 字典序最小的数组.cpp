/*
    给定n个数字，a1a2a3…an,你可以对这个数组执行任意次以下交换操作：
对于数组中的两个下标i,j（1<=i.j<=n）,如果ai+aj为奇数，那么就可以交换这两个数
现在允许我们的交换次数不限，求出能够通过若干次操作后得到的数组中字典序最小的一个
example:
（A）  
    输入 7 3 5 1    输出 7 3 5 1
（B）
    输入 53941 38641 31525 75864 29026 12199 83522 58200 64784 80987
    输出 12199 29026 31525 38641 53941 58200 64784 75864 80987 83522 
 */
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Solution
{
public:
    Solution(){}
    void quicksort(vector<int> &nums, int left, int right)
    {
        if(left >= right) return;
        int begin = left, end = right;
        int pivot = rand() % (right-left+1) + left;
        swap(nums[pivot], nums[right]);
        pivot = right--;
        while(left < right)
        {
            if(nums[left]<=nums[pivot]) 
            {
                left++;
                continue;
            }
            if(nums[right]>=nums[pivot]) 
            {
                right--;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        if(nums[left] < nums[pivot]) left++;
        swap(nums[left], nums[pivot]);
        
        quicksort(nums, begin, left-1);
        quicksort(nums, left+1, end);
    }

    vector<int> getMinArray(vector<int> arr)
    {
        // 不改变原数组arr，复制到res
        vector<int> res = arr;
        if(!arr.size()) return res;
        bool canswitch = false;
        int odd = arr[0]&1;
        for(int x : arr)
        {
            if((x&1) != odd)
            {
                canswitch = true;
                break;
            }
        }
        if(!canswitch) return arr;
        quicksort(res, 0, res.size()-1);
        return res;
    }
};

int main()
{
    // 时间复杂度：O(nlogn)，检验是否全奇数和全偶数O(n)，快排耗时O(nlogn)
    // 空间复杂度：O(n)，复制了一个数组，不改变原有数组
    Solution s;
    vector<int> arr = {53941,38641,31525, 75864, 29026, 12199, 83522, 58200 ,64784 ,80987};
    vector<int> res = s.getMinArray(arr);
    cout << "before: ";
    for(int x : arr) cout << x << ' ';
    cout << "\nafter: ";
    for(int x : res) cout << x << ' ';
    cout << '\n';
}