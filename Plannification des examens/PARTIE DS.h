#ifndef ENSAH_VERSION_2_H_INCLUDED
#define ENSAH_VERSION_2_H_INCLUDED
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct str2
{
    int jour;
    int mois;
    int annee;
}DATE;
typedef struct str4
{
    char *nom_module;
    DATE date;
    struct str4 *succ;

}emploi;
typedef struct str1
{
	char *CNE;
	char *nom;
	char *prenom;
	int  place;
	struct str1 *succ_e;
}etudiant;
char* JOURE_SEMAIN(DATE *d)
{

    char *monjour=(char*)malloc(sizeof(char));
    unsigned njours = (d->annee - 1) * 365;

    if (d->annee > 1582) /* Calendrier Grégorien */
    {
        njours += ((d->annee - 1) / 4);
        njours -= ((d->annee - 1) / 100);
        njours += ((d->annee - 1) / 400);
        njours += 2;
    }
    else /* Calendrier Julien */
        njours += ((d->annee - 1) / 4);

    njours += (d->mois - 1) * 31;

    switch (d->mois)
    {
    case 12:
        --njours;
    case 11:
    case 10:
        --njours;
    case 9:
    case 8:
    case 7:
        --njours;
    case 6:
    case 5:
        --njours;
    case 4:
    case 3:
        if (d->annee > 1582)
        {
            if (d->annee % 4 == 0 && (d->annee % 100 != 0 || d->annee % 400 == 0))
                njours -= 2;
            else
                njours -= 3;
        }
        else
        {
            if (d->annee % 4 == 0)
                njours -= 2;
            else
                njours -= 3;
        }
        break;
    }


    njours += (d->jour - 1);

    switch (njours % 7)
    {
    case 0:
        strcpy(monjour,"samedi");
        break;

    case 1:
        strcpy(monjour,"dimanche");
        break;

    case 2:
        strcpy(monjour,"lundi");
        break;

    case 3:
        strcpy(monjour,"mardi");
        break;

    case 4:
        strcpy(monjour,"mercredi");
        break;

    case 5:
        strcpy(monjour,"jeudi");
        break;

    case 6:
        strcpy(monjour,"vendredi");
        break;
    }

    return monjour;
}
char* mois(int d)
{
    char *mon_mois=(char*)malloc(sizeof(char));
    switch(d-1)
    {
    case 0:
        strcpy(mon_mois,"janvier");
        break;
    case 1:
        strcpy(mon_mois,"fevrier");
        break;
    case 2:
        strcpy(mon_mois,"mars");
        break;
    case 3:
        strcpy(mon_mois,"avril");
        break;
    case 4:
        strcpy(mon_mois,"mai");
        break;
    case 5:
        strcpy(mon_mois,"juin");
        break;
    case 6:
        strcpy(mon_mois,"juillet");
        break;
    case 7:
        strcpy(mon_mois,"aout");
        break;
    case 8:
        strcpy(mon_mois,"septembre");
        break;
    case 9:
        strcpy(mon_mois,"octobre");
        break;
    case 10:
        strcpy(mon_mois,"novembre");
        break;
    case 11:
        strcpy(mon_mois,"decembre");
        break;
    default:
        printf("ce choix est invalide");

    }
    return mon_mois;
}
/*void ecrir_dans_un_fichier(emploi *p)
{
    FILE *fic;
    if((fic=fopen("emplois_du_temps.txt","w"))!=NULL){
        while(p!=NULL){
                    fprintf(fic,"%d/%d/%d\t%s\n",p->date.jour,(p->date.mois),(p->date.annee),(p->nom_module)); // copier chaque maillon
                    p=p->succ; // passer au maillon suivant
                    }
                fclose(fic); // fermer le fichier
                }
}*/
//afficher les modules
void affiche1(emploi *l){
    emploi *p;
    p=l;
    if(l==NULL )
        printf("la liste est vide ");
    else{
    while(p!=NULL){
       printf("\t\t\t\t\t\t     | %d/%d/%d ",p->date.jour,p->date.mois,p->date.annee);
       printf("\t%s\n",p->nom_module);
       p = p->succ;
       }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    }
}
//afficher les etudiants
/*void affiche2(etudiant *l)
{
	etudiant *p=l;
	 if(l==NULL )
        printf("la liste est vide ");
    else{
    while(p!=NULL){
       printf("\t\t\t\t\t\t     | %s %s %s %d " , p->CNE , p->nom , p->prenom , &(p.place));
       p = p->succ_e; 
       }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    }
}*/
//AJOUTER A LA FIN:module
emploi* emfiler_m(emploi *l,emploi *elem){
    emploi *temp=NULL;
    if(l == NULL)
        l = elem;
    else{
        temp=l;
        while(temp->succ != NULL){
            temp=temp->succ;
            }
        temp->succ=elem;
    }
    return l;
}
//ajouter a la fin: etudiant
/*etudiant* emfiler_e(etudiant *l, etuadiant *elem)
{
	etudiant *temp=NULL;
	 if(l == NULL)
        l = elem;
    else{
        temp=l;
        while(temp->succ != NULL){
            temp=temp->succ;
            }
        temp->succ=elem;
    }
    return l;
}*/

//les fonctions de palannification
void AP1_AUTOMN(DATE *d){
    FILE *fic1,*fic2;
    int i=0,j=1,k=100;
    emploi *P=NULL;
    etudiant *E=NULL;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    fic1=fopen("S1_AP1.txt","r");
    if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
            }
    
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire : 2021/2022          Cycle : Preparatoire          Niveau : AP1   |\n");
    printf("\t\t\t\t\t\t     | Session : Automn                         Semestre : S1                                |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: l'amphie A et B,les salles 4 , 5, 16 , 17                               |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    while(!feof(fic1)){
    	    //module
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            
            //traitement du temps
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;
                }
            
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
           // E=emfiler_e(E,elem1);
            i++;
            }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                          |\n");
    affiche1(P);
     /*fic2=fopen("AP2.txt","r");
    if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
            }
   while(!feof(fic2))
    {
    	//etudiant
            etudiant *elem1=(etudiant*)malloc(sizeof(etudiant));
            elem1->CNE=(char*)malloc(sizeof(char)*30);
            elem1->nom=(char*)malloc(sizeof(char)*30);
            elem1->prenom=(char*)malloc(sizeof(char)*30);
            elem1->place=j;
            elem1->succ=NULL;
            j++;
            k++;
            if(k==101 && j==51){
            	j=1;
			}
			if(k>101 && j==26){
				j=1;
			}    
            fscanf(fic2,"%s %s %s %d",elem1->CNE,elem1->nom,elem1->prenom);
	}
    fclose(fic2);
    printf("\t\t\t\t\t\t     |")
    affiche2(E);*/

}
void AP1_PRINTEMPS(DATE *d)
{

}
void AP2_AUTOMN(DATE *d)
{
    FILE *fic1;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S3_AP2.txt","r");
    if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Preparatoire          Niveau : AP2     |\n");
    printf("\t\t\t\t\t\t     | Session : Automn                       Semestre : S3                                  |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: l'amphie A et B, les salles 4, 5, 16, 17                                |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    int i=0;
    while(!feof(fic1)){

            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;

    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                         |\n");
    affiche1(P);

    }
void AP2_PRINTEMPS(DATE *d){

}
void GI1_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S1_GI1.txt","r");
    if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GI       |\n");
    printf("\t\t\t\t\t\t     | niveau:GI1                             Session : Automn            Semestre : S1      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 1,2                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                          |\n");
    affiche1(P);

}
void GI2_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S3_GI2.txt","r");
    if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
            }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          Filiere : GI       |\n");
    printf("\t\t\t\t\t\t     | Niveau:GI2                             Session : Automn            Semestre : S3     |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 4,5                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                         |\n");
    affiche1(P);
}
void GI3_BI_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S5_GI3_BI.txt","r");
    if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieur          Filiere : GI        |\n");
    printf("\t\t\t\t\t\t     | Niveau: GI3_BI                         Session : Automn           Semestre : S5     |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: la salle 1                                                              |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                         |\n");
    affiche1(P);

}
void GI3_GL_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S5_GI3_GL.txt","r");
    if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieur          Filiere : GI        |\n");
    printf("\t\t\t\t\t\t     | Niveau: GI3_GL                         Session : Automn           Semestre : S5        |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: la salle 2                                                              |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
        }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                         |\n");
    affiche1(P);
                }
void GI1_PRINTEMPS(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S2_GI1.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieur          Filiere : GI        |\n");
    printf("\t\t\t\t\t\t     | Niveau: GI1                            Session : Automn           Semestre : S2       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: la salle 1,2                                                            |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                          |\n");
    affiche1(P);

}
void GI2_PRINTEMPS(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S4_GI2.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieur          Filiere : GI        |\n");
    printf("\t\t\t\t\t\t     | Niveau: GI2                            Session : Automn           Semestre : S4        |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: la salle 4,5                                                            |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                          |\n");
    affiche1(P);
}
void GC1_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S1_GC1.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GC       |\n");
    printf("\t\t\t\t\t\t     | niveau:GC1                             Session : Automn            Semestre : S1      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 1,2                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                          |\n");
    affiche1(P);

}
void GC2_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S3_GC2.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
        }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure           Filiere : GC      |\n");
    printf("\t\t\t\t\t\t     | Niveau:GC2                             Session : Automn             Semestre : S3     |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 4,5                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
        }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                          |\n");
    affiche1(P);


}
void GC3_HYD_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S5_GC3_HYD.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          Filiere : GC       |\n");
    printf("\t\t\t\t\t\t     | Niveau:GC3_HYD                         Session : Automn            Semestre : S5      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 4                                                            |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                         |\n");
    affiche1(P);

}
void GC3_BPC_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S5_GC3_BPC.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
        }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          Filiere : GC       |\n");
    printf("\t\t\t\t\t\t     | Niveau:GC3_BPC                         Session : Automn            Semestre : S5      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 5                                                            |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
    S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
        //je dois incrementer le temps
        }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                         |\n");
    affiche1(P);


}
void GC1_PRINTEMPS(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S2_GC1.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GC       |\n");
    printf("\t\t\t\t\t\t     | niveau:GC1                             Session : printemps         Semestre : S2      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 1,2                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                         |\n");
    affiche1(P);

}
void GC2_PRINTEMPS(DATE *d)
{
    FILE *fic1;
    int i=0;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S4_GC2.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          Filiere : GC       |\n");
    printf("\t\t\t\t\t\t     | Niveau:GC2                             Session : printemps         Semestre : S4      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 4,5                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                         |\n");
    affiche1(P);


}
void GEE1_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S1_GEE1.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEE      |\n");
    printf("\t\t\t\t\t\t     | niveau:GEE1                            Session : Automn            Semestre : S1      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 1,2                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t14:30->16:30                                                         |\n");
    affiche1(P);
}
void GEE2_AUTOMN(DATE *d)
{
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S3_GEE2.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEE      |\n");
    printf("\t\t\t\t\t\t     | niveau:GEE2                            Session : Automn            Semestre : S2      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 1,2                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t14:30->16:30                                                         |\n");
    affiche1(P);
}
void GEE3_AUTOMN(DATE *d){
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S5_GEE3.txt","r");
    if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
                    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEE      |\n");
    printf("\t\t\t\t\t\t     | niveau:GEE3                            Session : Automn            Semestre :S5       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 6,7                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                         |\n");
    affiche1(P);
 }
void GEE2_PRINTEMPS(DATE *d){
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S4_GEE2.txt","r");
    if(fic1==NULL){
    printf("\nouverture du fichier impossible!");
    exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEE      |\n");
    printf("\t\t\t\t\t\t     | niveau:GEE2                            Session : Printemps         Semestre : S4      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 4,5                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
        if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
        {
            d->mois+=1;
            d->jour-=31;
                    }
        if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
        {
            d->mois+=1;
            d->jour-=30;

            }
        if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
        {
            d->mois+=1;
            d->jour-=28;
            }
        if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
        {
            d->mois-=11;
            d->jour-=31;
            d->annee+=1;
            }
        S_JOURS=JOURE_SEMAIN(&elem->date);
        if(strcmp(S_JOURS,"dimanche")==0){
            d->jour+=1;
            elem->date.jour=(d->jour)+i;
                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t14:30->16:30                                                         |\n");
     affiche1(P);
 }
void GEE1_PRINTEMPS(DATE *d){
    FILE *fic1;
    int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S2_GEE1.txt","r");
    if(fic1==NULL){
        printf("\nouverture du fichier impossible!");
        exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEE      |\n");
     printf("\t\t\t\t\t\t     | niveau:GEE1                            Session : Printemps         Semestre : S2      |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | >>les locaux: les salles 1,2                                                          |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t14:30->16:30                                                          |\n");
     affiche1(P);
 }
 void GEER1_AUTOMN(DATE *d){
     FILE *fic1;
     int i;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
     emploi *P=NULL;
     fic1=fopen("S1_GEER1.txt","r");
     if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEER     |\n");
     printf("\t\t\t\t\t\t     | niveau:GEER1                           Session : Automn            Semestre : S1      |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | les locaux: les salles 1,2                                                            |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t16:30->18:30                                                         |\n");
     affiche1(P);
     }
void GEER2_AUTOMN(DATE *d){
    FILE *fic1;
    int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S3_GEER2.txt","r");
    if(fic1==NULL){
    printf("\nouverture du fichier impossible!");
    exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEER     |\n");
    printf("\t\t\t\t\t\t     | niveau:GEER2                           Session : Automn            Semestre : S3      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 4,5                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t16:30->18:30                                                         |\n");
    affiche1(P);

    }
void GEER3_AUTOMN(DATE *d){
    FILE *fic1;
    int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S5_GEER3.txt","r");
    if(fic1==NULL){
            printf("\nouverture du fichier impossible!");
            exit(0);
        }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEER     |\n");
    printf("\t\t\t\t\t\t     | niveau:GEER3                           Session : Automn            Semestre : S5      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 6,7                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
        emploi *elem=(emploi*)malloc(sizeof(emploi));
        elem->nom_module=(char*)malloc(sizeof(char)*30);
        elem->date.jour=(d->jour)+i;
        elem->date.mois=d->mois;
        elem->date.annee=d->annee;
        elem->succ=NULL;
        S_MOIS=mois(elem->date.mois);
        if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
        {
            d->mois+=1;
            d->jour-=31;
                    }
        if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
        {
            d->mois+=1;
            d->jour-=30;

            }
        if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
            d->mois+=1;
            d->jour-=28;
            }
        if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
            d->mois-=11;
            d->jour-=31;
            d->annee+=1;
            }
        S_JOURS=JOURE_SEMAIN(&elem->date);
        if(strcmp(S_JOURS,"dimanche")==0){
            d->jour+=1;
            elem->date.jour=(d->jour)+i;
            }
        fscanf(fic1,"%s",(elem->nom_module));
        P=emfiler_m(P,elem);
        i++;
        }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                          |\n");
    affiche1(P);

    }
void GEER1_PRINTEMPS(DATE *d){
     FILE *fic1;
     int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
     emploi *P=NULL;
     fic1=fopen("S2_GEER1.txt","r");
     if(fic1==NULL){
     printf("\nouverture du fichier impossible!");
     exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEER     |\n");
     printf("\t\t\t\t\t\t     | niveau:GEER1                           Session : Printemps         Semestre : S2      |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | les locaux: les salles 1,2\n                                                          |");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t16:30->18:30                                                         |\n");
     affiche1(P);

 }
 void GEER2_PRINTEMPS(DATE *d){
     FILE *fic1;
     int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
     emploi *P=NULL;
     fic1=fopen("S4_GEER2.txt","r");
     if(fic1==NULL){
     printf("\nouverture du fichier impossible!");
     exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GEER     |\n");
     printf("\t\t\t\t\t\t     | niveau:GEER2                           Session : Printemps         Semestre : S4      |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | >>les locaux: les salles 4,5                                                          |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t16:30->18:30                                                         |\n");
     affiche1(P);

 }
 void GM1_AUTOMN(DATE *d){
     FILE *fic1;
     int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
     emploi *P=NULL;
     fic1=fopen("S1_GM1.txt","r");
     if(fic1==NULL){
     printf("\nouverture du fichier impossible!");
     exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GM       |\n");
     printf("\t\t\t\t\t\t     | niveau:GM1                             Session : Automn            Semestre : S1      |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | >>les locaux: les salles 6,7                                                          |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                         |\n");
     affiche1(P);

 }
 void GM2_AUTOMN(DATE *d){
     FILE *fic1;
     int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
     emploi *P=NULL;
     fic1=fopen("S3_GM2.txt","r");
     if(fic1==NULL){
     printf("\nouverture du fichier impossible!");
     exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GM       |\n");
     printf("\t\t\t\t\t\t     | niveau:GM2                             Session : AUTOMN            Semestre : S3      |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | >>les locaux: les salles 6,7                                                          |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                         |\n");
     affiche1(P);

 }
 void GM3_AUTOMN(DATE *d){
     FILE *fic1;
     int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
     emploi *P=NULL;
     fic1=fopen("S5_GM3.txt","r");
     if(fic1==NULL){
     printf("\nouverture du fichier impossible!");
     exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GM       |\n");
     printf("\t\t\t\t\t\t     | niveau:GM3                             Session : Automn            Semestre : S5      |  \n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | >>les locaux: les salles 4,5                                                          |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                         |\n");
     affiche1(P);

 }
 void GM1_PRINTEMPS(DATE *d){
     FILE *fic1;
     int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
     emploi *P=NULL;
     fic1=fopen("S2_GM1.txt","r");
     if(fic1==NULL){
     printf("\nouverture du fichier impossible!");
     exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GM1      |\n");
     printf("\t\t\t\t\t\t     | niveau : GM1                           Session : Printemps         Semestre : S2      |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | >>les locaux: les salles 6,7                                                          |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t8:30->10:30                                                         |\n");
     affiche1(P);
 }
 void GM2_PRINTEMPS(DATE *d){
     FILE *fic1;
     int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
     emploi *P=NULL;
     fic1=fopen("S4_GM2.txt","r");
     if(fic1==NULL){
     printf("\nouverture du fichier impossible!");
     exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : GM       |\n");
     printf("\t\t\t\t\t\t     | niveau:GM2                             Session : Printemps         Semestre : S4      |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | >>les locaux: les salles 6,7                                                          |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                         |\n");
     affiche1(P);
 }
 void ID1_AUTOMN(DATE *d){
     FILE *fic1;
     int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
     emploi *P=NULL;
     fic1=fopen("S1_ID1.txt","r");
     if(fic1==NULL){
     printf("\nouverture du fichier impossible!");
     exit(0);
     }
     printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
     printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : ID       |\n");
     printf("\t\t\t\t\t\t     | niveau:ID2                             Session : AUTOMN            Semestre : S1      |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     printf("\t\t\t\t\t\t     | >>les locaux: les salles 6,7                                                          |\n");
     printf("\t\t\t\t\t\t     |                                                                                       |\n");
     i=0;
     while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
     }
     fclose(fic1);
     printf("\t\t\t\t\t\t     | \t\t\t14:30->16:30                                                          |\n");
    affiche1(P);

 }
void ID2_AUTOMN(DATE *d){
    FILE *fic1;
    int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S3_ID2.txt","r");
    if(fic1==NULL){
    printf("\nouverture du fichier impossible!");
    exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : ID       |\n");
    printf("\t\t\t\t\t\t     | niveau:ID2                             Session : AUTOMN            Semestre : S3      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 6,7                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t16:30->18:30                                                         |\n");
    affiche1(P);

}
void ID3_AUTOMN(DATE *d){
    FILE *fic1;
    int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S5_ID3.txt","r");
    if(fic1==NULL){
    printf("\nouverture du fichier impossible!");
    exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : ID       |\n");
    printf("\t\t\t\t\t\t     | niveau:ID3                             Session : AUTOMN            Semestre : S5      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 1,2                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t10:30->12:30                                                         |\n");
    affiche1(P);

}
void ID2_PRINTEMPS(DATE *d){
    FILE *fic1;
    int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S2_ID1.txt","r");
    if(fic1==NULL){
    printf("\nouverture du fichier impossible!");
    exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : ID       |\n");
    printf("\t\t\t\t\t\t     | niveau:ID1                             Session : Printemps         Semestre : S3      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 6,7                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
                d->jour-=30;

            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t14:30->16:30                                                         |\n");
    affiche1(P);

}
void ID1_PRINTEMPS(DATE *d){
    FILE *fic1;
    int i ;
    char *S_JOURS=(char*)malloc(sizeof(char));
    char *S_MOIS=(char*)malloc(sizeof(char));
    emploi *P=NULL;
    fic1=fopen("S4_ID2.txt","r");
    if(fic1==NULL){
    printf("\nouverture du fichier impossible!");
    exit(0);
    }
    printf("\t\t\t\t\t\t      ---------------------------------------------------------------------------------------\n" );
    printf("\t\t\t\t\t\t     | Annee universitaire:2021/2022          Cycle : Ingenieure          filiere : ID       |\n");
    printf("\t\t\t\t\t\t     | niveau:ID2                             Session : Printemps         Semestre : S4      |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    printf("\t\t\t\t\t\t     | >>les locaux: les salles 4,5                                                          |\n");
    printf("\t\t\t\t\t\t     |                                                                                       |\n");
    i=0;
    while(!feof(fic1)){
            emploi *elem=(emploi*)malloc(sizeof(emploi));
            elem->nom_module=(char*)malloc(sizeof(char)*30);
            elem->date.jour=(d->jour)+i;
            elem->date.mois=d->mois;
            elem->date.annee=d->annee;
            elem->succ=NULL;
            S_MOIS=mois(elem->date.mois);
            if((strcmp(S_MOIS,"janvier")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"mars")==0 && elem->date.jour==31)|| (strcmp(S_MOIS,"mai")==0 && elem->date.jour==31)||(strcmp(S_MOIS,"juillet")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"aout")==0 && elem->date.jour==31) || (strcmp(S_MOIS,"octobre")==0 && elem->date.jour==31) )
                {
                    d->mois+=1;
                    d->jour-=31;
                    }
            if((strcmp(S_MOIS,"novembre")==0 && elem->date.jour==30) || (strcmp(S_MOIS,"juin")==0 && elem->date.jour==30)||(strcmp(S_MOIS,"avril")==0 && elem->date.jour==30) ||(strcmp(S_MOIS,"septembre")==0 && elem->date.jour==30))
            {
                d->mois+=1;
            }
            if((strcmp(S_MOIS,"fevrier")==0 && elem->date.jour==28))//PROBLEM F LE FEVRIER
            {
                d->mois+=1;
                d->jour-=28;
            }
            if((strcmp(S_MOIS,"decembre")==0 && elem->date.jour==31))
            {
                d->mois-=11;
                d->jour-=31;
                d->annee+=1;
            }
            S_JOURS=JOURE_SEMAIN(&elem->date);
            if(strcmp(S_JOURS,"dimanche")==0){
                d->jour+=1;
                elem->date.jour=(d->jour)+i;

                }
            fscanf(fic1,"%s",(elem->nom_module));
            P=emfiler_m(P,elem);
            i++;
    }
    fclose(fic1);
    printf("\t\t\t\t\t\t     | \t\t\t16:30->18:30                                                         |\n");
    affiche1(P);

}
void plannification()
{
    char choix,*cycle=(char*)malloc(sizeof(char)),*filiere=(char*)malloc(sizeof(char)),*niveau=(char*)malloc(sizeof(char));
    int nbr,k=0;
    DATE date_debut;
    printf("\n");
    printf("\t\t\t\t\t    >>La date debut sous la forme (jj/mm/aa) : ");
    scanf("%d/%d/%d",&(date_debut.jour),&(date_debut.mois),&(date_debut.annee));
    printf("\n");
    printf("\t\t\t\t\t    >>Veuillez entrer le nbr des promos: ");
    scanf("%d",&nbr);
    debut1:
    printf("\n");	
    printf("\t\t\t\t\t    >>Veuillez choisir la session: \n");
    printf("\t\t\t\t\t\t      --------------\n");
    printf("\t\t\t\t\t\t     | [A] Automne; |\n");
    printf("\t\t\t\t\t\t     | [P] Printemp.|\n");
    printf("\t\t\t\t\t\t      --------------\n");
    printf("\t\t\t\t\t\t           >>Choix: ");
    fflush(stdin);
    gets(&choix);
    if(strcmp(&choix,"A")!= 0 && strcmp(&choix,"P")!= 0)
    {
        printf("ce choix est invalide!!");
        goto debut1;

    }
    for(k=0;k<nbr;k++){
    
    debut2:
    printf("\n");
    printf("\t\t\t\t\t    >>Veuillez choisir le cycle: \n");
    printf("\t\t\t\t\t\t       -------------------------\n");
    printf("\t\t\t\t\t\t      | [CP]Cycle preparatoire; |\n");
    printf("\t\t\t\t\t\t      | [CI]Cycle ingenieure.   |\n");
    printf("\t\t\t\t\t\t       -------------------------\n");
    printf("\t\t\t\t\t\t                      >>Choix: ");
    fflush(stdin);
    gets(cycle);
    if(strcmp(cycle,"CP")!=0 && strcmp(cycle,"CI")!=0)
    {
        printf("ce choix est invalide!!");
        goto debut2;
    }
    if(strcmp(cycle,"CP")==0)
        goto AP;
    else{
        debut9:
        printf("\t\t\t\t\t    >>Veulliez choisir la filiere: \n");
        printf("\t\t\t\t\t\t        --------------------------------------------------\n" );
        printf("\t\t\t\t\t\t       | [GI] Genie informatique;                         |\n");
        printf("\t\t\t\t\t\t       | [GC] Genie civil;                                |\n");
        printf("\t\t\t\t\t\t       | [GEE] Genie energetique et energie renouvelable; |\n");
        printf("\t\t\t\t\t\t       | [GEER] Genie de l'eau et de l'ennvironnement;    |\n");
        printf("\t\t\t\t\t\t       | [ID] Igenieure de donnees;                       |\n");
        printf("\t\t\t\t\t\t       | [GM] Genie mecanique.                            |\n");
        printf("\t\t\t\t\t\t        --------------------------------------------------\n" );
        printf("\t\t\t\t\t\t                                         >>Choix:  ");
        fflush(stdin);
        gets(filiere);
        if(strcmp(filiere,"GI")!=0 && strcmp(filiere,"GC")!=0 && strcmp(filiere,"GEE")!=0 && strcmp(filiere,"GEER")!=0 && strcmp(filiere,"ID")!=0 && strcmp(filiere,"GM")!=0)
        {
            printf("Ce choix est invalide!!\n");
            goto debut9;
        }

    }
    AP:
    printf("\t\t\t\t\t    >>Veuillez choisir le niveau :\n");
    
    if(strcmp(cycle,"CP")==0)
    {
        debut3:
        printf("\t\t\t\t\t\t        ------------------------------------\n");
        printf("\t\t\t\t\t\t       | [AP1] Premiere annee preparatoire; |\n");
        printf("\t\t\t\t\t\t       | [AP2] Deuxieme annee preparatoire; |\n");
        printf("\t\t\t\t\t\t        ------------------------------------\n");
        printf("\t\t\t\t\t\t                                 >>Choix:  ");
        gets(niveau);
        if(strcmp(niveau,"AP1")!=0 && strcmp(niveau,"AP2")!=0)
        {
            printf("ce choix est invalide!!\n");
            goto debut3;
        }
        if(strcmp(&choix,"A")==0){

                if( strcmp(niveau,"AP1")==0){
                    AP1_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                    }
               if(strcmp(niveau,"AP2")==0){
                    AP2_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
               }}
        if(strcmp(&choix,"P")==0){
                if( strcmp(niveau,"AP1")==0){
                    AP1_PRINTEMPS(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
               }
               if(strcmp(niveau,"AP2")==0){
                    AP2_PRINTEMPS(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
               }}}
else{
        if(strcmp(filiere,"GI")==0)
        {
            debut4:
            printf("\t\t\t\t\t\t        --------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t       | [GI1] Premiere annee genie informatique;                           |\n");
            printf("\t\t\t\t\t\t       | [GI2] Deuxieme annee genie informatique;                           |\n");
            printf("\t\t\t\t\t\t       | [GI3_BI] troisieme annee genie informatique bisnesse intelligence; |\n");
            printf("\t\t\t\t\t\t       | [GI3_GL] troisieme annee genie informatique genie logiciel;        |\n");
            printf("\t\t\t\t\t\t        --------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t                                                         >>Choix:  ");
            fflush(stdin);
            gets(niveau);
            if(strcmp(niveau,"GI1")!=0 && strcmp(niveau,"GI2")!=0 && strcmp(niveau,"GI3_BI")!=0 && strcmp(niveau,"GI3_GL")!=0 )
            {
                printf("ce choix est invalide!!");
                goto debut4;
            }
            if(strcmp(&choix,"A")==0){
                if( strcmp(niveau,"GI1")==0){
                    GI1_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }

               if(strcmp(niveau,"GI2")==0){
                    GI2_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
               }

               if(strcmp(niveau,"GI3_BI")==0){
                    GI3_BI_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
               if(strcmp(niveau,"GI3_GL")==0){
                    GI3_GL_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
               }}
            if(strcmp(&choix,"P")==0){
                if( strcmp(niveau,"GI1")==0){
                    GI1_PRINTEMPS(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
               if(strcmp(niveau,"GI2")==0){
                    GI2_PRINTEMPS(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
             }}
        if(strcmp(filiere,"GC")==0)
        {
            debut5:
            printf("\t\t\t\t\t\t        ---------------------------------------------------\n");
            printf("\t\t\t\t\t\t       | [GC1] Premiere annee genie civil;                 |\n");
            printf("\t\t\t\t\t\t       | [GC2] Deuxieme annee genie civil;                 |\n");
            printf("\t\t\t\t\t\t       | [GC3_HYD] troisieme annee genie civil HUDROLIQUE; |\n");
            printf("\t\t\t\t\t\t       | [GC3_BPC] troisieme annee genie civil BPC;        |\n");
            printf("\t\t\t\t\t\t        ---------------------------------------------------\n");
            printf("\t\t\t\t\t\t                                            >>Choix:  ");
            fflush(stdin);
            gets(niveau);
            if(strcmp(niveau,"GC1")!=0 && strcmp(niveau,"GC2")!=0 && strcmp(niveau,"GC3_HYD")!=0 &&  strcmp(niveau,"GC3_BPC")!=0)
            {
                printf("ce choix est invalide!!");
                goto debut5;
                }
            if(strcmp(&choix,"A")==0){
                if( strcmp(niveau,"GC1")==0){
                    GC1_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }

               if(strcmp(niveau,"GC2")==0){
                    GC2_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
               }
               if(strcmp(niveau,"GC3_HYD")==0){
                    GC3_HYD_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
               }
               if(strcmp(niveau,"GC3_BPC")==0){
                    GC3_BPC_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
               }}
            if(strcmp(&choix,"P")==0){
                if( strcmp(niveau,"GC1")==0){
                    GC1_PRINTEMPS(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
               if(strcmp(niveau,"GC2")==0){
                   GC2_PRINTEMPS(&date_debut);
                   if(nbr>1){
                        system("pause");
                        system("cls");
                    }
               }
               }
        }
        if(strcmp(filiere,"GEE")==0)
        {
            debut6:
            printf("\t\t\t\t\t\t         -------------------------------------\n");
            printf("\t\t\t\t\t\t        | [GEE1] Premiere annee genie civil;  |\n");
            printf("\t\t\t\t\t\t        | [GEE2] Deuxieme annee genie civil;  |\n");
            printf("\t\t\t\t\t\t        | [GEE3] troisieme annee genie civil; |\n");
            printf("\t\t\t\t\t\t         -------------------------------------\n");
            printf("\t\t\t\t\t\t                                >>Choix:  ");
            fflush(stdin);
            gets(niveau);
            if(strcmp(niveau,"GEE1")!=0 && strcmp(niveau,"GEE2")!=0 && strcmp(niveau,"GEE3")!=0 )
            {
                printf("ce choix est invalide!!");
                goto debut6;
                }
            if(strcmp(&choix,"A")==0){
                if( strcmp(niveau,"GEE1")==0){
                    GEE1_AUTOMN(&date_debut);
                    if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
              if(strcmp(niveau,"GEE2")==0){
                  GEE2_AUTOMN(&date_debut);
                  if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
              if(strcmp(niveau,"GEE3")==0){
                  GEE3_AUTOMN(&date_debut);
                  if(nbr>1){
                        system("pause");
                        system("cls");
                    }

                }}

            if(strcmp(&choix,"P")==0){

                if( strcmp(niveau,"GEE1")==0){
                GEE1_PRINTEMPS(&date_debut);
                if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
               if(strcmp(niveau,"GEE2")==0){
                   GEE2_PRINTEMPS(&date_debut);
                   if(nbr>1){
                        system("pause");
                        system("cls");
                    }

                }
        }}
         if(strcmp(filiere,"GEER")==0)
        {
            debut7:
            printf("\t\t\t\t\t\t         --------------------------------------\n");
            printf("\t\t\t\t\t\t        | [GEER1] Premiere annee genie civil;  |\n");
            printf("\t\t\t\t\t\t        | [GEER2] Deuxieme annee genie civil;  |\n");
            printf("\t\t\t\t\t\t        | [GEER3] troisieme annee genie civil; |\n");
            printf("\t\t\t\t\t\t         --------------------------------------\n");
            printf("\t\t\t\t\t\t                                   >>Choix:  ");
            fflush(stdin);
            gets(niveau);
            if(strcmp(niveau,"GEER1") !=0 && strcmp(niveau,"GEER2") !=0 && strcmp(niveau,"GEER3") !=0 )
            {
                printf("ce choix est invalide!!");
                goto debut7;
                }
            if(strcmp(&choix,"A")==0){
                if( strcmp(niveau,"GEER1")==0){
                        GEER1_AUTOMN(&date_debut);
                        if(nbr>1){
                        system("pause");
                        system("cls");
                    }

                }
            if(strcmp(niveau,"GEER2")==0){
                GEER2_AUTOMN(&date_debut);
                if(nbr>1){
                        system("pause");
                        system("cls");
                    }
            }
            if(strcmp(niveau,"GEER3")==0){
                   GEER3_AUTOMN(&date_debut);
                   if(nbr>1){
                        system("pause");
                        system("cls");
                    }

                }}
            if(strcmp(&choix,"P")==0){
                if( strcmp(niveau,"GEER1")==0){
                        GEER1_PRINTEMPS(&date_debut);
                        if(nbr>1){
                        system("pause");
                        system("cls");
                    }

                }
               if(strcmp(niveau,"GEER2")==0){
                   GEE2_PRINTEMPS(&date_debut);
                   if(nbr>1){
                        system("pause");
                        system("cls");
                    }

                }
        }}
         if(strcmp(filiere,"GM")==0)
        {
            debut8:
            printf("\t\t\t\t\t\t          ------------------------------------\n");
            printf("\t\t\t\t\t\t         | [GM1] Premiere annee genie civil;  |\n");
            printf("\t\t\t\t\t\t         | [GM2] Deuxieme annee genie civil;  |\n");
            printf("\t\t\t\t\t\t         | [GM3] troisieme annee genie civil; |\n");
            printf("\t\t\t\t\t\t          ------------------------------------\n");
            printf("\t\t\t\t\t\t                                   >>Choix:  ");
            fflush(stdin);
            gets(niveau);
            if(strcmp(niveau,"GM1")!=0 && strcmp(niveau,"GM2")!=0 && strcmp(niveau,"GM3")!=0 )
            {
                printf("ce choix est invalide!!");
                goto debut8;
                }
            if(strcmp(&choix,"A")==0){
                if( strcmp(niveau,"GM1")==0){
                GM1_AUTOMN(&date_debut);
                if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
        

              if(strcmp(niveau,"GM2")==0){
               GM2_AUTOMN(&date_debut);
               if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
        
            if(strcmp(niveau,"GM3")==0){
               GM3_AUTOMN(&date_debut);
               if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
        }
            if(strcmp(&choix,"P")==0){
                if( strcmp(niveau,"GM1")==0){
                GM1_PRINTEMPS(&date_debut);
                if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }

               if(strcmp(niveau,"GM2")==0){
               GM2_PRINTEMPS(&date_debut);
               if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }

        }}
        if(strcmp(filiere,"ID")==0)
        {
            debut10:
            printf("\t\t\t\t\t\t          ------------------------------------\n");
            printf("\t\t\t\t\t\t         | [ID1] Premiere annee genie civil;  |\n");
            printf("\t\t\t\t\t\t         | [ID2] Deuxieme annee genie civil;  |\n");
            printf("\t\t\t\t\t\t         | [ID3] troisieme annee genie civil; |\n");
            printf("\t\t\t\t\t\t          ------------------------------------\n");
            printf("\t\t\t\t\t\t                                  >>Choix:  ");
            fflush(stdin);
            gets(niveau);
            if(strcmp(niveau,"ID1")!=0 && strcmp(niveau,"ID2")!=0 && strcmp(niveau,"ID3")!=0 )
            {
                printf("ce choix est invalide!!");
                goto debut10;
                }
            if(strcmp(&choix,"A")==0){
                if( strcmp(niveau,"ID1")==0){
                ID1_AUTOMN(&date_debut);
                if(nbr>1){
                        system("pause");
                        system("cls");
                    }
        }

              if(strcmp(niveau,"ID2")==0){
                ID2_AUTOMN(&date_debut);
                if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
            if(strcmp(niveau,"ID3")==0){
               ID3_AUTOMN(&date_debut);
               if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
        }
            if(strcmp(&choix,"P")==0){
                if( strcmp(niveau,"ID1")==0){
                ID1_PRINTEMPS(&date_debut);
                if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }

               if(strcmp(niveau,"ID2")==0){
               ID2_PRINTEMPS(&date_debut);
               if(nbr>1){
                        system("pause");
                        system("cls");
                    }
                }
                }
               }

}}}





#endif // PARTIE_DS_H_INCLUDED
