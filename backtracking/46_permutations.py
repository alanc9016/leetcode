class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        
        self.permuteUtil(res, [], nums)
        
        return res
    
    def permuteUtil(self, res, soFar, rest):
        if len(rest) == 0:
            res.append(soFar)
            
        for i in range(len(rest)):
            next = soFar + [rest[i]]
            rem = rest[:i] + rest[i+1:]
            self.permuteUtil(res, next, rem)
