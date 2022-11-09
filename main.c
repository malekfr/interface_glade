#include <stdio.h>
#include <string.h>
#include "gestionUtilisateurs.h"
int main()
{
	utilisateur U1,U2,U3;
	int x=ajouter("utilisateurs.txt",U1);
	if (x==1)
		printf("\najout de l'utilisateur avec succés");
	else printf("\nechec d'ajout");
	x=modifier("utilisateurs.txt",1,U2);
	if (x==1)
		printf("\nModification de l'utilisateur avec succés");
	else printf("\nechec Modification");
	x=supprimer("utilisateurs.txt",1);
	if (x==1)
		printf("\nSuppression de l'utilisateur avec succés");
	else printf("\nechec Suppression");
	U3=chercher("utilisateurs.txt",3);
	if (U3.id==-1)
		printf("introuvable");
	int y=nbobserver("utilisateurs.txt");
	
	return 0;
}
