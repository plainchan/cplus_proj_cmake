#!/usr/bin/env python3

from tool import *
 
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        self.hashMap={}

        for i,v in enumerate(inorder):
            self.hashMap[v]=i
            
        return self.recursive(postorder,0,len(postorder)-1,inorder,0,len(inorder)-1)
 
    def recursive(self,postorder: List[int],p_start,p_end, inorder: List[int],in_start,in_end):
        if p_start > p_end:
            return None
        # print(p_start, p_end)
        p_root = p_end
        root = TreeNode(postorder[p_root])
        index = self.hashMap[postorder[p_root]]
        
        root.left = self.recursive(postorder,p_start,p_start+(index-in_start)-1,inorder,in_start,index-1)
        root.right = self.recursive(postorder,p_start+(index-in_start),p_end-1,inorder,index+1,in_end)
        return root
        

class Solution1:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(candidates: List[int], target: int, index: int, nums: List[int]):
            if target<0:
                return
            if target==0:
                ans.append(nums[:])
                return
            
            for i in range(index,len(candidates)):
                nums.append(candidates[i])
                backtrack(candidates,target-candidates[i],i,nums)
                nums.pop()
        ans=[]
        nums=[]  
        backtrack(candidates,target,0,nums)
        return ans



if __name__ == "__main__":
    # nodePrint = PrintNode()
    
    # inorder = [9,3,15,20,7]
    # postorder = [9,15,7,20,3]
    # inorder = [1,2]
    # postorder = [2,1]

    # print(inorder)
    # print(postorder)
    # print("-----------------------")
    # s = Solution()
    # node = s.buildTree(inorder,postorder)
    # # nodePrint.preorder(node)
    # # print()
    # nodePrint.inorder(node)
    # print()
    # nodePrint.postorder(node)
    # print()
  
    nums = [1,2,3,4]
    c = Solution1()
    print(c.combinationSum(nums,20))
    