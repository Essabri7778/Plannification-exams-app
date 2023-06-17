#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"PARTIE DS.h"

typedef struct Box{
  char* data;
  struct Box* next;
}Box;
void Welcome_Message();
void Saisie_Data( int *session, char *jour, DATE *debut, int *choix_AP, int *choix_5);
void Planifier_Tout(int session, DATE debut, int choix_AP, int choix_5, Box *temp, Box *l);//Prototype
void AP_S1(DATE debut, int choix_AP , Box *l, Box *temp);
DATE cinq_annee(DATE debut, int choix_5, Box *l, Box **temp);
void CI_S1(DATE debut, Box *l, Box *temp);
DATE AP_S2(DATE debut, int choix_AP, Box *l, Box **temp);
void CI_S2(DATE debut, Box *l, Box *temp);
void Verifier_Date(DATE *debut, Box **temp);
char* Trouver_Jour(DATE *d);
void liste_AP1();
void liste_AP2();
void EXIT();

void Verifier_Date(DATE *debut, Box **temp){
                   if((*debut).jour==32 && ((*debut).mois==1 || (*debut).mois== 3 || (*debut).mois== 5 || (*debut).mois== 7 || (*debut).mois== 8 || (*debut).mois== 10) ){
                           (*debut).jour=1;
                           *temp=(*temp)->next;
                           (*debut).mois++;
                    }
                    if((*debut).jour==31 && ((*debut).mois==4 || (*debut).mois== 6 || (*debut).mois== 9 || (*debut).mois== 11 ) ){
                           (*debut).jour=1;
                           *temp=(*temp)->next;
                           (*debut).mois++;
                    }
                    if((*debut).jour==32 && (*debut).mois==12){
                        (*debut).jour=1;
                        *temp=(*temp)->next;
                        (*debut).mois=1;
                        (*debut).annee++;
                    }
                    if((*debut).jour==29 && (*debut).mois==2){
                        (*debut).jour=1;
                        *temp=(*temp)->next;
                        (*debut).mois++;
                    }
}

void AP_S1(DATE debut, int choix_AP, Box *l, Box *temp){
        char module_AP1[100], module_AP2[100];
        FILE *AP1, *AP2;
        AP1=fopen("AP1_module_S1", "rt");
        if(AP1==NULL){
            printf("File can't open!\n");
            exit(1);
        }
        AP2=fopen("AP2_module_S1", "rt");
        if(AP2==NULL){
             printf("File can't open!\n");
            exit(1);
        }
        printf("_______________________________________________________________________________________________________________________________________________________________________\n");
        printf("\t\t|  8-->10\t         |\t\t\t|  10-->12\t|\t\t\t|  14-->16\t    |\t\t\t| 16-->18\t       |\n");
        printf("________________|________________________|______________________|_______________|_______________________|___________________|___________________|______________________|\n");
        while( fscanf(AP1, "%s", module_AP1)!=EOF && fscanf(AP2, "%s", module_AP2)!=EOF){
             if(strcmp(temp->data, "dimanche")!=0){
                printf("%d/%d/%d\t", debut.jour, debut.mois, debut.annee);
                (debut.jour)++;
                temp=temp->next;
             }
             else{
                 temp=l;
                (debut.jour)++;
                printf("%d/%d/%d\t\t", debut.jour, debut.mois, debut.annee);
                (debut.jour)++;
                temp=temp->next;
             }
             switch(choix_AP){
                case 1:
                   printf("            AP1\t\t\t\t\t\t\t\t\t\t          AP2\t\t\n");
                  printf("\t\t|  %s      |\t\t\t\t\t\t\t\t|  %s |\n\n", module_AP1, module_AP2);
                  break;
               case 2:
                   printf("            AP2\t\t\t\t\t\t\t\t\t\t          AP1\t\t\n");
                  printf("\t\t|  %s      |\t\t\t\t\t\t\t\t|  %s |\n\n", module_AP2, module_AP1);
                  break;
             }
       printf("________________|________________________|______________________|_______________|_______________________|___________________|___________________|______________________|\n");
       Verifier_Date(&debut, &temp);
       }
       fclose(AP1);
       fclose(AP2);
       printf("Press any key to escape this Page\n");
}

 DATE AP_S2(DATE debut, int choix_AP, Box *l, Box **temp)//Probleme affichage
 {
      FILE *AP1, *AP2;
      char module_AP1[100], module_AP2[100];
        AP1=fopen("AP1_module_S2", "rt");
        if(AP1==NULL){
            printf("AP1 can't open!\n");
            exit(1);
        }
        AP2=fopen("AP2_module_S2", "rt");
        if(AP2==NULL){
             printf("AP2 can't open!\n");
            exit(1);
        }
        printf("________________________________________________________________________________________________________________________________________________________\n");
        printf("\t\t|  8-->10\t      |\t\t\t|  10-->12\t|\t\t\t|  14-->16\t |\t\t\t| 16-->18\t|\n");
        printf("________________|_____________________|_________________|_______________|_______________________|________________|______________________|_______________|\n");
        while(fscanf(AP1, "%s", module_AP1)!=EOF && fscanf(AP2, "%s", module_AP2)!=EOF){
             if(strcmp((*temp)->data, "dimanche")!=0){
                printf("%d/%d/%d\t", debut.jour, debut.mois, debut.annee);
                (debut.jour)++;
                *temp=(*temp)->next;
             }
             else{
                 *temp=l;
                (debut.jour)++;
                printf("%d/%d/%d\t", debut.jour, debut.mois, debut.annee);
                (debut.jour)++;
                *temp=(*temp)->next;
             }
             switch(choix_AP){
               case 1:
                   printf("         AP1\t\t\t\t\t\t\t\t\t\tAP2\t\t\n");
                  printf("\t\t|  %s      |\t\t\t\t\t\t\t\t|  %s |\n\n", module_AP1, module_AP2);
                  break;
               case 2:
                   printf("          AP2\t\t\t\t\t\t\t\t\t\tAP1\t\t\n");
                  printf("\t\t|  %s      |\t\t\t\t\t\t\t\t|  %s |\n\n", module_AP2, module_AP1);
                  break;
             }
         printf("________________|_____________________|_________________|_______________|_______________________|________________|______________________|_______________|\n");
         Verifier_Date(&debut, temp);
         }
         fclose(AP1);
         fclose(AP2);
         return debut;
}

void CI_S1(DATE debut, Box *l, Box *temp){
       char GI1_module[20];
       char GC1_module[20];
       char GEER1_module[20];
       char GEE1_module[20];
        char GM1_module[20];
        char ID1_module[20];

        char GI2_module[20];
        char GC2_module[20];
        char GEER2_module[20];
        char GEE2_module[20];
        char GM2_module[20];
        char ID2_module[20];

        FILE *GI1=fopen("GI1_module_S1", "rt");
         if(GI1==NULL){
            printf("GI1 can\'t open\n");
            exit(1);
        }
        FILE *GC1=fopen("GC1_module_S1", "rt");
         if(GC1==NULL){
            printf("GC1 can\'t open\n");
            exit(1);
        }
        FILE *GEER1=fopen("GEER1_module_S1", "rt");
         if(GEER1==NULL){
            printf("GEER1 can\'t open\n");
            exit(1);
        }
        FILE *GEE1=fopen("GEE1_module_S1", "rt");
         if(GEE1==NULL){
            printf("GEE1 can\'t open\n");
            exit(1);
        }
        FILE *GM1=fopen("GM1_module_S1", "rt");
         if(GM1==NULL){
            printf("GM1 can\'t open\n");
            exit(1);
        }
        FILE *ID1=fopen("ID1_module_S1", "rt");
         if(ID1==NULL){
            printf("ID1 can\'t open\n");
            exit(1);
        }

        FILE *GI2=fopen("GI2_module_S1", "rt");
         if(GI2==NULL){
            printf("GI2 can\'t open\n");
            exit(1);
        }
        FILE *GC2=fopen("GC2_module_S1", "rt");
        if(GC2==NULL){
            printf("GC2 can\'t open\n");
            exit(1);
        }
        FILE *GEER2=fopen("GEER2_module_S1", "rt");
        if(GEER2==NULL){
            printf("GEER2 can\'t open\n");
            exit(1);
        }
        FILE *GEE2=fopen("GEE2_module_S1", "rt");
        if(GEE2==NULL){
            printf("GEE2 can\'t open\n");
            exit(1);
        }
        FILE *GM2=fopen("GM2_module_S1", "rt");
        if(GM2==NULL){
            printf("GM2 can\'t open\n");
            exit(1);
        }
        FILE *ID2=fopen("ID2_module_S1", "rt");
        if(ID2==NULL){
            printf("ID2 can\'t open\n");
            exit(1);
        }
        printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|-------------------------------------------------------------|\n");
        printf("\t\t8-->10\t\t\t\t\t\t10-->12\t\t\t\t\t    14-->16\t\t\t\t\t\t16-->18\n");
        printf("--------|-----------------------------------------------|-----------------------------------------------|------------------------------------------|-------------------------------------------------------------|\n");
        while(fscanf(GI1, "%s", GI1_module)!=EOF){
            fscanf(GC1, "%s", GC1_module);
            fscanf(GEER1, "%s", GEER1_module);
            fscanf(GEE1, "%s", GEE1_module);
            fscanf(GM1, "%s", GM1_module);
            fscanf(ID1, "%s", ID1_module);

            fscanf(GI2, "%s", GI2_module);
            fscanf(GC2, "%s", GC2_module);
            fscanf(GEER2, "%s", GEER2_module);
            fscanf(GEE2, "%s", GEE2_module);
            fscanf(GM2, "%s", GM2_module);
            fscanf(ID2, "%s", ID2_module);

            if(strcmp(temp->data, "dimanche")!=0){
               printf("%d/%d/%d\t", debut.jour, debut.mois, debut.annee);
               (debut.jour)++;
               temp=temp->next;
            }
            else{
                 temp=l;
                (debut.jour)++;
                printf("%d/%d/%d\t", debut.jour, debut.mois, debut.annee);
                (debut.jour)++;
                temp=temp->next;
            }
                printf("\t\tGI1\t\t\t\t\tGEE1\t\t\t\t\t\tGI2\t\t\t\t\t\tGEE2\n");
                printf("\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\n", GI1_module, GEE1_module, GI2_module, GEE2_module);
                printf("\t\tSalle 2 & 3\t\t\t\t\tSalle 5 & 6\t\t\t\t\tSalle 2 &3\t\t\t\t\tSalle 5 &6\n\n");
                printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|-------------------------------------------------------------|\n");
                printf("\t\t\tGC1\t\t\t\t\tGM1\t\t\t\t\t\tGC2\t\t\t\t\t\tGM2\n");
                printf("\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\n", GC1_module, GM1_module, GC2_module, GM2_module);
                printf("\t\tSalle 4 & 5\t\t\t\t\tSalle 10 \t\t\t\t\tSalle 4 & 5\t\t\t\t\tSalle 10\n\n");
                printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|-------------------------------------------------------------|\n");
                printf("\t\t\tGEER1\t\t\t\t\tID1\t\t\t\t\t\tGEER2\t\t\t\t\t\tID2\n");
                printf("\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\n", GEER1_module, ID1_module, GEER2_module, ID2_module);
                printf("\t\tSalle 10 & 11\t\t\t\t\tSalle 11 & 12\t\t\t\t\tSalle 10 &11\t\t\t\t\tSalle 11 &12\n\n");
                printf("--------|-----------------------------------------------|-----------------------------------------------|------------------------------------------|-------------------------------------------------------------|\n");

            Verifier_Date(&debut, &temp);
            }
            fclose(GI1);
            fclose(GEE1);
            fclose(GC1);
            fclose(GM1);
            fclose(GEER1);
            fclose(ID1);
            fclose(GI2);
            fclose(GEE2);
            fclose(GC2);
            fclose(GM2);
            fclose(GEER2);
            fclose(ID2);
            printf("Press any key to escape this Page\n");
}

void CI_S2(DATE debut, Box *l, Box *temp)
{
        FILE *GI1=fopen("GI1_module_S2", "rt");
        if(GI1==NULL){
            printf("GI1 can\'t open!\n");
            exit(1);
        }
        FILE *GC1=fopen("GC1_module_S2", "rt");
         if(GC1==NULL){
            printf("GC1 can\'t open!\n");
            exit(1);
        }
        FILE *GEER1=fopen("GEER1_module_S2", "rt");
         if(GEER1==NULL){
            printf("GEER1 can\'t open!\n");
            exit(1);
        }
        FILE *GEE1=fopen("GEE1_module_S2", "rt");
         if(GEE1==NULL){
            printf("GEE1 can\'t open!\n");
            exit(1);
        }
        FILE *GM1=fopen("GM1_module_S2", "rt");
         if(GM1==NULL){
            printf("GM1 can\'t open!\n");
            exit(1);
        }
        FILE *ID1=fopen("ID1_module_S2", "rt");
         if(ID1==NULL){
            printf("ID1 can\'t open!\n");
            exit(1);
        }

        FILE *GI2=fopen("GI2_module_S2", "rt");
         if(GI2==NULL){
            printf("GI2 can\'t open!\n");
            exit(1);
        }
        FILE *GC2=fopen("GC2_module_S2", "rt");
         if(GC2==NULL){
            printf("GC2 can\'t open!\n");
            exit(1);
        }
        FILE *GEER2=fopen("GEER2_module_S2", "rt");
         if(GEER2==NULL){
            printf("GEER2 can\'t open!\n");
            exit(1);
        }
        FILE *GEE2=fopen("GEE2_module_S2", "rt");
         if(GEE2==NULL){
            printf("GEE2 can\'t open!\n");
            exit(1);
        }
        FILE *GM2=fopen("GM2_module_S2", "rt");
         if(GM2==NULL){
            printf("GM2 can\'t open!\n");
            exit(1);
        }
        FILE *ID2=fopen("ID2_module_S2", "rt");
         if(ID2==NULL){
            printf("ID2 can\'t open!\n");
            exit(1);
        }

    char GI1_module[100];
    char GC1_module[100];
    char GEER1_module[100];
    char GEE1_module[100];
    char GM1_module[100];
    char ID1_module[100];

        char GI2_module[100];
        char GC2_module[100];
        char GEER2_module[100];
        char GEE2_module[100];
        char GM2_module[100];
        char ID2_module[100];
        printf("\t|-----------------------------------------------|-----------------------------------------------|----------------------------------------------|---------------------------------------------------------|\n");
        printf("\t\t8-->10\t\t\t\t\t\t10-->12\t\t\t\t\t    14-->16\t\t\t\t\t\t16-->18\n");
        printf("--------|-----------------------------------------------|-----------------------------------------------|----------------------------------------------|---------------------------------------------------------|\n");
        while(fscanf(GI1, "%s", GI1_module)!=EOF){
            fscanf(GC1, "%s", GC1_module);
            fscanf(GEER1, "%s", GEER1_module);
            fscanf(GEE1, "%s", GEE1_module);
            fscanf(GM1, "%s", GM1_module);
            fscanf(ID1, "%s", ID1_module);

            fscanf(GI2, "%s", GI2_module);
            fscanf(GC2, "%s", GC2_module);
            fscanf(GEER2, "%s", GEER2_module);
            fscanf(GEE2, "%s", GEE2_module);
            fscanf(GM2, "%s", GM2_module);
            fscanf(ID2, "%s", ID2_module);

            Verifier_Date(&debut, &temp);

            if(strcmp(temp->data, "dimanche")!=0){
               printf("%d/%d/%d\t", debut.jour, debut.mois, debut.annee);
               (debut.jour)++;
               temp=temp->next;
               }
               else{
                temp=l;
                (debut.jour)++;
                printf("%d/%d/%d\t", debut.jour, debut.mois, debut.annee);
                (debut.jour)++;
                temp=temp->next;
               }
                printf("\t\tGI1\t\t\t\t\tGEE1\t\t\t\t\t\tGI2\t\t\t\t\t\tGEE2\n");
                printf("\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\n", GI1_module, GEE1_module, GI2_module, GEE2_module);
                printf("\t\tSalle 2 & 3\t\t\t\t\tSalle 5 & 6\t\t\t\t\tSalle 2 &3\t\t\t\t\tSalle 5 &6\n\n");
                printf("\t|-----------------------------------------------|-----------------------------------------------|----------------------------------------------|---------------------------------------------------------|\n");
                printf("\t\t\tGC1\t\t\t\t\tGM1\t\t\t\t\t\tGC2\t\t\t\t\t\tGM2\n");
                printf("\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\n", GC1_module, GM1_module, GC2_module, GM2_module);
                printf("\t\tSalle 4 & 5\t\t\t\t\tSalle 10 \t\t\t\t\tSalle 4 & 5\t\t\t\t\tSalle 10\n\n");
                printf("\t|-----------------------------------------------|-----------------------------------------------|----------------------------------------------|---------------------------------------------------------|\n");
                printf("\t\t\tGEER1\t\t\t\t\tID1\t\t\t\t\t\tGEER2\t\t\t\t\t\tID2\n");
                printf("\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\n", GEER1_module, ID1_module, GEER2_module, ID2_module);
                printf("\t\tSalle 10 & 11\t\t\t\t\tSalle 11 & 12\t\t\t\t\tSalle 10 &11\t\t\t\t\tSalle 11 &12\n\n");
                printf("--------|-----------------------------------------------|-----------------------------------------------|----------------------------------------------|---------------------------------------------------------|\n");
            Verifier_Date(&debut, &temp);
            }
            fclose(GI1);
            fclose(GEE1);
            fclose(GC1);
            fclose(GM1);
            fclose(GEER1);
            fclose(ID1);
            fclose(GI2);
            fclose(GEE2);
            fclose(GC2);
            fclose(GM2);
            fclose(GEER2);
            fclose(ID2);
            printf("Press any key to escape this Page\n");
}

DATE cinq_annee(DATE debut, int choix_5, Box *l, Box **temp){
    char module_GL[100];
    char module_GM[100];
    char module_HYD[100];
    char module_ID[100];
    char module_GEER[100];
    char module_BI[100];
    char module_GEE[100];
    char module_BPC[100];

            FILE *GL=fopen("GL_module_S1", "rt");
            if(GL==NULL){
                printf("GL can\'t open!\n");
                exit(1);
            }
            FILE *GM=fopen("GM_module_S1", "rt");
            if(GM==NULL){
                printf("GM can\'t open!\n");
                exit(1);
            }
            FILE *HYD=fopen("HYD_module_S1", "rt");
            if(HYD==NULL){
                printf("HYD can\'t open!\n");
                exit(1);
            }
            FILE *ID=fopen("ID_module_S1", "rt");
            if(ID==NULL){
                printf("ID can\'t open!\n");
                exit(1);
            }
            FILE *GEER=fopen("GEER_module_S1", "rt");
            if(GEER==NULL){
                printf("GEER can\'t open!\n");
                exit(1);
            }
            FILE *BI=fopen("BI_module_S1", "rt");
            if(BI==NULL){
                printf("BI can\'t open!\n");
                exit(1);
            }
            FILE *GEE=fopen("GEE_module_S1", "rt");
            if(GEE==NULL){
                printf("GEE can\'t open!\n");
                exit(1);
            }
            FILE *BPC=fopen("BPC_module_S1", "rt");
            if(BPC==NULL){
                printf("BPC can\'t open!\n");
                exit(1);
            }
            printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|---------------------------------------------------|\n");
            printf("\t\t8-->10\t\t\t\t\t\t10-->12\t\t\t\t\t    14-->16\t\t\t\t\t\t16-->18\n\n");
            printf("--------|-----------------------------------------------|-----------------------------------------------|------------------------------------------|---------------------------------------------------|\n");
              while(fscanf(GL, "%s", module_GL)!=EOF){//Matin
                    fscanf(GM, "%s", module_GM);
                    fscanf(HYD, "%s", module_HYD);
                    fscanf(ID, "%s", module_ID);
                    fscanf(GEER, "%s", module_GEER);
                    fscanf(BI, "%s", module_BI);
                    fscanf(GEE, "%s", module_GEE);
                    fscanf(BPC, "%s", module_BPC);

                if(strcmp((*temp)->data, "dimanche")!=0){
                      printf("%d/%d/%d\t\t", debut.jour, debut.mois, debut.annee);
                      (debut.jour)++;
                       *temp=(*temp)->next;
               }
               else{
                 *temp=l;
                 (debut.jour)++;
                  printf("%d/%d/%d\t", debut.jour, debut.mois, debut.annee);
                 (debut.jour)++;
                 *temp=(*temp)->next;
               }
               switch(choix_5){
                  case 1:
                    printf("    GL\t\t\t\t\t\tGM\n");
                    printf("\t|\t%s\t\t|\t%s\n", module_GL, module_GM);
                    printf("\t\tSalle 2\t\t\t\t\t\tSalle 10\n\n");
                    printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|---------------------------------------------------|\n");
                    printf("\n\t\tHYD\t\t\t\t\t\tID\n");
                    printf("\t|\t%s\t\t|\t%s\n", module_HYD, module_ID);
                    printf("\t\tSalle 4\t\t\t\t\t\tSalle 11 & 12\n\n");
                    printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|---------------------------------------------------|\n");
                    printf("\n\t\tGEER\t\t\t\t\t\tBI\n");
                    printf("\t|\t%s\t\t|\t%s\n", module_GEER, module_BI);
                    printf("\t\tSalle 10 & 11\t\t\t\t\tSalle 2\n\n");
                    printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|---------------------------------------------------|\n");
                    printf("\n\t\tGEE\t\t\t\t\t\tBPC\n");
                    printf("\t|\t%s\t\t|\t%s\n", module_GEE, module_BPC);
                    printf("\t\tSalle 5 & 6\t\t\t\t\tSalle 4\n\n");
                    break;
                 case 2:
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t  GL\t\t\t\t\t\tGM\n");
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t| %s\t\t   |\t%s\n", module_GL, module_GM);
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t       Salle 2\t\t\t\t\t\t    Salle 10\n\n");
                    printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|---------------------------------------------------|\n");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tHYD\t\t\t\t\t\tID\n");
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t| %s\t\t   |\t%s\n", module_HYD, module_ID);
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t       Salle 4   \t\t\t\t\t    Salle 11 & 12\n\n");
                    printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|---------------------------------------------------|\n");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tGEER\t\t\t\t\t\tBI\n");
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t| %s\t\t   |\t%s\n", module_GEER, module_BI);
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t       Salle 10 & 11\t\t\t\t\t     Salle 2\n\n");
                    printf("\t|-----------------------------------------------|-----------------------------------------------|------------------------------------------|---------------------------------------------------|\n");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tGEE\t\t\t\t\t\tBPC\n");
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t| %s\t\t   |\t%s\n", module_GEE, module_BPC);
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t       Salle 5 & 6\t\t\t\t\t     Salle 4\n\n");
                    break;
                }
               printf("\n");
               printf("--------|-----------------------------------------------|-----------------------------------------------|------------------------------------------|---------------------------------------------------|\n");
        Verifier_Date(&debut, temp);
        }
        fclose(GL);
        fclose(GM);
        fclose(HYD);
        fclose(ID);
        fclose(GEER);
        fclose(BI);
        fclose(GEE);
        fclose(BPC);

        return debut;
}

void liste_AP1()
{

    FILE *liste_1=fopen("AP1_Et", "rt");
    if(liste_1==NULL){
        printf("ERROR!\n");
        exit(1);
    }
    char Et_Nom[100], Et_Prenom[100], CNE[100];
    int i, indice=1;

    printf(">>  >>  Liste 1\n");
    printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=30 && (fscanf(liste_1, "%s", CNE)!=EOF);indice++){
            fscanf(liste_1, "%s", Et_Nom);
            fscanf(liste_1, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tSalle 4-Ancien Bloc\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(">>  >>  Liste 2 \n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=60 && (fscanf(liste_1, "%s", CNE)!=EOF);indice++){
            fscanf(liste_1, "%s", Et_Nom);
            fscanf(liste_1, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tSalle 5-Ancien Bloc\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(">>  >>  Liste 3 \n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=90 && (fscanf(liste_1, "%s", CNE)!=EOF);indice++){
            fscanf(liste_1, "%s", Et_Nom);
            fscanf(liste_1, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tSalle 15-Ancien Bloc\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(">>  >>  Liste 4 \n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=120 && (fscanf(liste_1, "%s", CNE)!=EOF);indice++){
            fscanf(liste_1, "%s", Et_Nom);
            fscanf(liste_1, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tSalle 17-Ancien Bloc\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(">>  >>  Liste 5 \n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=190 && (fscanf(liste_1, "%s", CNE)!=EOF);indice++){
            fscanf(liste_1, "%s", Et_Nom);
            fscanf(liste_1, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tAmphi A\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(">>  >>  Liste 6\n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=260 && (fscanf(liste_1, "%s", CNE)!=EOF);indice++){
            fscanf(liste_1, "%s", Et_Nom);
            fscanf(liste_1, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tAmphi B\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
       fclose(liste_1);
       printf("Press any key to escape this Page");
}

void liste_AP2()
{
    FILE *liste_2=fopen("AP2_Et", "rt");
    if(liste_2==NULL){
        printf("ERROR!\n");
        exit(1);
    }
    char Et_Nom[100], Et_Prenom[100], CNE[100];
    int i, indice=1;
    printf(" >>  >>  Liste 1  :\n");
    printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=30 && (fscanf(liste_2, "%s", CNE)!=EOF);indice++){
            fscanf(liste_2, "%s", Et_Nom);
            fscanf(liste_2, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tSalle 4-Ancien Bloc\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(" >>  >>  Liste 2  :\n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=60 && (fscanf(liste_2, "%s", CNE)!=EOF);indice++){
            fscanf(liste_2, "%s", Et_Nom);
            fscanf(liste_2, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tSalle 5-Ancien Bloc\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(" >>  >>  Liste 3  :\n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=90 && (fscanf(liste_2, "%s", CNE)!=EOF);indice++){
            fscanf(liste_2, "%s", Et_Nom);
            fscanf(liste_2, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tSalle 15-Ancien Bloc\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(" >>  >>  Liste 4  :\n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=120 && (fscanf(liste_2, "%s", CNE)!=EOF);indice++){
            fscanf(liste_2, "%s", Et_Nom);
            fscanf(liste_2, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tSalle 17-Ancien Bloc\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }

        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(" >>  >>  Liste 5  :\n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=190 && (fscanf(liste_2, "%s", CNE)!=EOF);indice++){
            fscanf(liste_2, "%s", Et_Nom);
            fscanf(liste_2, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tAmphi A\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
        printf("\nPress any key to see the next LIST\n");
        getch();
        system("cls");
        printf(" >>  >>  Liste 6  :\n");
        printf("_____________________________________________________________________________________________________________________\n");
        for(i=indice;indice<=260 && (fscanf(liste_2, "%s", CNE)!=EOF);indice++){
            fscanf(liste_2, "%s", Et_Nom);
            fscanf(liste_2, "%s", Et_Prenom);
            printf("CNE\t\t\tNom\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("%s\t\t%s %s\n", CNE, Et_Nom, Et_Prenom);
            printf("---------------------------------------------------------------------------------------------------------------------|\n");
            printf("N_place\t\t\tSalle\n");
            printf("--------------|------------------------------------------------------------------------------------------------------|\n");
            printf("    %d\t\t\tAmphi B\n", indice);
            printf("______________|______________________________________________________________________________________________________|\n\n");
        }
       fclose(liste_2);
       printf("Press any key to escape this Page");
}

Box* tab_to_liste(char A[][10], int size)
{
    Box* head=NULL;
    Box* new_elem=NULL;
    Box* last_elem=NULL;
    int i;
    for(i=0;i<size;i++){
        new_elem=(Box*)malloc(sizeof(Box));
        new_elem->data=(char*)malloc(sizeof(char)*10);
        strcpy(new_elem->data,A[i]);
        new_elem->next=NULL;
        if(head==NULL){
            head=new_elem;
        }
        else{
            last_elem->next=new_elem;
        }
        last_elem=new_elem;
    }
    return head;
}

void Saisie_Data(int *session, char *jour, DATE *debut, int *choix_AP, int *choix_5)
{
     
 do{
    printf("Veuiller Saisir:\n\t[ 1 ]---->Session Automne\n\t[ 2 ]---->Session Printemps\nSession: ");
    scanf("%d", &(*session));
 }while((*session)!=1 && (*session)!=2);
    printf(">>> Saisir Date Debut des Examens <<<\n");
    printf("Jour (caractère en miniscule, exemple: lundi): ");
    scanf("%s", jour);
    printf("chiffre: ");
    scanf("%d", &debut->jour);
    printf("Mois: ");
    scanf("%d", &debut->mois);
    printf("Annee: ");
    scanf("%d", &debut->annee);

    printf("\n\nPlus d'Options ----------->> >>\n");
  do{
    printf("Taper:\n\t[ 1 ]-->AP1 matin et AP2 soir\n\t[ 2 ]-->AP2 matin et AP1 soir\nchoix:");
    scanf("%d", &(*choix_AP));
  }while((*choix_AP)!=1 && (*choix_AP)!=2);

  do{
    printf("Taper:\n\t[ 1 ]-->5 eme annee_Matin\n\t[ 2 ]-->5 eme anne_Soir\nchoix: ");
    scanf("%d", &(*choix_5));
  }while((*choix_5)!=1 && (*choix_5)!=2);
  printf("\n\nPress any key to escape this page\n");
}

void Welcome_Message()
{
    printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("                                  >>>    WELCOME                                                                                                                                                \n");
    printf("                                                TO OUR                                                                                                                                                     \n");
    printf("                                                      PROJECT   >>> PLANNIFICATION DES EXAMENS ENSAH                                                    \n");
   printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
   printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n\n\nPress any key to escape this page\n");
}

void EXIT()
{
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t>>>\tTHANK YOU FOR USING OUR APPLICATION\t<<<");
    exit(0);
}

void Planifier_Tout(int session, DATE debut, int choix_AP, int choix_5, Box *temp, Box *l){
  switch(session){
    case 1:
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++[  Plan de AP-1er Semestre  ]+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        AP_S1(debut, choix_AP, l, temp);
        getch();
        system("cls");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++[ Liste AP1 ]+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        liste_AP1();
        getch();
        system("cls");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++[ Liste AP2 ]+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        liste_AP2();
        getch();
        system("cls");
        printf("--------------------------------------------------------------------------[  Plan des 5eme annee-1er Semestre  ]-----------------------------------------------------------------------------------------\n\n");
        debut=cinq_annee(debut, choix_5, l, &temp);
        //1 ET 2 CI
        getch();
        system("cls");

        printf("------------------------------------------------------------[  Plan de 1ere et 2eme annee cycle ingenieur-1er Semestre  ]----------------------------------------------\n\n\n");
        CI_S1(debut, l, temp);
        break;
    case 2:
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++[  Plan de AP-2eme Semestre  ]+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        debut=AP_S2(debut, choix_AP, l, &temp);
        printf("Press any key to escape this Page\n");
        getch();
        system("cls");
         printf("+++++++++++++++++++++++++++++++[ Liste AP1 ]+++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
          liste_AP1();
          getch();
          system("cls");
          printf("+++++++++++++++++++++++++++++++++++++++++++++++++++[ Liste AP2 ]+++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
          liste_AP2();
          getch();
          system("cls");
        //5eme annee
         printf("                  >> >> 5eme annee\n--------------------------------------------------------------------------------->  P.F.E  <----------------------------------------------------------------------------\n");
         printf("Press any key to escape this Page\n");
        //1 et 2 cycle
        getch();
        system("cls");
        printf("---------------------------------------------------------Plan de 1ere et 2eme annee cycle ingenieur-2eme Semestre----------------------------------------------\n\n");
        CI_S2(debut, l, temp);
        break;
  }
  
   
}

int main()
{
    DATE debut;
    int session, choix_AP, choix_5;
    char *choix=(char*)malloc(sizeof(char));
    char jour[10];
    Box* l;
    l=NULL;
    char tab[7][10]={"lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche"};
    l=tab_to_liste(tab, 7);
    Box *temp;
    temp=l;
    Welcome_Message();
    getch();
    system("cls");
    printf("\t\t\t\t\t\t\t**************UNIVERSITE ABDELMALEK ESSAADI*******************\n");
    printf("\t\t\t\t\t\t\t*****Ecole Nationale des Sciences Appliquees d'Al Hoceima*****\n");
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t      ----------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t     | Application de planification des examens a l'ENSAH |\n");
    printf("\t\t\t\t\t\t\t      ----------------------------------------------------\n\n\n");
  
    printf(">>  >>  >> Plan des Examens\n");
    printf("Taper\n");
    printf("\t\t\t\t\t    >>le type de l'examen:\n");
    printf("\t\t\t\t\t\t      ------------------------\n");
    printf("\t\t\t\t\t\t     | [DS] Devoir surveille; |\n");
    printf("\t\t\t\t\t\t     | [EF] Examen final.     |\n");//partie de jamila
    printf("\t\t\t\t\t\t      ------------------------\n");
   do{
    printf("\t\t\t\t\t\t                  >>Choix: ");
    scanf("%s", choix);
   }while((strcmp(choix,"EF")!=0) && (strcmp(choix,"DS")!=0));
   
   
    getch();
    system("cls");
   

    if(strcmp(choix,"EF")==0){
    	Saisie_Data(&session, jour, &debut, &choix_AP, &choix_5);
    	getch();
    	system("cls");
    	while(strcmp(temp->data, jour)!=0){
            temp=temp->next;
		}
        Planifier_Tout(session, debut, choix_AP, choix_5, temp, l);
		}
    if(strcmp(choix,"DS")==0){
	       plannification();
	}
	getch();
    system("cls");
	EXIT();
            

   return 0;
}
	
  
