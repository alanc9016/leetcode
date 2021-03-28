def subsetsWrapper(soFar, res):
    if len(res) == 0:
        print(soFar)
    else:
        subsetsWrapper(soFar + res[0], res[1:])
        subsetsWrapper(soFar, res[1:])

def subsets(s):
    subsetsWrapper("",s)

subsets("abc")

