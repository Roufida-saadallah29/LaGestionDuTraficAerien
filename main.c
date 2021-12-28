#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"
#include "liste_chainee.c"

int main()
{
        avionListe *av=NULL;
    avionListe *A=NULL;
    avionListe *M=NULL;
    avionListe *D=NULL;
        //system("cls");
     intro();
    // Ecrire sur la premiére page esi
   gotoxy(1,40);
   system("pause");

  while (1)
 {
    system("cls");
   menu_principal();
   int choix;
   scanf("%d",&choix);
        if (choix == 0)
            break;
   switch(choix)
   {
    case 1:
    {
           system("cls");
        av=Creation_Avion();
        system("pause");
        system("cls");
        printf("\n*************************** La liste est : ********************\n\n");
        afficherListeItera(av);
    }
    break;
    case 2:
    {
           system("cls");
        if(av!=NULL)
        {
          printf("**************************** Verifier si un avion est dans l'aeroport **********************\n\n\n");
          char code[10];
          printf("donner le code \n");
          scanf("%s",code);
          int ver;
          ver=Verifier(av,code);
          if(ver==1)
          {
              printf("\n\n\nl'avion de code ----- %s ----- est dans l'aeroport\n\n\n ",code);
          }
          else
          {
              if(ver==-1)
              {
                  printf("\n\n\n l'avion n'est pas dans l'aeroport ----- %d ----\n\n\n",ver);
              }
          }
          //system("pause");
        }
        else
        {
                  printf("la liste est null\n");
                  break;
        }
    }
    break;
    case 3:
    {
        system("cls");
        if(av!=NULL)
        {
            suppression(av);
            printf("\n*************************** La liste apres la supression : ********************\n\n");
            afficherListeItera(av);
        }
        else
        {
                  printf("la liste est null\n");
                  break;
        }
    }
        break;
    case 4:
    {
           system("cls");
        if(av!=NULL)
        {
          trier_Liste(av);
          printf("\n*************************** La liste apres le trie : ********************\n\n");
          afficherListeItera(av);
        }
        else
        {
                  printf("la liste est null\n");
                  break;
        }

    }
    break;
    case 5:
        {
               system("cls");
            if(av!=NULL)
            {
              while(1)
             {
                system("cls");
                Diviser_LaListe(av,&D,&A,&M);
                //system("pause");
                menu_secondaire();
                int choice;
                scanf("%d",&choice);
                system("cls");
                if(choice==6)
                    break;
                if (choice == 0)
                   return 0;
                switch(choice)
                {
                    case 1:
                        {
                            printf("\n********************** La liste des avions decolles **************\n\n");
                            if(D!=NULL)
                              afficherListeItera(D);
                            else
                                printf("La liste est null\n\n\n");
                            system("pause");

                        }
                        break;
                    case 2:
                        {
                            printf("\n****************** La liste des avions atterris  (traitement recursif) *****************\n\n");

                            if(A!=NULL)
                              affiche_liste_rec(A->tete);
                            else
                                printf("La liste est null\n\n\n");
                            system("pause");
                        }
                        break;
                    case 3:
                        {
                            printf("\n******************** La liste des avions en maintenance ********************\n\n");
                            if(M!=NULL)
                              afficherListeItera(M);
                            else
                                printf("La liste est null\n\n\n");
                            system("pause");
                        }
                        break;
                    case 4:
                        {
                            printf("\n************* La liste des avions qui ont assure le max des vols et ages - de 10 ans *********\n\n");
                            AvionMaxvolMoins10ans(av);
                            system("pause");
                        }
                        break;
                    case 5:
                        {
                            printf("\n************* La liste des avions qui ont assure le max des vols et ages - de 10 ans *********\n\n");
                            AvionMinvolMoin10ans(av);
                            system("pause");
                        }
                        break;

                }

            }
            }
         else
              {
                  printf("la liste est null\n");
                  break;
              }

        }
        break;
                    default:
                        {
                          gotoxy(25,22);
                          printf("SVP ENTRER UN AUTRE CHOIX\n");
                          printf("\n\n\n");
                          gotoxy(25,28);
                        }

                         break;

   }
  system("pause");
 }
 system("cls");


    return 0;
}

