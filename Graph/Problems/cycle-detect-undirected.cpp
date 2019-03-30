#include<stdio.h>
#include<list>

using namespace std;

int V;
list<int> *adj;
int *color, *prev;
bool flag = false;

void dfs(int u)
{
    color[u] = 1;
    printf("%d ", u);

    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;

        if(color[v] == 0) {
            prev[v] = u;
            dfs(v);
        }
        else if(color[v] == 1) {
            flag = true;
            return;
        }
    }

    color[u] = 2;
}

int main()
{
    int e, u, v;

    FILE* f = fopen("cycle-detect-directed.txt", "r");

    fscanf(f, "%d %d", &V, &e);

    adj = new list<int>[V];
    color = new int[V];
    prev = new int[V];

    for(int i = 0; i < e; i++) {
        fscanf(f, "%d %d", &u, &v);
        adj[u].push_back(v);
    }

    for(int i = 0; i < V; i++) {
        color[i] = 0;
        prev[i] = -1;
    }

    for(int i = 0; i < V; i++) {
        if(flag)
            break;

        if(color[i] == 0) {
            dfs(i);
            printf("\n");
        }
    }

    if(flag)
        printf("Cycle\n");
    else
        printf("Not cycle\n");

    fclose(f);

    return 0;
}
