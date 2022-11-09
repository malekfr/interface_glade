#include <stdio.h>
#include <string.h>
#include "gestionUtilisateurs.h"
int ajouter(char * filename, utilisateur U)
{	FILE * f=fopen(filename, "a");
	if (f!=NULL)
	{
		fprintf(f,"%d %s %s %s %Date %s %s %s %d %s\n",U.id,U.nom,U.prenom,U.genre,U.dn,U.type,U.appartenance,U.nationalite,U.idbv,U.mdp);
		fclose(f);
		return 1;
	}
	else return 0;
}
int modifier(char * filename, int id, utilisateur nouv)
{ 	int tr;
	utilisateur U;
	FILE * f=fopen(filename, "r");
	FILE * f2=fopen("nouv.txt","w");
	if (f!=NULL && f2!=NULL)
	{
		while (fscanf(f,"%d %s %s %s %Date %s %s %s %d %s\n",&U.id,U.nom,U.prenom,U.genre,U.dn,U.type,U.appartenance,U.nationalite,&U.idbv,U.mdp)!=EOF)
		{
			if (U.id==id)
			{
				fprintf(f2,"%d %s %s %s %Date %s %s %s %d %s\n",nouv.id,nouv.nom,nouv.prenom,nouv.genre,nouv.dn,nouv.type,nouv.appartenance,nouv.nationalite,nouv.idbv,nouv.mdp);
				tr=1;
			}
		else
			fprintf(f2,"%d %s %s %s %Date %s %s %s %d %s\n",U.id,U.nom,U.prenom,U.genre,U.dn,U.type,U.appartenance,U.nationalite,U.idbv,U.mdp);
		}
	}
	fclose(f);
	fclose(f2);
	remove(filename);
	rename("nouv.txt",filename);
	return tr;
}
int supprimer(char * filename, int id)
{
	int tr=0;
	utilisateur U;
	FILE * f=fopen(filename,"r");
	FILE * f2=fopen("nouv.txt","w");
	if ( f!=NULL && f2!=NULL)
	{
		 while (fscanf(f,"%d %s %s %s %Date %s %s %s %d %s\n",&U.id,U.nom,U.prenom,U.genre,U.dn,U.type,U.appartenance,U.nationalite,&U.idbv,U.mdp)!=EOF)
		{
			if (U.id==id)
				tr=1;
			else
				fprintf(f2,"%d %s %s %s %Date %s %s %s %d %s\n",U.id,U.nom,U.prenom,U.genre,U.dn,U.type,U.appartenance,U.nationalite,U.idbv,U.mdp);
		}
	}
	fclose(f);
	fclose(f2);
	remove(filename);
	rename("nouv.txt",filename);
	return tr;
}
utilisateur chercher(char * filename,int id)
{
	utilisateur U;
	int tr;
	FILE * f=fopen(filename,"r");
	if (f!=NULL)
	{
		while (tr==0 && fscanf(f,"%d %s %s %s %Date %s %s %s %d %s\n",&U.id,U.nom,U.prenom,U.genre,U.dn,U.type,U.appartenance,U.nationalite,&U.idbv,U.mdp)!=EOF)
		{
			if (U.id==id)
				tr=1;
		}
	}
	fclose(f);
	if (tr==0)
		U.id=-1;
	return U;
}
int nbobserver(char * filename)
{
	utilisateur U;
	int tr=0;
	FILE * f=fopen(filename,"w");
	if (f!=NULL)
	{
		if (U.type=="observateur")
			tr=++tr;
	}
	fprintf("\nLe nombre des observateurs est :%d",tr);
	return tr;
	fclose(f);
}
void trier(char * filename)
{
	int i,j;
	utilisateur U,tmp;
	FILE * f=fopen(filename,"r");
	utilisateur T[100];
	for (i=0; i<sizeof(T); i++);
	{
		int *index=i;
		for (j=i+1; j<sizeof(T)+1; j++)
		{
			if (T[*index].id>T[j].id)
				*index=j;
		}
		if (*index!=i)
		{
			tmp=T[i];
			T[i]=T[*index];
			T[*index]=tmp;
		}
	}
	for (i=0; i<sizeof(T); i++)
		printf("%utilisateur",T[i]);
}
