#
Definition
for a binary tree node.#class TreeNode: #def __init__(self, val = 0, left = None, right = None): #self.val = val# self.left = left# self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) - > TreeNode:
    self.element_to_idx = { el: idx
        for idx, el in enumerate(inorder) }
self.pre = preorder
self.ino = inorder
self.idx = 0
new_root = self.build(inorder, 0, len(self.pre))
return new_root

def build(self, elements, i, j):
    if i == j:
    return None

root = TreeNode(self.pre[self.idx])

curr_idx = self.element_to_idx[root.val]
self.idx += 1
root.left = self.build(elements, i, curr_idx)
root.right = self.build(elements, curr_idx + 1, j)

return root