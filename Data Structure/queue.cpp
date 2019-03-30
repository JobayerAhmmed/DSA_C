// push()
// pop()
// front()
// empty()

#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(20);
    q.push(15);
    q.push(25);

    while (!q.empty()) {
        printf("%d ", q.front());
        q.pop();
    }
    printf("\n");

    return 0;
}
