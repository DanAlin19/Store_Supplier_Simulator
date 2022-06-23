                                Tema 3 Structuri de Date
                                                Dan Alin-Constantin 311CC

    Citesc de la tastatura numerele naturale n, m, d ce reprezinta numarul de 
noduri, numarul de arce si numarul de depozite din graf. Apoi m linii citesc
ID-urile nodurilor si w costul de la un nod la altul. Dupa o sa citesc "d"
depozite, citesc numarul de cerinte. In final citesc task-ul.

    Task-ul 1. 
    Citesc de la tastura depozitul din care se incarca marfa, numarul de
magazine din care se va aproviziona depozitul si apoi magazinele aprovizionate
Aplic Dijkstra de la depozit la restul nodurilor din grafic. Afisez ID-ul 
magazinului care va fi alimentat si costul drumului de la depozit la 
destinatar apoi pun in vector final1 drumul de cost minim de la depozit la 
magazin si adaug in suma tote costurile din parcurgerea mea. Apoi aplic 
Dijkstra de la destinatar la restul nodurilor. Afisez costul drumului de la 
magazinul alimentat la depozit. Pun in vectorul final2 drumul de la 
destinatar la depozit. Apoi afisez cei doi vectori pe rand doar ca la final2
sar peste primul element.

    Task-ul 2.
    Am aplicat algoritmul Plus-Minus pentru a gasi componentele conexe dupa
ce am eliminat toate legaturile depozitelor de magazine. Pentru fiecare nod
x al grafului care nu a fost plasat inca intr-o componenta tare conexa 
determinam toate nodurile in care se poate ajunge din nodul x, folosindu-ne 
de graful G si le marcam intr-o matrice de adiacenta, apoi mai construim o 
matrice de adiacenta doar ca cu graful transpus. nodurile care sutn marcate
si intr-o matrice si in cealalta reprezinta o componenta conexa. Componentele 
conexe sunt notate in in vectorul ctc. Afisez fiecare componenta conexa pe 
cate un rand.

    Task-ul 3
    Citesc numarul de zone. Apoi citesc r numar de noduri si cele nr_node_zone
elemente pe care le stochez in vectorul "vector zone". Calculez starea finala 
si aloc o matrice de costuri. Apoi parcurg fiecare depozit pe rand. Matricea
de costuri o sa aiba toate elementele infinit. Initializez coada si adaug
depozitul in coada. Caut sa vad daca vecinul nodului este printre componentele
zonei sau daca este depozitul. Daca in masca nu se afla bitul 1 pe nodul
respectiv incrementez masca si updatez matricea de costuri. Daca in masca nu
se afla bitul 0 pe nodul respectiv updatez matricea de costuri. la final minim
se afla pe matrix_cost[depozite[k]][stare_finala]. Calculez minimul drumurilor
din fiecare depozit si eliberez memoria
