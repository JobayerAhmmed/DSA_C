// Complexity: O(n)
// 10^6 character can be inserted.

#include <stdio.h>
#include <string.h>

struct Node {
    bool endmark;
    Node* next[26];
    Node() {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} *root;

void insert(char* str, int len) {
    Node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new Node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}

bool search(char* str, int len) {
    Node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(Node* curr) {
    for (int i = 0; i < 26; i++)
        if (curr->next[i])
            del(curr->next[i]);
    delete(curr);
}

int main() {
    root = new Node();

    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char str[50];
        scanf("%s", str);
        insert(str, strlen(str));
    }

    int q;
    printf("Enter number of query: ");
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        char str[50];
        scanf("%s", str);
        if (search(str, strlen(str)))
            printf("%s found\n", str);
        else
            printf("%s not found\n", str);
    }

    del(root);

    return 0;
}
