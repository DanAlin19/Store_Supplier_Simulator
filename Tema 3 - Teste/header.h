#ifndef HEADER_H_
#define HEADER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct graph {

    int nr_nodes;
    struct node** neighbours;
} graph;

typedef struct node {

    int val;
    float cost;
    struct node* next;
} node;

typedef struct Queue {

	struct nodeQ *head, *tail;
	int len;
} Queue;

typedef struct nodeQ {

	int data;
    int stare_initiala;
	struct nodeQ *next;
} nodeQ;

#define inf 99999999

void initGraph(graph *G, int n);

void insertEdge (graph *G, int x, int val, float costuri);

int getEdge (graph G, int x, int y);

void freeGraph(graph *G);

void Dijkstra(graph *G, int source, float *d, int *viz, int *taticul_lor);

void dfs1(int x, int **matrix, int *s2, int n);

void dfs2(int x, int **matrix, int *p2, int n);

void init_queue (Queue **q);

void free_queue (Queue *q);

void add_queue (Queue *q, int val, int stare_actuala);

void pop_queue(Queue *q);

void print_Queue(Queue *q);

int front (Queue *q);

int front_mask (Queue *q);

int is_empty(Queue *q);

int bit_in_set(int num, int n);

int minimul(int a, int b);

#endif