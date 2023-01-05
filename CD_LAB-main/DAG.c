#include<stdio.h>
#include<stdlib.h>
int c = 0;
struct adj_list {
    int dest;
    struct adj_list *next;
}*np = NULL, *np1 = NULL, *p = NULL, *q = NULL;
struct Graph {
    int v;
    struct adj_list *ptr;
} array[6];
void addReverseEdge(int src, int dest) {
    np1 = malloc(sizeof(struct adj_list));
    np1->dest = src;
    np1->next = NULL;
    if (array[dest].ptr == NULL) {
        array[dest].ptr = np1;
        q = array[dest].ptr;
        q->next = NULL;
    } else {
        q = array[dest].ptr;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = np1;
    }
}
void addEdge(int src, int dest) {
    np = malloc(sizeof(struct adj_list));
    np->dest = dest;
    np->next = NULL;
    if (array[src].ptr == NULL) {
        array[src].ptr = np;
        p = array[src].ptr;
        p->next = NULL;
    } else {
        p = array[src].ptr;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = np;
    }
    //addReverseEdge(src, dest);
}
void print_graph(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Adjacency List of %d: ", array[i].v);
        while (array[i].ptr != NULL) {
            printf("%d ", (array[i].ptr)->dest);
            array[i].ptr = (array[i].ptr)->next;
        }
        printf("\n");
    }
}
int checkDAG(int n) {
    int count = 0;
    int size = n - 1, i, j;
    for (i = 0; i < n; i++) {
        if (count == size) {
            return 1;
        }
        if (array[i].ptr == NULL) {
            count++;
            for (j = 0; j < n; j++) {
 
                while (array[j].ptr != NULL) {
                    if ((array[j].ptr)->dest == (array[i].ptr)->dest) {
                        (array[j].ptr)->dest = -1;
                    }
                    array[i].ptr = (array[i].ptr)->next;
                }
            }
 
        }
    }
    return 0;
}
int main() {
    int n = 6, i;
    printf("Number of vertices: %d\n", n);
 
    for (i = 0; i < n; i++) {
        array[i].v = i;
        array[i].ptr = NULL;
    }
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 3);
    addEdge(5, 2);
    print_graph(n);
    printf("The given graph is 'Directed Acyclic Graph' :");
    if (checkDAG(n) == 1)
        printf(" True");
    else
        printf(" False");
}