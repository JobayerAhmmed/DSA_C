// HackerRank

#include<stdio.h>
#include<string.h>

struct Node {
    bool endmark;
    Node* next[10];
    Node() {
        endmark = false;
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }
} *root;

bool insert(char* str, int len) {
    Node* curr = root;
    bool is_new = false;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        is_new = false;
        if (curr->next[id] == NULL) {
            curr->next[id] = new Node();
            is_new = true;
        }
        curr = curr->next[id];
        if (curr->endmark == true)
            return false;
    }

    curr->endmark = true;

    return is_new;
}

void del(Node* curr) {
    for (int i = 0; i < 10; i++)
        if (curr->next[i])
            del(curr->next[i]);
    delete(curr);
}

int main() {
    int n;
    scanf("%d", &n);

    root = new Node();
    bool is_good = true;
    for (int i = 0; i < n; i++) {
        char str[61];
        scanf("%s", str);
        is_good = insert(str, strlen(str));
        if (is_good == false) {
            printf("BAD SET\n");
            printf("%s\n", str);
            break;
        }
    }

    if (is_good == true)
        printf("GOOD SET\n");

    return 0;
}
