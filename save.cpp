#include <iostream>
#include <string.h>

using namespace std;

struct node {
    string text;
    struct node * next;
};

struct node * findEnd(node * p) {
    if (p->next == NULL)
        return p;
    else
        return findEnd(p->next);
}

void showList( struct node * p ) {
    if (p != NULL)
        cout << p->text <<endl;
    showList(p->next);
}

struct node * createNode(string text) {
    struct node * root = new node();
    root->text = text;
    root->next = NULL;
    return root;
}

void insert(struct node ** pr, string text) {
    struct node * end = new node();
    struct node * aux = new node();
    end = findEnd(*pr);
    aux->text = text;
    aux->next = NULL;
    end->next = aux;
}

int main() {
    struct node * root = createNode("Test");
    insert(&root, "Yo cuando");
    insert(&root, "Yo cuando 2");
    showList(root);
    return 0;
}
