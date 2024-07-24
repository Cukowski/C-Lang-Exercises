"""
:type  param_1: {Treenode}
:rtype: float[]
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def average_of_levels_in_binary_tree(root):
    if not root:
        return []

    result = []
    queue = [root]

    while queue:
        level_sum = 0
        level_count = len(queue)

        for _ in range(level_count):
            node = queue.pop(0)
            level_sum += node.val

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level_sum / level_count)

    return result