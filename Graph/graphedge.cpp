#include<stdio.h>
#include<list>

using namespace std;

int V;
list<int> *adj;
int *color, *prev;

void dfsvisit(int u)
{
    color[u] = 1;

    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;

        if(color[v] == 0) {
            printf("%d %d Tree Edge\n", u, v);
            prev[v] = u;
            dfsvisit(v);
        }
        else if(color[v] == 1) {
            printf("%d %d Back Edge (Cycle)\n", u, v);
        }
        else if(color[v] == 2) {
            bool isForward = false;
            int x = v;
            while(prev[x] != -1) {
                if(prev[x] == u) {
                    isForward = true;
                    break;
                }
                x = prev[x];
            }

            if(isForward)
                printf("%d %d Forward Edge\n", u, v);
            else
                printf("%d %d Cross Edge\n", u, v);
        }
    }

    color[u] = 2;
}


void dfs()
{
    color = new int[V];
    prev = new int[V];

    for(int u = 0; u < V; u++) {
        color[u] = 0;
        prev[u] = -1;
    }

    for(int u = 0; u < V; u++) {
        if(color[u] == 0) {
            prev[u] = -1;
            dfsvisit(u);
        }
    }
}

int main()
{
    int e, u, v;

    FILE* f = fopen("graphedge.txt", "r");

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

    return 0;
}
