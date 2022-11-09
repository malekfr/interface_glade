#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
typedef struct
{
	int j;
	int m;
	int a;
} Date;
typedef struct
{
	int id;
	char nom[20];
	char prenom[20];
	char genre[10];
	Date dn;
	char type[20];
	char appartenance[20];
	char nationalite[20];
	int idbv;
	char mdp[20];
} utilisateur;
int ajouter(char *, utilisateur);
int modifier( char *, int , utilisateur);
int supprimer(char *,int);
utilisateur chercher(char *, int);
int nbobserver(char *);
void trier(char *);
#endif
