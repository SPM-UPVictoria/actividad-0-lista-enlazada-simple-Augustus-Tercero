#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct node {
    string text;
    struct node * next;
};

struct node * findEnd(node * p) {
    if (p->next == NULL)
        return p;
    return findEnd(p->next);
}

void showList( struct node * p ) {
    if (p == NULL)
        return;
    else if (p != NULL)
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

void removeNode( struct node *& p, string text) {
    struct node * aux = new node();
    if (p->next != NULL){
        if (p->text == text) {
            aux = p;
            p = p->next;
            delete aux;
        }
        removeNode(p->next,text);
    }
}

void removeLastNode(struct node ** p) {
    struct node * aux = new node();
    struct node * auxLast = new node();
    auxLast = findEnd(*p);
    if ((*p)->next->next == NULL) {
        aux = (*p)->next;
        aux->next = NULL;
        // delete (*p)->next->next;
        delete auxLast;
        return;
    }
    removeLastNode(&(*p)->next);
}

int main() {
    struct node * root = createNode("Test");
    insert(&root, "Yo cuando 1");
    insert(&root, "Yo cuando 2");
    insert(&root, "Yo cuando 3");
    showList(root);
    cout << "\n" << endl;
    removeNode(root, "Test");
    showList(root);
    cout << "\n" << endl;
    removeLastNode(&root);
    showList(root);
    return 0;
}

