class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        
        self.subset_util(res, [], nums)
        
        return res
        
    def subset_util(self, res, soFar, rest):
        if len(rest) == 0:
            res.append(soFar)
        else:
            self.subset_util(res, soFar + [rest[0]], rest[1:])
            self.subset_util(res, soFar, rest[1:])
        
