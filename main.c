#include <stdio.h>
#include <string.h>
#include"gestionbv.h"

int main()
{
GBV A1,A2;
int x=ajouter("GBV.txt", A1);
    if(x==1)
        printf("ajout avec succés");
    else 
        printf("echec  d'ajout");
 x=modifier("GBV.txt",1117,A2 );                 

    if(x==1)
        printf("Modification avec succés");
    else 
        printf("echec de Modification");
x=supprimer("GBV.txt",1117 );
    if(x==1)
        printf("Suppressio avec succés");
    else 
        printf("echec de Suppression");
return 0;
}
