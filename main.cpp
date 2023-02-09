#include <iostream>
#include <string.h>

using namespace std;

struct node {
    string text;
    struct node * next;
};

struct node * findEnd(node * p) {
    if (p == NULL)
        return p;
    else
        return findEnd(p->next);
}

void showList( struct node * p ) {
    if (p != NULL)
        cout << p->text <<endl;
    showList(p->next);
}

int main() {
    struct node * root = new struct node();
    struct node * aux = new struct node();
    struct node * aux2 = new struct node();
    struct node * end = new struct node();
    root->text = "Test 1";
    root->next = aux;

    aux->text = "Test 2";
    aux->next = aux2;

    aux2->text = "Test 3";
    aux2->next = NULL;

    showList(root);
    end = findEnd(root);
    cout << end << endl;
    return 0;
}
