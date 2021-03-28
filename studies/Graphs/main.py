graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []

def bfs(source):
    queue = []
    queue.append(source)
    visited = []
    while queue:
        u = queue.pop(0)
        print(u)
        for v in graph[u]:
            if v not in visited: 
                queue.append(v)
                visited.append(v)

def topological_sort():
    visited = []
    stack = []

    def dfs_visit(u):
        for v in graph[u]:
            if v not in visited:
                # print(v)
                visited.append(v)
                dfs_visit(v)
        stack.append(u)

    for u in graph:
        if u not in visited:
            # print(u)
            dfs_visit(u)

    print(stack[::-1])

# bfs("claire")
topological_sort()

