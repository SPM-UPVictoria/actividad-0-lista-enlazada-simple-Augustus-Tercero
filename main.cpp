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
        cout << p->text << endl;
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

void removeNode( struct node * p, string text) {
    struct node * aux = new node();
    if (p->text == text) {
        aux->text = p->text;
        aux->next = NULL;
        delete p;
    } else {
        removeNode(p, text);
    }
}

int main() {
    struct node * root = createNode("Test");
    insert(&root, "Yo cuando");
    insert(&root, "Yo cuando 2");
    insert(&root, "Yo cuando 3");
    showList(root);
    // removeNode(root, "Yo cuando");
    return 0;
}
