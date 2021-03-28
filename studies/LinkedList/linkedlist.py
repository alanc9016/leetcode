class Node:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextval = None

class SLinkedList:
    def __init__(self):
        self.headval = None
    def size(self):
        temp = self.headval
        res = 0
        while temp:
            res+=1
            temp = temp.nextval
        return res
    def empty(self):
        return self.headval == None
    def push_front(self, x):
        newNode = Node(x)
        newNode.nextval = self.headval
        self.headval = newNode
        return self.headval
    def pop_front(self):
        if self.headval == None:
            return None
        self.headval = self.headval.nextval
    def listprint(self):
        printval = self.headval
        while printval is not None:
            print (printval.dataval)
            printval = printval.nextval

li = SLinkedList()
li.push_front(1)
li.push_front(2)
li.push_front(3)
li.pop_front()
li.listprint()
print (li.size())

