#include "header.h"

int main() {

    graph G;
    int n, m, d, u, v;
    float w;
    // citesc numarul de noduri, numarul de arce si numarul de depozite
    scanf("%d %d %d", &n, &m, &d);
    initGraph(&G , n);

    int *depozite = (int *)malloc(d * sizeof(int));
    int *ctc = (int *)calloc(n, sizeof(int));
    int *s2 = (int *)calloc(n, sizeof(int));
    int *p2 = (int *)calloc(n, sizeof(int));

    // alocam dinamic matricea de adiacenta pentru ctc
    int **matrix = (int **)calloc(n, sizeof(int *));
    for(int i = 0; i < n; i++)
        matrix[i] = (int *)calloc(n, sizeof(int));

    for(int i = 0; i < m; i++) {
        //citim ID-urile nodurilor si w costul parcurgerii
        scanf("%d %d %f", &u, &v, &w);
        insertEdge(&G, u, v, w);
        // adaug si in matricea de adiacenta valoarea 1 pentru toate legaturile
        matrix[u][v] = 1;
    }

    for(int i = 0; i < d; i++) {
        // citesc depozitele din grafic
        scanf("%d",&depozite[i]);
        for(int k = 0; k < n; k++) {
                // fac pe linie si pe coloana depozitelor 0 pentru ctc
                matrix[depozite[i]][k] = 0;
                matrix[k][depozite[i]] = 0;
            }
    }

    // citesc numarul de cerinte
    int numar_cerinte;
    scanf("%d",&numar_cerinte);

    char *cerinta = (char *)malloc(3 * sizeof(char));
    for( int i = 0; i < numar_cerinte; i++) {
        // citesc cerinta
        scanf("%s",cerinta);
        // pentru cerinta 1 ("e1")
        if(strstr(cerinta,"e1") != 0) {
            int s;
            // s este depozitul din care se incarca marfa
            scanf("%d", &s);
            int nr_mag_aprov;
            // se citeste numarul de magazine care vor fi aprovizionate
            scanf("%d", &nr_mag_aprov);
            int destinatar;
            float *d = (float *)malloc(n * sizeof(float));
            int *viz = (int *)malloc(n * sizeof(int));
            int *final1 = (int *)malloc(n * sizeof(int));
            int *final2 = (int *)malloc(n * sizeof(int));
            float suma = 0;
            for(int j = 0; j < nr_mag_aprov; j++) {
                // se citesc ID-urile magazinelor care vor fi alimentate in ordine crescatoare
                scanf("%d", &destinatar);
                int *taticul1 = (int *)malloc(n * sizeof(int));
                // aplicam dijkstra de la depozit in restul nodurilor
                Dijkstra(&G,s,d,viz,taticul1);
                // afisez ID-ul magazinului care va fi alimentat
                printf("%d\n", destinatar);
                // afisez costul drumului de la depozit la destinatar
                printf("%0.1f ", d[destinatar]);
                int cautare1 = destinatar;
                int cnt1 = 0;
                final1[cnt1] = cautare1;
                // pun in vectorul final1 drumul de la depozit la destinatar
                while(cautare1 != s) {
                    cautare1 = taticul1[cautare1];
                    cnt1++;
                    final1[cnt1] = cautare1;
                }
                free(taticul1);
                int *taticul2 = (int *)malloc(n * sizeof(int));
                suma += d[destinatar];
                // aplicam dijktra de la destinatar in restul nodurilor
                Dijkstra(&G,destinatar,d,viz,taticul2);
                // aici afisez costul drumului de la destinatar la depozit
                printf("%0.1f\n", d[s]);
                int cautare2 = s;
                int cnt2 = 0;
                final2[cnt2] = cautare2;
                // pun in vectorul final2 drumul de la destinatar la depozit
                while(cautare2 != destinatar) {
                    cautare2 = taticul2[cautare2];
                    cnt2++;
                    final2[cnt2] = cautare2;
                }
                // afisez drumul de la depozit la destinatar
                for(int p = cnt1; p >= 0; p--)
                    printf("%d ",final1[p]);
                // afisez suma de la destinatar la depozit
                for(int p = cnt2 - 1; p > 0; p--)
                    printf("%d ",final2[p]);
                printf("%d",final2[0]);   
                printf("\n");
                free(taticul2);
                suma += d[s];
                
            }   
            // eliberare memorie
            free(final1);
            free(final2);
            free(d);
            free(viz);
            // afisez suma totala a parcurgerilor
            printf("%0.1f", suma);
        }
        if(i != numar_cerinte - 1)
            printf("\n");
        // pentru cerinta 2 "e2"
        if(strstr(cerinta,"e2") != 0) {
            
            int contorizare = 0, nrc = 0;  
            // am aplicat Algoritmul Plus-Minus
            for(int i = 0; i < n; i++) 
                if(ctc[i] == 0) {
                    for(int j = 0; j < n; j++)
                        s2[j] = p2[j] = 0;
                    nrc++;
                    dfs1(i,matrix,s2,n);
                    dfs2(i,matrix,p2,n);
                    for(int j = 0; j < n; j++)
                        if(s2[j] == 1 && p2[j] == 1)
                            ctc[j] = nrc;
                }
            int x = 0;
            // afisare 
            printf("%d\n", nrc - d);
            for(int i = 0; i < d; i++)
                ctc[depozite[i]] = 0;
            while(contorizare !=  nrc - d - 1) {
                for(int i = 0; i < n; i++) 
                    if(ctc[i] > x) {
                        x = ctc[i];
                        break;
                    }
                for(int i = 0; i < n; i++)
                    if(ctc[i] == x) {
                        printf("%d", i);
                        ctc[i] = 0;
                        break;
                    }
                for(int i = 0; i < n; i++)
                    if(ctc[i] == x) {
                        printf(" %d", i);
                        ctc[i] = 0;
                    }
                printf("\n");
                contorizare++;
            }
            for(int i = 0; i < n; i++) 
                    if(ctc[i] > x) {
                        x = ctc[i];
                        break;
                    }

            for(int i = 0; i < n; i++)
                    if(ctc[i] == x) {
                        printf("%d", i);
                        ctc[i] = 0;
                        break;
                    }
                for(int i = 0; i < n; i++)
                    if(ctc[i] == x) {
                        printf(" %d", i);
                        ctc[i] = 0;
                    }
        }

        // pentru cerinta 3 "e3"
        if(strstr(cerinta,"e3") != 0) {
            int r, nr_node_zone;

            // citim numarul de zone
            scanf("%d", &r);
            for(int j = 0; j < r; j++) {
                // citim numarul de elemente din zona
                scanf("%d", &nr_node_zone);
                int *vector_zone = (int *)malloc(nr_node_zone * sizeof(int));
                int stare_finala = 0;
                // citesc elementele din zona si le stochez in vectorul "vector_zone"
                for(int k = 0; k < nr_node_zone; k++) {
                    scanf("%d", &vector_zone[k]);
                    // calculez starea finala din maska de biti
                    stare_finala += (int)pow(2, vector_zone[k]);
                }
                // alocam matricea de costuri
                float **matrix_cost = (float **)malloc(n * sizeof(float *));
                for(int i = 0; i < n; i++)
                    matrix_cost[i] = (float *)malloc(((int)pow(2, n) + 1)* sizeof(float));

                float raspuns = inf;
                // parcurgere pentru fiecare depozit
                for(int k = 0; k < d; k++) {
                    
                    // o facem infinti pe toata
                    for(int i = 0; i < n; i++)
                    for(int j = 0; j <= (int)pow(2, n); j++)
                        matrix_cost[i][j] = inf;

                    float minim = inf;
                    stare_finala += (int)pow(2, depozite[k]);
                    int stare_actuala = 0;
                    stare_actuala += (int)pow(2, depozite[k]);
                    // initializez coada 
                    Queue *q;
                    init_queue(&q);
                    matrix_cost[depozite[k]][stare_actuala] = 0;
                    // adaug in coada fiecare depozit pe rand
                    add_queue(q, depozite[k], stare_actuala);
                    while(!is_empty(q)) {
                        
                        int nodul = front(q);
                        int mask = front_mask(q);
                        node *run = G.neighbours[nodul];
                        while(run != NULL) {
                            // caut sa vad daca este printre componentele zonei sau daca este depozitul
                            for(int i = 0; i < nr_node_zone; i++)
                                if(run->val == vector_zone[i] || run->val == depozite[k]) {
                                    // daca in masca nu se afla bitul 1 pe nodul respectiv
                                    if(bit_in_set(mask,run->val) == 0 &&
                                     matrix_cost[run->val][mask + (int)pow(2,run->val)] > matrix_cost[nodul][mask] + run->cost) {
                                        
                                        add_queue(q,run->val, mask + (int)pow(2,run->val));
                                        matrix_cost[run->val][mask + (int)pow(2,run->val)] = matrix_cost[nodul][mask] + run->cost;
                                        break;
                                    }
                                    // daca in masca nu se afla bitul 0 pe nodul respectiv
                                    if(bit_in_set(mask,run->val) == 1 &&
                                     matrix_cost[run->val][mask] > matrix_cost[nodul][mask] + run->cost) {
                                        
                                        add_queue(q,run->val, mask);
                                        matrix_cost[run->val][mask] = matrix_cost[nodul][mask] + run->cost;
                                        break;
                                    }
                                    
                                }
                            run = run->next;
                        }
                        pop_queue(q);
                    }
                    
                    minim = matrix_cost[depozite[k]][stare_finala];
                    // calculez minimul drumurilor cu depozitul x
                    if(minim < raspuns)
                        raspuns = minim;
                    stare_finala -= (int)pow(2, depozite[k]);
                    
                    free_queue(q);
                    free(q);
                } 
                if(j != r - 1) {
                    printf("%0.1f\n", raspuns);
                }
                else
                    printf("%0.1f", raspuns);

                // eliberez memoria
                for(int i = 0; i < n; i++)
                    free(matrix_cost[i]);
                free(matrix_cost);   
                free(vector_zone);
            }
        } 
    }
    // eliberare de memorie
    freeGraph(&G);
    free(depozite);
    free(s2);
    free(p2);
    for(int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
    free(ctc);
    free(cerinta);
    return 0;
}   