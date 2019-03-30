#include<stdio.h>
#include<limits.h>
#include<list>
#include<queue>

using namespace std;

int V;
list<int> *adj;
int *color, *prev, *dist;

void bfs(int s)
{
    color = new int[V];
    prev = new int[V];
    dist = new int[V];

    for(int i = 0; i < V; i++) {
        color[i] = 0;
        prev[i] = -1;
        dist[i] = INT_MAX;
    }

    color[s] = 1;
    prev[s] = -1;
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        printf("%d ", u);

        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = *i;

            if (color[v] == 0) {
                color[v] = 1;
                prev[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        color[u] = 2;
    }
}

void printpath(int s, int v)
{
    if (v == s)
        printf("%d ", s);
    else if (prev[v] == -1)
        printf("No path from %d to %d", s, v);
    else {
        printpath(s, prev[v]);
        printf("%d ", v);
    }
}

int main()
{
    int e, u, v, s;

    FILE* f = fopen("1 bfs.txt", "r");

    fscanf(f, "%d %d", &V, &e);
    adj = new list<int>[V];

    for (int i = 0; i < e; i++) {
        fscanf(f, "%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fscanf(f, "%d", &s);

    bfs(s);
    printf("\n");

    printpath(s, 3);

    delete[] color;
    delete[] prev;
    delete[] dist;
    delete[] adj;

    return 0;
}
