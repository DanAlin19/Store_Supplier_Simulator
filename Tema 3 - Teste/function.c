#include "header.h"

void initGraph(graph *G, int n) {

    G->nr_nodes = n;
    G->neighbours = (node**)malloc(G->nr_nodes * sizeof (node*));
    for(int i = 0; i < G->nr_nodes; i++) 
      G->neighbours[i] = NULL;
    
} 

void insertEdge (graph *G, int x, int val, float costuri) {

    node *new_node = (node*)malloc(sizeof(node));
    new_node->val = val;
    new_node->cost = costuri;
    new_node->next = G->neighbours[x];
    G->neighbours[x] = new_node;
}

int getEdge (graph G, int x, int y) {

    node *p;
    for ( p = G.neighbours[x]; p != NULL; p = p->next) 
        if(y == p->val) 
          return 1;
    return 0;
}

void freeGraph(graph *G) {

    node *run;
    for(int i = 0; i < G->nr_nodes; i++) {
        run = G->neighbours[i];
        while(run != NULL) {
            G->neighbours[i] = G->neighbours[i]->next;
            free(run);
            run = G->neighbours[i];
        }
    }
    free(G->neighbours);
}

void Dijkstra(graph *G, int source, float *d, int *viz, int *taticul_lor) {

  for(int i = 0; i < G->nr_nodes; i++) {
    d[i] = inf;
    viz[i] = -1;
  }
  d[source] = 0;
  for(int i = 0; i < G->nr_nodes; i++) {
    int min = i;
    int dmin = inf; 
    for(int j = 0; j < G->nr_nodes; j++) 
      if(d[j] < dmin && viz[j] == -1) {
        min = j;
        dmin = d[j];
      }
    viz[min] = 1;
    node *run;
    run = G->neighbours[min];
    while (run != NULL) {
      if( d[min] + run->cost < d[run->val]) {
        d[run->val] = d[min] + run->cost;
        taticul_lor[run->val] = min;
      }
      run = run->next;
    } 
  }
}

void dfs1(int x, int **matrix, int *s2, int n) {

    s2[x] = 1;
    for(int i = 0; i < n; i++) 
        if(s2[i] == 0 && matrix[x][i] == 1)
            dfs1(i,matrix,s2,n);
}

void dfs2(int x, int **matrix, int *p2, int n) {

    p2[x] = 1;
    for(int i = 0; i < n; i++) 
        if(p2[i] == 0 && matrix[i][x] == 1)
            dfs2(i,matrix,p2,n);
}

void init_queue (Queue **q) {

	(*q) = (Queue *)malloc(sizeof(Queue));
	(*q)->head = (*q)->tail = NULL;
	(*q)->len = 0;
}

void free_queue (Queue *q) {

	nodeQ* urmatorul;
	urmatorul = q->head;
	while(q->head != NULL) {
		urmatorul = q->head;
		q->head = q->head->next;
    free(urmatorul);
	}
	q->len = 0;
}

void add_queue (Queue *q, int val, int stare_actuala) {

	nodeQ* new_node = (nodeQ *)malloc(sizeof(nodeQ));
  if(new_node == NULL) 
    return;

  if(q->len != 0) {

    new_node->next = NULL;
    q->tail->next = new_node;
    q->tail = new_node;
    new_node->stare_initiala = stare_actuala;
    new_node->data = val;
    q->len += 1;
  }
  else {

    new_node->data = val;
    new_node->stare_initiala = stare_actuala;
    new_node->next = NULL;
    q->head = new_node;
    q->tail = new_node;
    q->len += 1;
  }
}

void pop_queue(Queue *q) {

	q->len -= 1;
	nodeQ* delete;
	delete = q->head;
	q->head = q->head->next;
  free(delete);
	
}

void print_Queue(Queue *q) {

	nodeQ* run;
	run = q->head;
	while(run != NULL) {
		printf("%d ",run->data);
		run = run->next;
	}
  
}

int front (Queue *q) {

	return q->head->data;
}

int front_mask (Queue *q) {

	return q->head->stare_initiala;
}

int is_empty(Queue *q) {

	if(q->len == 0)
		return 1;
	return 0;
}

int bit_in_set(int num, int n) {

  if(num & (1 << n))
    return 1;
  else
    return 0;
}

int minimul(int a, int b) {

      if( a < b )
        return a;
      else  
        return b;
}