/*
    Topological Sort 拓扑排序
*/

#include <iostream>
#include <queue>

using namespace std;


struct Edge
{
    int vertex;    
    Edge* next;
    
    Edge(int v, Edge* n=nullptr) :vertex(v), next(n) {}
    
    void insert(int to) { next = new Edge(to, next); }
};

Edge** graph;
int N, M, start, a, b;
int* indegree;
int p, ans = 1;
Edge* v;
queue<int> Q;

void init() {
    graph = new Edge*[N+1];
    indegree = new int [N+1]{};
    for (int i=0; i<=N; ++i) graph[i] = new Edge(i);
}

int main()
{
    cin >> N >> M;

    init();

    while (M--) {
        cin >> a >> b;
        graph[a]->insert(b);
        indegree[b]++;
    }



    for (int i=1; i<=N; ++i) if (indegree[i] == 0) Q.push(i);
    Q.push(0); 

    while ( Q.size() > 1 ) {
        p = Q.front(); Q.pop();
        if (p == 0) {
            Q.push(0);
            ans++; continue;
        }
        
        
        v = graph[p]->next;
        while (v) {
            if (--indegree[v->vertex] == 0) Q.push(v->vertex);
            v = v->next;
        }
    }

    cout << ans;
    return 0;
}

