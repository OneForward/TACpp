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
    
    Edge(int v=0, Edge* n=nullptr) :vertex(v), next(n) {}
    
    void insert(int to) { next = new Edge(to, next); }
};

const int MAX = 505;

int main()
{
    Edge graph[MAX]{};
    int indegree[MAX]{}, N, M, a, b, ans = 0;
    queue<int> Q;

    cin >> N >> M;

    while (M--) {
        cin >> a >> b;
        graph[a].insert(b);
        indegree[b]++;
    }

    for (int i=1; i<=N; ++i) if (indegree[i] == 0) Q.push(i);

    while ( Q.size() ) {
        int len = Q.size(); ans++;
        while (len--) {
            auto u = Q.front(); Q.pop();
            
            auto v = graph[u].next;
            while (v) {
                if (--indegree[v->vertex] == 0) Q.push(v->vertex);
                v = v->next;
            }
        }
    }

    cout << ans;
    return 0;
}

