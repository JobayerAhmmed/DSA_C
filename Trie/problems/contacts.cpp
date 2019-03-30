// HackerRank

#include<stdio.h>
#include<string.h>

struct Node {
    int counter;
    Node* next[26];
    Node() {
        counter = 0;
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
        curr->counter++;
    }
}

int search(char* str, int len) {
    Node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return 0;
        curr = curr->next[id];
    }
    return curr->counter;
}

void del(Node* curr) {
    for (int i = 0; i < 26; i++)
        if (curr->next[i])
            del(curr->next[i]);
    delete(curr);
}

int main() {
    int n;
    scanf("%d", &n);

    root = new Node();
    char command[5], str[22];
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        scanf("%s", str);

        if (strcmp(command, "add") == 0) {
            insert(str, strlen(str));
        }
        else {
            printf("%d\n", search(str, strlen(str)));
        }
    }

    return 0;
}
