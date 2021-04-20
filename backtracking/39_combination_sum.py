class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        self.backtrack([],candidates, res, target)
        return res
    
    def backtrack(self, soFar, candidates, res, target):
        if target < 0:
            return
        if target == 0:
            res.append(soFar)
            return
        for i in range(len(candidates)):
            self.backtrack(soFar+[candidates[i]], candidates[i:], res, target - candidates[i])
