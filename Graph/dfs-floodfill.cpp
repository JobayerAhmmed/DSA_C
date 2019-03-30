#include<stdio.h>
#include<limits.h>
#include<list>
using namespace std;

int V;
list<int> *adj;
int *color, *prev, *dist;

void dfs(int u, int clr)
{
    color[u] = clr;
    printf("%d ", u);

    list<int>::iterator v;
    for(v = adj[u].begin(); v != adj[u].end(); v++) {
        if (color[*v] == 0) {
            prev[*v] = u;
            dist[*v] = dist[u] + 1;
            dfs(*v, clr);
        }
    }

//    color[u] = 2;
}

int main()
{
    int e, u, v, clr;

    FILE* f = fopen("dfs-floodfill.txt", "r");

    fscanf(f, "%d %d", &V, &e);
    adj = new list<int>[V];

    for(int i = 0; i < e; i++) {
        fscanf(f, "%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    color = new int[V];
    prev = new int[V];
    dist = new int[V];

    for(int i = 0; i < V; i++) {
        color[i] = 0;
        prev[i] = -1;
        dist[i] = INT_MAX;
    }

    clr = 0;
    for(int i = 0; i < V; i++) {
        if(color[i] == 0) {
            printf("Vertex ");
            dist[i] = 0;
            dfs(i, ++clr);
            printf(" have color %d\n", clr);
        }
    }

    fclose(f);
    delete[] adj;
    delete[] color;
    delete[] prev;
    delete[] dist;

    return 0;
}

