#include <stdio.h>
#include <limits.h>

//EXO3.1 trier les taches en ordre croissant des deb[j];
// tri par insertion
void tri_taches_exo3(int* deb, int* fin, int nbTaches)
{
	int c_deb ;
    int c_fin ;
    int i;
    int j;
    for(i=1; i < nbTaches; i++){
        c_deb = deb[i];
        c_fin = fin[i];
        j = i-1;
        while( j>= 0 && deb[j] < c_deb){
            deb[j+1] = deb[j];
            fin[j+1] = fin[j];
            j=j-1;
        } 
        deb[j+1] = c_deb;
        fin[j+1] = c_fin;
    }
}

int glouton(int* deb, int* fin, int nbTaches) 
{
	int dispo[nbTaches];
	dispo[0] = 0; // initialiser la date de dispo de la machine 0  a 0 
	int p = 0; 
	int j;
	int i = 0;
	for(j = 1 ; j < nbTaches ; j++ ) // si la machine i est disponible pour la tache j 
	{
		for(i=0; i < nbTaches ; i++) // parcourir le tableau des machines dispo et voir si il y a une machine disponible sinon ajouter une nouvelle 
		{
			if(deb[j] >= dispo[i])
			{
				dispo[i] = fin[j];
			} 
			else
			{
				// ajouter une nouvelle machine ;
				dispo[p+1] = fin[j];
				p=p+1;
			}
		}
	}

	return p;
}

int main(){
    int d[]={1,3,4,5,9,10};
    int f[] = {2,8,5,7,11,12};
    
    tri_taches_exo3(d,f,6);
    printf("le nombre de machines est test \n");
    int res = glouton(d,f,6);
    printf("le nombre de machines est : %d \n",res);
    return 0;
}