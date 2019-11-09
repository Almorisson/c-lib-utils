#include<stdlib.h>
#include<stdio.h>

#include "header.h"

/**
 * Function `insert_end` allow to insert a new node at the end of a Linked list
*/
void insert_end(Node **root, int value)
{
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->x = value;

    Node *curr = *root;
    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    // Iterate through over the list to the get the end where Node is normally empty
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_node; // Insert a new Node in the Linked List
}
/**
 * Function `insert_beginning` allow to insert a new node at the beginning of a Linked list
*/
void insert_beginning(Node **root, int value)
{

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }

    new_node->x = value;
    new_node->next = *root;

    *root = new_node;
}
/**
 * Function `insert_after_node` allow to insert a new node after a specified node in a Linked list
*/
void insert_after_node(Node *node, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }

    new_node->x = value;
    new_node->next = node->next; // Can be NULL if it's the last element
    node->next = new_node;
}
/**
 * Function `insert_sorted_ll` allow to insert a new node in a sorted Linked list and keep it sorted after insertion
*/
void insert_sorted_ll(Node **root, int value) {
    if(*root == NULL || (**root).x >= value) {
        insert_beginning(root, value);
        return;
    }

    Node *curr = *root;
    while (curr->next != NULL)
    {
        if (curr->next->x >= value)
        {
           break;;
        }
        curr = curr->next;

    }

    insert_after_node(curr, value);
}
/**
 * Function `delete_node` allow to delete a specific node in a Linked list
*/
void delete_node(Node **root, Node *node) {
    if(*root == NULL) {
        exit(-1);
    }

    if ((**root).x == node->x)
    {
        Node *node_to_remove = *root;
        *root = (*root)->next;
        free(node_to_remove);
        return;
    }

    for (Node *curr = *root; curr->next != NULL; curr = curr->next)
    {
        if (curr->next->x == node->x) {
            Node *node_to_remove = curr->next;
            curr->next = curr->next->next;
            free(node_to_remove);
            return;
        }
    }
}
/**
 * Function `reverse_ll` allow to reverse a Linked list
 * The `tail` become the `head` and the `head` become the `tail`
*/
void reverse_ll(Node **root)
{
    Node *prev = NULL;
    Node *curr = *root;

    while (curr != NULL)
    {
        Node *next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *root = prev;
}
/**
 * Function `has_loop` allow to detect if a Linked list has a cycle loop or not
*/
int has_loop(Node *root) {
    Node *slow = root;
    Node *fast = root;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return -1;
}
/**
 * Function `count_elems` allow to count the number of elements in a Linked list
*/
int count_elems(Node *root)
{
    int counter = 0;

    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        counter++;
    }

    return counter;
}
/**
 * Function `count_elems_recursive` allow to count the number of elements in a Linked list recursively
*/
int count_elems_recursive(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    return 1 + count_elems_recursive(root->next);
}
/**
 * Function `deallocate` allow to free a whole Linked list passed in parameter
*/
void deallocate(Node **root)
{
    Node *curr, *aux;
    curr = *root;
    while (curr->next != NULL)
    {
        aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

int main(int argc, char *argv[]) {

    Node *root = NULL;

    insert_end(&root, 0);
    insert_end(&root, 1);
    insert_end(&root, 2);
    insert_end(&root, 3);
    //reverse_ll(&root);
    root->next->next->next = root;

    if (has_loop(root) == 1)
    {
        printf("Linked list has a loop.");
    }

    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        printf("Value : %d \n Address : %p\n", curr->x, curr);
    }
    printf("Linked list has %d elements.\n", count_elems(root));
    printf("Linked list has %d elements.", count_elems_recursive(root));
    // We deallocate the linked List and the end of all operations
    deallocate(&root);

    return 0;
}
