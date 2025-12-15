#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Insert at end
struct node* insert_end(struct node *start, int data) {
    struct node *temp, *curr;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    if (start == NULL)
        return temp;

    curr = start;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    temp->prev = curr;

    return start;
}

// Display list (forward)
void display(struct node *start) {
    struct node *curr = start;
    while (curr != NULL) {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Reverse DLL
struct node* reverse(struct node *start) {
struct node *curr = start, *temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;   // move to next node (old next)
    }

    if (temp != NULL)
        start = temp->prev;

    return start;
}

// -------- Main Program --------
int main() {
    struct node *start = NULL;

    start = insert_end(start, 10);
    start = insert_end(start, 20);
    start = insert_end(start, 30);
    start = insert_end(start, 40);

    printf("Original DLL:\n");
    display(start);

    start = reverse(start);

    printf("Reversed DLL:\n");
    display(start);

    return 0;
}
