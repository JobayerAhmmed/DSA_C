#include<stdio.h>
#include<list>
#include<stack>
using namespace std;

int V;
list<int> *adj, *adjT;
int *color, *colorT;
stack<int> dfsstack;

void dfs(int u)
{
    color[u] = 1;

    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;
        if(color[v] == 0)
            dfs(v);
    }

    color[u] = 2;
    dfsstack.push(u);
}

void dfsT(int u)
{
    colorT[u] = 1;
    printf("%d ", u);

    list<int>::iterator i;
    for(i = adjT[u].begin(); i != adjT[u].end(); i++) {
        int v = *i;
        if(colorT[v] == 0)
            dfsT(v);
    }

    colorT[u] = 2;
}

void stronglyconnectedcomponents()
{
    color = new int[V];
    colorT = new int[V];

    for(int u = 0; u < V; u++) {
        color[u] = 0;
        colorT[u] = 0;
    }

    // call dfs
    for(int u = 0; u < V; u++) {
        if(color[u] == 0) {
            dfs(u);
        }
    }

    // compute G^T
    for(int u = 0; u < V; u++) {
        list<int>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = *i;
            adjT[v].push_back(u);
        }
    }

    // call dfs(G^T) according to stack
    while(!dfsstack.empty()) {
        int u = dfsstack.top();
        dfsstack.pop();

        if(colorT[u] == 0) {
            dfsT(u);
            printf("\n");
        }
    }
}

int main()
{
    int e, u, v;

    FILE* f = fopen("stronglyconnectedcomponents.txt", "r");

    fscanf(f, "%d %d", &V, &e);

    adj = new list<int>[V];
    adjT = new list<int>[V];

    for(int i = 0; i < e; i++) {
        fscanf(f, "%d %d", &u, &v);
        adj[u].push_back(v);
    }

    stronglyconnectedcomponents();

    fclose(f);
    delete[] adj;
    delete[] adjT;
    delete[] color;
    delete[] colorT;

    return 0;
}
