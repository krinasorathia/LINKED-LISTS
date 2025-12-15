#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Insert at end
struct node* insert_end(struct node *start, int data) {
    struct node *temp, *curr;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (start == NULL)
        return temp;

    curr = start;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return start;
}

// Display list
void display(struct node *start) {
    struct node *curr = start;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Reverse SLL
struct node* reverse(struct node *start) {
    struct node *prev = NULL, *curr = start, *temp = NULL;

    while (curr != NULL) {
        temp = curr->next;   // store next
        curr->next = prev;   // reverse link
        prev = curr;         // move prev
        curr = temp;         // move curr
    }
    start = prev;
    return start;
}

// -------- Main Program --------
int main() {
    struct node *start = NULL;

    start = insert_end(start, 10);
    start = insert_end(start, 20);
    start = insert_end(start, 30);
    start = insert_end(start, 40);

    printf("Original List:\n");
    display(start);

    start = reverse(start);

    printf("Reversed List:\n");
    display(start);

    return 0;
}
