#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

/* Structures */
typedef struct Node {
    int x;
    struct Node* next;
} Node;

/* Lib functions */
int         main(int , char**);
void		my_putchar(char);
void		my_putstr(char*);
int			my_strlen(char*);
int 		my_strcmp(char*, char*);
void		my_put_nbr(int);

/* Project's functions */
void        insert_beginning(Node**, int);
void        insert_after_node(Node*, int);
void        deallocate(Node**);

#endif
