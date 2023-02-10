//
// Created by agust on 09/02/2023.
//

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
    if (p == NULL)
        return;
    else if ( p != NULL ) {
        cout << p->text << endl;
    }
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


struct node * searchNode( struct node * p, string text) {
    if ( p->text == text )
        return p;
    else if (p->next == NULL) {
        cout << "No se encontró" << endl;
    }
    searchNode(p->next,text);
}

int main() {
    struct node * root = createNode("raiz");
    struct node * test = new node();
    insert(&root, "Yo cuando 1");
    insert(&root, "Yo cuando 2");
    insert(&root, "Yo cuando 3");
    showList(root);
    return 0;
}
