#include<stdio.h>
#include<list>

using namespace std;

// low[u] - stores the lowest dt reachable from DFS spanning sub tree of u

int V;
list<int> *adj;
int *color, *prev, *dt, *low;
bool *ap;
int root, rootchild, time;

void dfsvisit(int u)
{
    color[u] = 1;
    dt[u] = low[u] = ++time;

    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;

        if(color[v] == 0) {
            prev[v] = u;

            if(u == root)
                rootchild++;

            dfsvisit(v);
            if(low[v] >= dt[u])
                ap[u] = true;

            if(low[v] > dt[u])
                printf("%d %d - bridge\n", u, v);

            low[u] = min(low[u], low[v]);
        }
        else if(v != prev[u])
            low[u] = min(low[u], dt[v]);
    }

    color[u] = 2;
}

void dfs()
{
    color = new int[V];
    prev = new int[V];
    dt = new int[V];
    low = new int[V];
    ap = new bool[V];

    for(int u = 0; u < V; u++) {
        color[u] = 0;
        prev[u] = -1;
        dt[u] = 0;
        low[u] = 0;
        ap[u] = false;
    }

    time = 0;
    for(int u = 0; u < V; u++) {
        if(color[u] == 0) {
            root = u;
            rootchild = 0;
            dfsvisit(u);
            ap[root] = (rootchild > 1);
        }
    }

    for(int u = 0; u < V; u++) {
        if(ap[u] == true) {
            printf("%d ", u);
        }
    }
}

int main()
{
    int e, u, v;

    FILE* f = fopen("articulationpoints&bridges.txt", "r");

    fscanf(f, "%d %d", &V, &e);

    adj = new list<int>[V];

    for(int i = 0; i < e; i++) {
        fscanf(f, "%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    fclose(f);
    delete[] adj;
    delete[] color;
    delete[] prev;
    delete[] dt;
    delete[] low;
    delete[] ap;

    return 0;
}
