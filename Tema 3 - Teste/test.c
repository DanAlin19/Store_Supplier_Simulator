 Queue *q;
                    init_queue(&q);
                    add_queue(q, depozite[k], stare_actuala);
                    while(!is_empty(q)) {
                        int current = front(q);
                        int mask = front_mask(q);
                        pop_queue(q);
                        node *run;
                        run = G.neighbours[current];
                        while (run != NULL) {
                            int add = run->cost;
                            if(matrix_cost[run->val][mask] > matrix_cost[current][mask] + add) {
                                mask += pow(2,run->val);
                                add_queue(q,run->val, mask);
                                matrix_cost[run->val][mask] = matrix_cost[current][mask] + add;
                            }
                            run = run->next;
                        } 
                    }
                    
                    minim = matrix_cost[vector_zone[nr_node_zone - 1]][nr_node_zone * nr_node_zone - 1];
                    printf("\n");
                    free_queue(q);
                    free(q);