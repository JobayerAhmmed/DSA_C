#include<stdio.h>
#include<limits.h>
#include<list>
using namespace std;

int V;
list<int> *adj;
int *color, *prev, *td, *tf, time;

void dfsvisit(int u)
{
    color[u] = 1;
    time = time + 1;
    td[u] = time;
    printf("%d ", u);

    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;

        if (color[v] == 0) {
            prev[v] = u;
            dfsvisit(v);
        }
    }

    color[u] = 2;
    time = time + 1;
    tf[u] = time;
}

void dfs()
{
    color = new int[V];
    prev = new int[V];
    td = new int[V];
    tf = new int[V];

    for(int u = 0; u < V; u++) {
        color[u] = 0;
        prev[u] = -1;
    }

    time = 0;

    for(int u = 0; u < V; u++) {
        if(color[u] == 0) {
            dfsvisit(u);
            printf("\n");
        }
    }
}

int main()
{
    int e, u, v;

    FILE* f = fopen("2 dfs.txt", "r");

    fscanf(f, "%d %d", &V, &e);
    adj = new list<int>[V];

    for(int i = 0; i < e; i++) {
        fscanf(f, "%d %d", &u, &v);
        adj[u].push_back(v);
    }

    dfs();

    fclose(f);
    delete[] adj;
    delete[] color;
    delete[] prev;
    delete[] td;
    delete[] tf;

    return 0;
}
