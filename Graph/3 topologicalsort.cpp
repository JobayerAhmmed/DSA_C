#include<stdio.h>
#include<limits.h>
#include<list>

using namespace std;

int V;
list<int> *adj;
int *color, *tf, time;
list<int> sortedlist;

void dfsvisit(int u)
{
    color[u] = 1;
    time = time + 1;

    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;

        if(color[v] == 0) {
            dfsvisit(v);
        }
    }

    color[u] = 2;
    time = time + 1;
    tf[u] = time;
    sortedlist.push_front(u);
}

void topologicalsort()
{
    color = new int[V];
    tf = new int[V];

    for(int u = 0; u < V; u++) {
        color[u] = 0;
    }

    time = 0;
    for(int u = 0; u < V; u++) {
        if(color[u] == 0) {
            dfsvisit(u);
        }
    }

    list<int>::iterator i;
    for(i = sortedlist.begin(); i != sortedlist.end(); i++) {
        printf("%d ", *i);
    }
    printf("\n");
}

int main()
{
    int e, u, v;

    FILE* f = fopen("3 topologicalsort.txt", "r");

    fscanf(f, "%d %d", &V, &e);
    adj = new list<int>[V];

    for(int i = 0; i < e; i++) {
        fscanf(f, "%d %d", &u, &v);
        adj[u].push_back(v);
    }

    topologicalsort();

    fclose(f);
    delete[] adj;
    delete[] color;
    delete[] tf;

    return 0;
}
