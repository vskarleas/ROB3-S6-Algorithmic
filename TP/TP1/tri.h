#ifndef H_TRI
#define H_TRI

void tri_ins(int* tab, int n);

//Fusionne deux sous-tableaux de tab
//Le premier commence a l'indice deb1 et se termine a l'indice fin1
//Le deuxieme commence a l'indice deb2 = deb1+1 et se termine a l'indice fin2
void fusion(int* tab, int deb1, int fin1, int deb2 , int fin2);

//Trie le sous-tableau de tab qui commence a l'indice deb et se termine a l'indice fin
void tri_fusion_bis(int* tab,int deb,int fin);

void tri_fusion(int* tab, int n);

void tri_enum_bis(int* tab, int n);

void tri_enum_v2(int *tab, int n);

void tri_base_bis(int* tab, int n);

void tri_base(int *tab, int n);

void tri_enum(int *tab, int n);

#endif
