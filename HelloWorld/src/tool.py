#!/usr/bin/env python3

from typing import List,Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class PrintNode:
    def preorder(self,root):
        if root ==None:
            return
        print(root.val,end=" ")
        self.preorder(root.left)
        self.preorder(root.right)
    def inorder(self,root):
        if root ==None:
            return
        self.inorder(root.left)
        print(root.val,end=" ")
        self.inorder(root.right)    
    def postorder(self,root):
        if root ==None:
            return
        self.inorder(root.left)
        self.inorder(root.right)   
        print(root.val,end=" ")
        

if __name__ == "__main__":
    pass


