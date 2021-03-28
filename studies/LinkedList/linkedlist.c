#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *next;
}node;

int size(node*);
int empty(node*);
int value_at(node*,int);
node* push_front(node*,int);
node* pop_front(node*);
node* push_back(node*,int);
node* pop_back(node*);
int front(node*);
int back(node*);
node* erase(node*,int);
node* reverse(node*);

main() {
    node *head = NULL;
    head = push_back(head, 1);
    head = push_back(head, 2);
    head = push_back(head, 3);
    /* head = reverse(head); */
    /* head = erase(head, 3); */
    /* head = push_front(head, 0); */
    /* head = pop_back(head); */
    /* head = pop_back(head); */
    /* head = pop_back(head); */
    /* head = pop_back(head); */
    /* printf("front: %d\n", front(head)); */
    /* printf("back: %d\n", back(head)); */
    /* printf("size: %d\n", size(head)); */
    for (; head != NULL; head = head->next)
        printf("%d ", head->item);
    return 0;
}

int size(node *head) {
    int res = 0;
    for (node *temp = head; temp != NULL; temp = temp->next) 
        res++;
    return res;
}

int empty(node *head) {
    return head == NULL;
}

int value_at(node *head, int index) {
    int i = 0;
    node *temp;
    for (temp = head; temp != NULL, 
            i != index; temp = temp->next, i++) {
    }
    if (i == index && temp != NULL)
        return temp->item;
    else
        return -1;
}

node* push_front(node *head, int x) {
    node *new_node = malloc(sizeof(node));

    new_node->next = NULL;
    new_node->item = x;
    
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }

    return head;
}

node* pop_front(node *head) {
    if (head == NULL)
        return NULL;
    return head->next;
}

node* push_back(node *head, int x) {
    node *new_node = malloc(sizeof(node));
    new_node->next = NULL;
    new_node->item = x;

    if (head == NULL) {
        head = new_node;
        return head;
    }

    node *temp = head;
    node *prev = head;

    while (temp != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = new_node;
    return head;
}


node* pop_back(node *head) {
    node *prev = head;
    node *temp = head;
    node *next = head->next;

    if (next == NULL) {
        return NULL;
    }

    while (next != NULL) {
        prev = temp;
        temp = temp->next;
        next = next->next;
    }

    prev->next = NULL;
    return head;
}

int front(node *head) {
    return head == NULL ? -1 : head->item;
}

int back(node *head) {
    if (head == NULL)
        return -1;
    node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;
    return temp->item;
}

node* erase(node *head, int x) {
    if (head == NULL)
        return head;

    if (head->item == x) {
        head = head->next;
        return head;
    }
    
    node *prev = head;
    node *temp = head;

    while (temp != NULL) {
        if (temp->item == x)
            prev->next = temp->next;
        prev = temp;
        temp = temp->next;
    }

    return head;
}

node* reverse(node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    node *curr = head;
    node *prev = head;
    node *next = head->next;
    head->next = NULL;

    while (next != NULL) {
        curr = next;
        next = next->next;
        curr->next = prev;
        prev = curr;
    }

    head = prev;

    return head;
}
