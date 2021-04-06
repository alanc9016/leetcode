class Solution:
    def minOperations(self, n: int) -> int:
        myDict = {}
        arr = []
        res = 0

        for i in range(n):
            arr.append((2 * i) + 1)
        
        target = sum(arr)//n
        
        for num in arr:
            if abs(target - num) != 0 and abs(target - num) not in myDict:
                myDict[abs(target-num)] = True
                res+= abs(target-num)
        
        
        return res