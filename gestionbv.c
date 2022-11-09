#include "gestionbv.h"

int ajouter(char * namefile, GBV A )
{
    FILE * f=fopen(namefile, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %d %d %d\n",A.IdAdmin,A.municipalite,A.ecole, A.numsalle,A.nbrelecteur, A.capaciteobs);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier( char * file, int Id, GBV nouv )
{
    int tr=0;
    GBV A ;
    FILE * f=fopen(file, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %d %d\n",&A.IdAdmin,A.municipalite,A.ecole,&A.numsalle,&A.nbrelecteur,&A.capaciteobs)!=EOF)
        {
            if(A.IdAdmin == Id)
            {
                fprintf(f2,"%d %s %s %d %d %d\n",nouv.IdAdmin,nouv.municipalite,nouv.ecole,nouv.numsalle,nouv.nbrelecteur,nouv.capaciteobs);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %d %d %d\n",A.IdAdmin,A.municipalite,A.ecole,A.numsalle,A.nbrelecteur, A.capaciteobs);

        }
    }
    fclose(f);
    fclose(f2);
    remove(file);
    rename("nouv.txt", file);
    return tr;

}

int supprimer(char * file, int Id)
{
    int tr=0;
    GBV A ;
    FILE * f=fopen(file, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %d %d\n",&A.IdAdmin,A.municipalite,A.ecole,&A.numsalle,&A.nbrelecteur,&A.capaciteobs)!=EOF)
        {
            if(A.IdAdmin== Id)
                tr=1;
            else
                fprintf(f2,"%d %s %s %d %d %d\n",A.IdAdmin,A.municipalite,A.ecole,A.numsalle,A.nbrelecteur, A.capaciteobs);
        }
    }
    fclose(f);
    fclose(f2);
    remove(file);
    rename("nouv.txt",file);
    return tr;
}


