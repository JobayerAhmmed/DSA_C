// push()
// pop()
// top()
// empty()

#include<stdio.h>
#include<stack>

using namespace std;

int main()
{
    stack<int> s;

    s.push(3);
    s.push(5);
    s.push(7);
    s.push(9);
    s.push(1);

    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");

    return 0;
}
