# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    global m
    def maxPathSum(self, root: TreeNode) -> int:
        global m
        m = root.val
        self.maxSum(root)
        return m
    
    def maxSum(self, root: TreeNode) -> int:
        if root is None:
            return 0
        curr = root.val
        left = max(self.maxSum(root.left),0)
        right = max(self.maxSum(root.right),0)
        global m 
        m = max(m, curr + left + right)
        return curr + max(left, right)