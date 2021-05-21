/*
    DFS求从某一顶点出发到长度为指定长度的简单路径的数目
*/

#include <iostream>
using namespace std;

struct Edge
{
    int vertex;    
    Edge* next;
    
    Edge(int v, Edge* n=nullptr) :vertex(v), next(n) {}
    
    void insert(int to) { next = new Edge(to, next); }
};

Edge** graph;
bool* visited;
int ans = 0;
int N, M, start, targetLength, a, b;

void init() {
    graph = new Edge*[N+1];
    visited  = new bool[N+1]{};
    for (int i=0; i<=N; ++i) graph[i] = new Edge(i);
}

void dfs(int u, int len) {
    if (len == targetLength) { ans++; return; }

    auto v = graph[u]->next;
    visited[u] = true; 
    while (v) {
        if (! visited[v->vertex] ) dfs(v->vertex, len+1);
        v = v->next;
    }
    visited[u] = false;
}


int main()
{
    cin >> N >> M >> start >> targetLength;

    init();

    while (M--) {
        cin >> a >> b;
        graph[a]->insert(b);
    }

    dfs(start, 0);

    cout << ans;
    return 0;
}
