def perm(soFar, rest):
    if len(rest) == 0:
        print(soFar)
    else:
        for i in range(len(rest)):
            next = soFar + rest[i]
            rem = rest.replace(rest[i],"")
            perm(next, rem)

def permutation(s):
    perm("",s)

permutation("abc")
