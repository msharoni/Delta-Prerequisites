'''Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
'''



class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def hasSon(self):
        if self.right or self.left:
            return True
     
def serialize(node):
    if not node:
        return "#"
    left = serialize(node.left) 
    right = serialize(node.right) 
    
    return f"{node.val} {left}{right}"
    
def deserialize(tree_str):
    values = iter(serialize(node).split(' '))
    def helper():
        val = next(values)
        if val == '#':
            return None
        node = Node(val)
        node.left = helper()
        node.right = helper()

node = Node('root', Node('left', Node('left.left') , Node('left.right')), Node('right'))
print(serialize(node))
print(deserialize(serialize(node)))

#assert deserialize(serialize(node)).left.left.val == 'left.left'