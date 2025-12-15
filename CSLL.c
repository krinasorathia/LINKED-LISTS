#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert_begin(struct node *start, int data) {
    struct node *temp, *curr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;

    if (start == NULL) {
        temp->next = temp;
        return temp;
    }

    curr = start;
    while (curr->next != start)
        curr = curr->next;

    temp->next = start;
    curr->next = temp;
    return temp;
}

struct node* insert_end(struct node *start, int data) {
    struct node *temp, *curr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;

    if (start == NULL) {
        temp->next = temp;
        return temp;
    }

    curr = start;
    while (curr->next != start)
        curr = curr->next;

    curr->next = temp;
    temp->next = start;
    return start;
}

struct node* delete_node(struct node *start, int key) {
    struct node *curr = start, *prev = NULL;

    if (start == NULL)
        return NULL;

    if (start->data == key && start->next == start) {
        free(start);
        return NULL;
    }

    if (start->data == key) {
        curr = start;
        while (curr->next != start)
            curr = curr->next;

        curr->next = start->next;
        free(start);
        return curr->next;
    }

    prev = start;
    curr = start->next;

    while (curr != start && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == start) {
        printf("Element not found\n");
        return start;
    }

    prev->next = curr->next;
    free(curr);
    return start;
}

int main() {
    struct node *start = NULL;

    start = insert_begin(start, 10);
    start = insert_end(start, 20);
    start = insert_end(start, 30);
    start = delete_node(start, 20);

    return 0;
}
