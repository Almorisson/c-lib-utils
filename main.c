#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void init_list() {
    
}
int main(int argc, char *argv[]) {

    Node *root = NULL;

    root->next->next->next = root->next;

    if (has_loop(root) == 1)
    {
        printf("Linked list has a loop.");
    }

    for (Node* curr = root; curr != NULL; curr = curr->next)
    {
        printf("Value : %d \n Address : %p\n", curr->x, curr);
    }

    // We deallocate the linked List and the end of all operations
    deallocate(&root);

    return 0;
}
