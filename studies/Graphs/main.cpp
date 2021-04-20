#include <iostream>
#include <vector>
#include <stack>
#include <queue>

class Graph {
public:
    Graph(int size) :
        size(size) {
            adj.resize(size);
    }
    void insert(int,int);
    void bfs(int s);
    void dfs();
    void dfs_util(int,bool*);
    void topo_sort();
    void dfs_visit(int,bool*);
    void printGraph();
    int countComponents();
private:
    std::vector<std::vector<int>> adj;
    int size;
    std::stack<int> stack;
};

void Graph::insert(int u, int v) {
    adj[u].push_back(v);
}

void Graph::printGraph() {
    for (int u = 0; u < size; u++) {
        std::cout << u;
        for (auto v : adj[u])
            std::cout << "-> " << v;
        std::cout << std::endl;
    }
}

void Graph::dfs() {
    bool *visited = new bool[size];

    for (int i = 0; i < size; i++)
        visited[i] = false;

    for (int u = 0; u < size; u++) {
        if (!visited[u]) {
            visited[u] = true;
            std::cout << u << std::endl;
            dfs_util(u,visited);
        }
    }
}

void Graph::dfs_util(int u, bool visited[]) {
    for (auto v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            std::cout << v << std::endl;
            dfs_util(v, visited);
        }
    }
}

void Graph::topo_sort() {
    bool *visited = new bool[size];

    for (int i = 0; i < size; i++)
        visited[i] = false;

    for (int u = 0; u < size; u++) {
        if (!visited[u]) {
            visited[u] = true;
            dfs_visit(u,visited);
        }
    }

    int x = stack.size();
    for (int i = 0; i < x; i++) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
}

void Graph::dfs_visit(int u,bool *visited) {
    for (auto v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs_visit(v,visited);
        }
    }
    stack.push(u);
}


void Graph::bfs(int s) {
    std::queue<int> queue;
    bool *visited = new bool[size];

    for (int i = 0; i < size; i++)
        visited[i] = false;

    queue.push(s);

    while (!queue.empty()) {
        int x = queue.front();
        queue.pop();

        std::cout << x << std::endl;

        for (int v : adj[x]) {
            if (!visited[v]) {
                visited[v] = true;
                queue.push(v);
            }
        }
    }
}

int Graph::countComponents() {
    int res = 0;

    bool *visited = new bool[size];

    for (int i = 0; i < size; i++)
        visited[i] = false;

    for(int i = 0; i < size; i++) {
        if (!visited[i]) {

            res++;
            visited[i] = true;
            dfs_visit(i,visited);
        }
    }

    return res;
}

main() {
    Graph graph = Graph(5);
    graph.insert(0,1);
    graph.insert(0,4);
    graph.insert(1,4);
    graph.topo_sort();
    std::cout << graph.countComponents();
    /* graph.printGraph(); */
    /* graph.bfs(0); */
    /* graph.dfs(); */
}

