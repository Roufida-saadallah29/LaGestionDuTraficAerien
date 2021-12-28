#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste_chainee.h"
#include <time.h>
#include<windows.h>

#define B 1000

#define lar 160

void color(int couleurDuTexte,int couleurDeFond)
{
    /*fonction d'affichage de couleurs*/

    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


void gotoxy(int a, int b)
{
        COORD c;

        c.X=a;
        c.Y=b;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/***********************************************************************************
*
*                            GESTION MENU et Affichage
*
************************************************************************************/

void printf_encadre(char chaine []) /*Procédure qui permet d'afficher un texte tout en l'encadrant*/
{
    int cpt=0,i=0,j=0;
    int pgl=0;
    for(i=0;i<strlen(chaine);i++)
   {         cpt++;
            if (chaine[i]=='.'){
            if (cpt>pgl){
            pgl=cpt;
            }
            cpt=0;
        }
    }
       printf("\n ");
    for (i=0;i<(pgl+1);i++){
        printf("_");
    }
    printf("\n|");
    for (i=0;i<(pgl+1);i++){
        printf(" ");
    }
    printf("|\n");
    cpt=0;
    printf("|");
    for(i=0;i<strlen(chaine);i++){
        printf("%c", chaine[i]);
        cpt++;
        if (chaine[i]=='.'){
                for (j=0;j<(pgl-cpt+1);j++){
                    printf(" ");
                }
                printf("|\n|");
                cpt=0;
    }
}
    for (i=0;i<(pgl+1);i++){
        printf("_");
    }
    printf("|\n");
}
void printf_centre (const char* str) /*Procédure qui permet d'imprimer un texte centré sur la console*/
{
    int n,v;
    v=(lar-strlen(str)) / 2;
    for (n = 0; n < v; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
    for (n=(v+strlen(str)); n< 166;n++){
        putchar(' ');
    }
}

void MI(int x,int y) /*Procédure qui permet d'afficher le mot "ESI" sur la console*/
{
    color(1,0);
    gotoxy(x,y);
    printf("   \333\333");
    gotoxy(x,y+1);
    printf("    \333 ");
    gotoxy(x,y+2);
    printf("    \333");
    gotoxy(x,y+3);
    printf("    \333");
    gotoxy(x,y+4);
    printf("    \333");
    Sleep(500);
    ///////////////////
    gotoxy(x+8,y);
    printf("\333\333        \333\333");
    gotoxy(x+8,y+1);
    printf("\333 \333      \333 \333");
    gotoxy(x+8,y+2);
    printf("\333  \333    \333  \333");
    gotoxy(x+8,y+3);
    printf("\333   \333  \333   \333");
    gotoxy(x+8,y+4);
    printf("\333    \333\333    \333");



    ///////////////////////
    Sleep(500);
    gotoxy(x+22,y);
    printf("\333");
    gotoxy(x+22,y+1);
    printf("\333");
    gotoxy(x+22,y+2);
    printf("\333");
    gotoxy(x+22,y+3);
    printf("\333");
    gotoxy(x+22,y+4);
    printf("\333");

	color(15,0);
}
void printf_cadremenu(int x1, int x2, int y1,int y2,int col) /*Procédure qui affiche un cadre d'une couleur spécifiée sur la console*/
{
	int a,k;
	color(col,0);
	k=x2;
	for(a=x1;a<x2;a++){
	gotoxy(a,y2);
	printf("\333\333");
	gotoxy(k,y1);
	printf("\333\333");
	k--;
	Sleep(1);
	}
	k=y2;
	for(a=y1;a<y2;a++){
	gotoxy(x1,a);
	printf("\333\333");
	gotoxy(x2,k);
	printf("\333\333");
	k--;
	Sleep(1);
	}
	color(15,0);
}
void menu_principal()
{
                 color(14,0);
                gotoxy(22,3);
                printf("\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
                gotoxy(22,4);
                printf("\t\t\t    %c MENU PRINCIPAL %c",186,186);
                gotoxy(22,5);
                printf("\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                color(15,16);
                gotoxy(25,7);
                printf ("\t Faites votre choix de la liste suivante :\n\n");
                gotoxy(25,9);
                printf ("\t [1] :");   printf(" Remplir la liste des avions\n");
                gotoxy(25,11);
                printf ("\t [2] : Verifier si un avion est dans l’aeroport\n");
                gotoxy(25,13);
                printf ("\t [3] : Supprimer les avions plus de 20 ans\n");
                gotoxy(25,15);
                printf ("\t [4] : Trier la liste des avions\n");
                gotoxy(25,17);
                printf ("\t [5] :  Afficher la liste des avions\n");
                gotoxy(25,19);
                printf ("\t [0] : Quitter \n\n\n");
                printf_cadremenu(15,100,1,25,14);
                gotoxy(25,22);
                printf("Entrez votre choix: ");
}

void menu_secondaire()
{
                 color(14,0);
                gotoxy(22,3);
                printf("\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
                gotoxy(22,4);
                printf("\t\t\t    %c MENU AFFICHAGE  %c",186,186);
                gotoxy(22,5);
                printf("\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                color(15,16);
                gotoxy(22,7);
                printf ("\t Faites votre choix de la liste suivante :\n\n");
                gotoxy(22,9);
                printf ("\t [1] :");   printf(" La liste des avions decolles\n");
                gotoxy(22,11);
                printf ("\t [2] : La liste des avions atterris\n");
                gotoxy(22,13);
                printf ("\t [3] : La liste des avions en maintenance\n");
                gotoxy(22,15);
                printf ("\t [4] : La liste des avions qui ont assure le max des vols et ages - de 10 ans\n");
                gotoxy(22,17);
                printf ("\t [5] :  Liste des avions qui ont assure le min des vols et ages - de 10 ans \n");
                gotoxy(22,19);
                printf ("\t [6] :  Revenir au menu principal \n");
                gotoxy(22,21);
                printf ("\t [0] : Quitter \n\n\n");
                printf_cadremenu(15,105,1,25,14);
                gotoxy(25,22);
                printf("Entrez votre choix: ");
}
void intro() /*Procédure qui affiche des informations sur le travail entrepris*/
{   gotoxy(1,10);
	color(7,0);
	printf_centre("Mini projet");
	gotoxy(1,11);
	color(12,0);
	printf_centre("La gestion du trafic aerien");
	gotoxy(1,14);
	color(7,0);
	Sleep(500);
	printf_centre("Ce travail vous est presente par:");
	Sleep(1000);
	gotoxy(1,16);
	color(11,0);
	printf_centre("     SAADALLAH        ");
	gotoxy(1,17);
	printf_centre("ROUFIDA ");
	gotoxy(1,20);
	color(7,0);
	Sleep(1000);
	printf_centre("Matiere: Algorithmique et structures de donnees");
	MI(75,23);
	gotoxy(1,30);
	color(9,0);
	//printf_centre("~Universite de Saida  Dr. Moulay Tahar ~");
	gotoxy(1,35);
	color(7,0);
	//printf_centre("Annee universitaire: 2020/2021");
	printf_cadremenu(50,110,8,37,7);
	Sleep(1000);
}
void message_attente() /*Procédure qui affiche un message sur la console pour inviter l'utilisateur à appuyer sur une touche pour continuer*/
{
    printf("\n");
    system("pause");
    system("cls");
    }
void printf_point(int a)
{
    color(a,0);
    printf("\333\333");
    color(15,0);
}
void message_de_fin(){
	int x=106,y=20,n,v;
	gotoxy(60,20);
	printf("Vous avez choisi de quitter le menu principal");
 	for(n=0;n<2;n++){
	gotoxy(x,y);
	printf(".");
	Sleep(500);
	gotoxy(x,y);
	printf(" ");
	gotoxy(x+1,y);
	printf(".");
	Sleep(500);
	gotoxy(x+1,y);
	printf(" ");
	gotoxy(x+2,y);
	printf(".");
	Sleep(500);
	gotoxy(x+2,y);
	printf(" ");
	}
	v=1;
	for(x=62;x<130;x++){
		gotoxy(x,y);
		printf("Vous avez choisi de quitter le menu principal");
		Sleep(50);
		system("cls");
		gotoxy(v,y);
		printf("Merci pour votre attention.");
		v++;
	}
	gotoxy(1,40);
}

/***********************************************************************************
*
*                             Creation de la liste
*
************************************************************************************/


/************************  Creation de L'entete **************************************/

avionListe *initialisation(char code[],int stock,char etat,date dateFabrication,int NbVol)
{
    avionListe *avionListe = malloc(sizeof(*avionListe));
    avion *Avion = malloc(sizeof(*Avion));

    if (avionListe == NULL || Avion == NULL)
    {
        exit(EXIT_FAILURE);
    }



    strcpy(Avion->code,code);
    Avion->stockage=stock;
    Avion->etat=etat;
    Avion->dateFabrication=dateFabrication;
    Avion->NbVol=NbVol;
    Avion->suivant=NULL;
    avionListe->tete=Avion;
    return avionListe;
}

/************************* insertion dans l'entet ****************************************/

void insertion(avionListe *avionListe,char code[],int stock,char etat,date dateFabrication,int NbVol)
{
    /* Création du nouvel élément */
    avion *nouveau = malloc(sizeof(*nouveau));
    if (avionListe == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nouveau->code,code);
    nouveau->stockage=stock;
    nouveau->etat=etat;
    nouveau->dateFabrication=dateFabrication;
    nouveau->NbVol=NbVol;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = avionListe->tete;
    avionListe->tete=nouveau;
}
/***************************************************************** Creation de la liste des avions *********************************************************/
avionListe *Creation_Avion()
{
    int i, N;
    int m, t;
    char end;
    avionListe *Maliste;
/******************* les donnees******************/
    char code[10];
    int stock;
    char etat;
    date aj;
    int nbvols;
/**********************************************/
  printf("\n ***************************** Remplir la liste des avions *******************\n\n");
    printf("\n%c",218);
    for (m=0;m<40;m++)      printf("%c",196);
    printf("%c",191);
    printf("%c",218);
    for (m=0;m<20;m++)      printf("%c",196);
    printf("%c",191);
    printf("\n%c",179);
    printf("        Entrer le nombre d'avion:       ");
    printf("%c%c",179,179);
    for (m=0;m<20;m++)      printf(" ");
    printf("%c",179);
    printf("\n%c",192);
    for (m=0;m<40;m++)      printf("%c",196);
    printf("%c",217);
    printf("%c",192);
    for (m=0;m<20;m++)      printf("%c",196);
    printf("%c",217);
    do {

    gotoxy(45,5);
    scanf("%d", &N);

      } while (N <= 0);
    printf("\n\n");
    printf("introduire les informations des avions\n");
    for(i=0;i<N;i++)
    {
        printf("\n******************************* avion %d    ***************\n",i+1);
        /***************************code*******************/
         printf("\n%c",218);
         for (m=0;m<28;m++)      printf("%c",196);
         printf("%c",191);
         printf("%c",218);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",191);
         printf("\n%c",179);
         printf("  le code d'avion:          ");
         printf("%c%c",179,179);
         for (m=0;m<20;m++)      printf(" ");
         printf("%c",179);
         printf("\n%c",192);
         for (m=0;m<28;m++)      printf("%c",196);
         printf("%c",217);
         printf("%c",192);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",217);
         gotoxy(33,13+18*i);
         scanf("%s",code);
        /***********************stockage ***********/
         printf("\n%c",218);
         for (m=0;m<28;m++)      printf("%c",196);
         printf("%c",191);
         printf("%c",218);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",191);
         printf("\n%c",179);
         printf("  la capacite de stockage   ");
         printf("%c%c",179,179);
         for (m=0;m<20;m++)      printf(" ");
         printf("%c",179);
         printf("\n%c",192);
         for (m=0;m<28;m++)      printf("%c",196);
         printf("%c",217);
         printf("%c",192);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",217);
         gotoxy(33,16+18*i);
         scanf("%d",&stock);
        /*************************etat******************/
         scanf ("%c", &end);
         printf("\n%c",218);
         for (m=0;m<28;m++)      printf("%c",196);
         printf("%c",191);
         printf("%c",218);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",191);
         printf("\n%c",179);
         printf("  L'etat ( D/A/M)           ");
         printf("%c%c",179,179);
         for (m=0;m<20;m++)      printf(" ");
         printf("%c",179);
         printf("\n%c",192);
         for (m=0;m<28;m++)      printf("%c",196);
         printf("%c",217);
         printf("%c",192);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",217);

         do
         {
            gotoxy(33,19+18*i);
           if(end=='\n')
          {
            scanf("%c",&etat);
          }
          scanf("%c",&end);
         }while((etat!='A')&&(etat!='D')&&(etat!='M'));
         /********************** La date de fabrication **********************/
          printf("\n%c",218);
          for (m=0;m<28;m++)      printf("%c",196);
          printf("%c",191);
          printf("%c",218);
          for (m=0;m<20;m++)      printf("%c",196);
          printf("%c",191);
          printf("\n%c",179);
          printf("  la date de fabrication    ");
          printf("%c%c",179,179);
          for (m=0;m<20;m++)      printf(" ");
          printf("%c",179);
          printf("\n%c",192);
          for (m=0;m<28;m++)      printf("%c",196);
          printf("%c",217);
          printf("%c",192);
          for (m=0;m<20;m++)      printf("%c",196);
          printf("%c",217);
          gotoxy(33,22+18*i);
          printf("jj-mm-aaaa");
          do
          {

           gotoxy(33,22+18*i);
           printf("jj-mm-aaaa");
           gotoxy(33,22+18*i);
           scanf("%d",&aj.jour);
          }while((aj.jour>31)||(aj.jour<0));
          do
          {
           /*gotoxy(70,11);
           printf("les jours ne depasse pas 31\n");*/
           gotoxy(35,22+18*i);
           printf("-mm-aaaa");
           gotoxy(36,22+18*i);
           scanf("%d",&aj.mois);
          }while((aj.mois>12)||(aj.mois<0));
          do
          {
           /*gotoxy(70,11);
           printf("les jours ne depasse pas 31\n");*/

           gotoxy(39,22+18*i);
           scanf("%d",&aj.annee);
          }while((aj.annee>2021)||(aj.annee<1800));
         /************************le nombre de vols assures*****************/
           printf("\n%c",218);
           for (m=0;m<28;m++)      printf("%c",196);
           printf("%c",191);
           printf("%c",218);
           for (m=0;m<20;m++)      printf("%c",196);
           printf("%c",191);
           printf("\n%c",179);
           printf("  le nombre de vols assures ");
           printf("%c%c",179,179);
           for (m=0;m<20;m++)      printf(" ");
           printf("%c",179);
           printf("\n%c",192);
           for (m=0;m<28;m++)      printf("%c",196);
           printf("%c",217);
           printf("%c",192);
           for (m=0;m<20;m++)      printf("%c",196);
           printf("%c",217);
           gotoxy(33,25+18*i);
           scanf("%d",&nbvols);
/*****************************************************************/
           printf("\n");
           if(i==0)
           {
              Maliste=initialisation(code,stock,etat,aj,nbvols);
           }
           else
            insertion(Maliste,code,stock,etat,aj,nbvols);
    }
    return Maliste;

}
/*****************************************Supprimer les avions ages de plus de 20 ans et qui sont actuellement en maintenance technique*******************/
void suppression(avionListe *liste)
{
    date aujourdhui;
    time_t now;
    time(&now);
    struct tm *local=localtime(&now);
    aujourdhui.annee=local->tm_year+1900;
    aujourdhui.mois=local->tm_mon+1;
    aujourdhui.jour=local->tm_mday;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->tete != NULL)
    {

        int trouv=0;
       // if(liste->tete->stockage==4)
        if((aujourdhui.annee-liste->tete->dateFabrication.annee>20)||((aujourdhui.annee-liste->tete->dateFabrication.annee==20)&&(aujourdhui.mois> (liste->tete->dateFabrication.mois)))||((aujourdhui.annee-liste->tete->dateFabrication.annee==20)&&(aujourdhui.mois== (liste->tete->dateFabrication.mois))&&(aujourdhui.jour>(liste->tete->dateFabrication.jour))))
        {
            if(liste->tete->etat=='M')
            {
              avion *aSupprimer = liste->tete;
              liste->tete = liste->tete->suivant;
              free(aSupprimer);
            }
        }
        avion *q=liste->tete;
        avion *p=NULL;
          while(q!=NULL  )
          {
            p=q;
            q=q->suivant;
            if(q!=NULL)
            {
             if((aujourdhui.annee-q->dateFabrication.annee>20)||((aujourdhui.annee-q->dateFabrication.annee==20)&&(aujourdhui.mois> (q->dateFabrication.mois)))||((aujourdhui.annee-q->dateFabrication.annee==20)&&(aujourdhui.mois== (q->dateFabrication.mois))&&(aujourdhui.jour>(q->dateFabrication.jour))))
            {
                if(q->etat=='M')
                {
                 p->suivant=q->suivant;
                 free(q);
                 q=p->suivant;
                }

             }
            }

           }
    }

}
/************************************ Fonctions d'affichage **************************************/

  /*------------------------------------------------------------ affichage iteratif ------------------------------------------------------*/

void afficherListeItera(avionListe *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    avion *actuel = liste->tete;
    char stocka[13];
    int m;
    char dat[13];
    char nbvol[10];
    printf("\n");
    while (actuel != NULL)
    {

         printf("%c",218);
         for (m=0;m<28;m++)      printf("%c",196);
         printf("%c",191);

         printf("\n%c",179);
         printf("    code     = %s",actuel->code);
         for(m=0;m<13-strlen(actuel->code);m++)  printf(" ");
         printf("%c",179);
         printf("\n%c",179);
         sprintf(stocka,"%d",actuel->stockage);
         printf("    stockage = %d",actuel->stockage);
         for(m=0;m<13-strlen(stocka);m++) printf(" ");
         printf("%c",179);
         printf("\n%c",179);
         printf("    etat     = %c            ",actuel->etat);
         printf("%c",179);
         printf("\n%c",179);
         sprintf(dat,"%d-%d-%d",actuel->dateFabrication.jour,actuel->dateFabrication.mois,actuel->dateFabrication.annee);
         printf("    date     = %s",dat);
         for(m=0;m<13-strlen(dat);m++) printf(" ");
         printf("%c",179);
         printf("\n%c",179);
         sprintf(nbvol,"%d",actuel->NbVol);
         printf("    Nbvol    = %d",actuel->NbVol);
         for(m=0;m<13-strlen(nbvol);m++) printf(" ");
         printf("%c",179);
         printf("\n%c",192);
         for (m=0;m<28;m++)      printf("%c",196);
         printf("%c",217);
         printf("\n");
         printf("              |             \n");
         printf("              |             \n");
         printf("              v             \n");
        actuel = actuel->suivant;
    }
         printf("            NULL\n");
}
  /*----------------------------------------------------  affichage recursif ------------------------------------------------------*/

void affiche_liste_rec(avion *liste)
{
    char stocka[13];
    int m;
    char dat[13];
    char nbvol[10];
    if(liste!=NULL)
    {

                   printf("%c",218);
                   for (m=0;m<28;m++)      printf("%c",196);
                   printf("%c",191);

                   printf("\n%c",179);
                   printf("    code     = %s",liste->code);
                   for(m=0;m<13-strlen(liste->code);m++)  printf(" ");
                   printf("%c",179);
                   printf("\n%c",179);
                   sprintf(stocka,"%d",liste->stockage);
                   printf("    stockage = %d",liste->stockage);
                   for(m=0;m<13-strlen(stocka);m++) printf(" ");
                   printf("%c",179);
                   printf("\n%c",179);
                   printf("    etat     = %c            ",liste->etat);
                   printf("%c",179);
                   printf("\n%c",179);
                   sprintf(dat,"%d-%d-%d",liste->dateFabrication.jour,liste->dateFabrication.mois,liste->dateFabrication.annee);
                   printf("    date     = %s",dat);
                   for(m=0;m<13-strlen(dat);m++) printf(" ");
                   printf("%c",179);
                   printf("\n%c",179);
                   sprintf(nbvol,"%d",liste->NbVol);
                   printf("    Nbvol    = %d",liste->NbVol);
                   for(m=0;m<13-strlen(nbvol);m++) printf(" ");
                   printf("%c",179);
                   printf("\n%c",192);
                   for (m=0;m<28;m++)      printf("%c",196);
                   printf("%c",217);
                   printf("\n");
                   printf("              |             \n");
                   printf("              |             \n");
                   printf("              v             \n");

               affiche_liste_rec(liste->suivant);
    }
}



/**************************************** Trier la liste des avions par ordre croissant des capacites de stockage ********************************/

void permuter(avion* elemt1, avion* elemt2)
{
    /*permet de permuter entre 2 maillons d'avion*/
     avion *p;
     date aj;
     char code[10];
     strcpy(code,elemt1->code);
     int stock=elemt1->stockage;
     int nbvol=elemt1->NbVol;
     char etat=elemt1->etat;
     aj=elemt1->dateFabrication;
     strcpy(elemt1->code,elemt2->code);
     elemt1->stockage=elemt2->stockage;
     elemt1->etat=elemt2->etat;
     elemt1->dateFabrication=elemt2->dateFabrication;
     elemt1->NbVol=elemt2->NbVol;
     strcpy(elemt2->code,code);
     elemt2->stockage=stock;
     elemt2->etat=etat;
     elemt2->dateFabrication=aj;
     elemt2->NbVol=nbvol;


}

void trier_Liste( avionListe *liste )
{
    /*permet de trier une liste d'avion selon le principe du tri a bulles*/

 if(liste->tete !=NULL)
  {
	int cpt;

    avion *queu;
    avion *P=liste->tete;
    while(P!= NULL)
    {
         queu=P;
         P=P->suivant;

    }

	do {
		 P = liste->tete;
		 cpt = 0 ;
		 while (P != queu)
		 {
		  if ( (P->stockage)>(P->suivant->stockage))
            {
			 permuter(P,P->suivant) ;
			 cpt++;
			}
	        P = P->suivant ;
	      }
       } while (cpt != 0) ;
  }

}
/**************************************************** Le nombre Max et Min de vols ***************************************/

 /*------------------------------------------------------ le nombre maximal des vols assurres  ------------------------------------------------------*/
int MaxNbvol( avionListe *liste )
{
    int Max;
    int m,i;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    avion *actuel = liste->tete;
    Max=actuel->NbVol;
    while (actuel != NULL)
    {
        if((actuel->NbVol)>Max)
        {
            Max=actuel->NbVol;
        }
        actuel = actuel->suivant;
    }
   return Max;
}
/*------------------------------------------------------ le nombre minimal des vols assurres  ------------------------------------------------------*/
int MinNbvol( avionListe *liste )
{
    int Min;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    avion *actuel = liste->tete;
    Min=actuel->NbVol;
    while (actuel != NULL)
    {
        if((actuel->NbVol)<Min)
        {
            Min=actuel->NbVol;
        }
        actuel = actuel->suivant;
    }
   return Min;
}
/************************************************** Affichage de question6 ***********************************************/

void AvionMaxvolMoins10ans(avionListe *liste) //afficher La liste des avions qui ont assur´e le max des vols et ag´es - de 10 ans
{
    int Max=MaxNbvol(liste);
    date aujourdhui;
    time_t now;
    time(&now);
    struct tm *local=localtime(&now);
    aujourdhui.annee=local->tm_year+1900;
    aujourdhui.mois=local->tm_mon+1;
    aujourdhui.jour=local->tm_mday;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    avion *actuel = liste->tete;
    char stocka[13];
    int m;
    char dat[13];
    char nbvol[10];
    printf("\n");
    while (actuel != NULL)
    {
       if((actuel->NbVol==Max))
       {
                if((aujourdhui.annee-actuel->dateFabrication.annee<10)||((aujourdhui.annee-actuel->dateFabrication.annee==10)&&(aujourdhui.mois< (actuel->dateFabrication.mois)))||((aujourdhui.annee-actuel->dateFabrication.annee==10)&&(aujourdhui.mois== (actuel->dateFabrication.mois))&&(aujourdhui.jour<(actuel->dateFabrication.jour))))
                {
                   printf("%c",218);
                   for (m=0;m<28;m++)      printf("%c",196);
                   printf("%c",191);

                   printf("\n%c",179);
                   printf("    code     = %s",actuel->code);
                   for(m=0;m<13-strlen(actuel->code);m++)  printf(" ");
                   printf("%c",179);
                   printf("\n%c",179);
                   sprintf(stocka,"%d",actuel->stockage);
                   printf("    stockage = %d",actuel->stockage);
                   for(m=0;m<13-strlen(stocka);m++) printf(" ");
                   printf("%c",179);
                   printf("\n%c",179);
                   printf("    etat     = %c            ",actuel->etat);
                   printf("%c",179);
                   printf("\n%c",179);
                   sprintf(dat,"%d-%d-%d",actuel->dateFabrication.jour,actuel->dateFabrication.mois,actuel->dateFabrication.annee);
                   printf("    date     = %s",dat);
                   for(m=0;m<13-strlen(dat);m++) printf(" ");
                   printf("%c",179);
                   printf("\n%c",179);
                   sprintf(nbvol,"%d",actuel->NbVol);
                   printf("    Nbvol    = %d",actuel->NbVol);
                   for(m=0;m<13-strlen(nbvol);m++) printf(" ");
                   printf("%c",179);
                   printf("\n%c",192);
                   for (m=0;m<28;m++)      printf("%c",196);
                   printf("%c",217);
                   printf("\n");
                   printf("              |             \n");
                   printf("              |             \n");
                   printf("              v             \n");
                }

       }

        actuel = actuel->suivant;
    }
                   printf("            NULL\n");
}

void AvionMinvolMoin10ans(avionListe *liste) // afficher Liste des avions qui ont assur´e le min des vols et ag´es - de 10 ans
{
    int Min=MinNbvol(liste);
    date aujourdhui;
    time_t now;
    time(&now);
    struct tm *local=localtime(&now);
    aujourdhui.annee=local->tm_year+1900;
    aujourdhui.mois=local->tm_mon+1;
    aujourdhui.jour=local->tm_mday;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    avion *actuel = liste->tete;
    char stocka[13];
    int m;
    char dat[13];
    char nbvol[10];
    printf("\n");
    while (actuel != NULL)
    {
       if((actuel->NbVol==Min))
       {
                if((aujourdhui.annee-actuel->dateFabrication.annee<10)||((aujourdhui.annee-actuel->dateFabrication.annee==10)&&(aujourdhui.mois< (actuel->dateFabrication.mois)))||((aujourdhui.annee-actuel->dateFabrication.annee==10)&&(aujourdhui.mois== (actuel->dateFabrication.mois))&&(aujourdhui.jour<(actuel->dateFabrication.jour))))
                {
                   printf("%c",218);
                   for (m=0;m<28;m++)      printf("%c",196);
                   printf("%c",191);

                   printf("\n%c",179);
                   printf("    code     = %s",actuel->code);
                   for(m=0;m<13-strlen(actuel->code);m++)  printf(" ");
                   printf("%c",179);
                   printf("\n%c",179);
                   sprintf(stocka,"%d",actuel->stockage);
                   printf("    stockage = %d",actuel->stockage);
                   for(m=0;m<13-strlen(stocka);m++) printf(" ");
                   printf("%c",179);
                   printf("\n%c",179);
                   printf("    etat     = %c            ",actuel->etat);
                   printf("%c",179);
                   printf("\n%c",179);
                   sprintf(dat,"%d-%d-%d",actuel->dateFabrication.jour,actuel->dateFabrication.mois,actuel->dateFabrication.annee);
                   printf("    date     = %s",dat);
                   for(m=0;m<13-strlen(dat);m++) printf(" ");
                   printf("%c",179);
                   printf("\n%c",179);
                   sprintf(nbvol,"%d",actuel->NbVol);
                   printf("    Nbvol    = %d",actuel->NbVol);
                   for(m=0;m<13-strlen(nbvol);m++) printf(" ");
                   printf("%c",179);
                   printf("\n%c",192);
                   for (m=0;m<28;m++)      printf("%c",196);
                   printf("%c",217);
                   printf("\n");
                   printf("              |             \n");
                   printf("              |             \n");
                   printf("              v             \n");
                }

       }

        actuel = actuel->suivant;
    }
                   printf("            NULL\n");
}
/**************************************************************************************************/

void Diviser_LaListe(avionListe *liste, avionListe **listD,avionListe **listA,avionListe **listM)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    int cpt1=0,cpt2=0,cpt3=0;
    avion *actuel = liste->tete;
    while (actuel != NULL)
    {
        if((actuel->etat)=='D')
        {
            if(cpt1==0)
            {
                *listD=initialisation(actuel->code,actuel->stockage,actuel->etat,actuel->dateFabrication,actuel->NbVol);
            }
            else
            {
                insertion(*listD,actuel->code,actuel->stockage,actuel->etat,actuel->dateFabrication,actuel->NbVol);
            }
             cpt1++;
        }
        else
        {
          if((actuel->etat)=='A')
          {
            if(cpt2==0)
            {
                *listA=initialisation(actuel->code,actuel->stockage,actuel->etat,actuel->dateFabrication,actuel->NbVol);
            }
            else
            {
                insertion(*listA,actuel->code,actuel->stockage,actuel->etat,actuel->dateFabrication,actuel->NbVol);
            }
             cpt2++;
          }
          else
          {
             if((actuel->etat)=='M')
             {
              if(cpt3==0)
              {
                *listM=initialisation(actuel->code,actuel->stockage,actuel->etat,actuel->dateFabrication,actuel->NbVol);
              }
              else
              {
                insertion(*listM,actuel->code,actuel->stockage,actuel->etat,actuel->dateFabrication,actuel->NbVol);
              }
             cpt3++;
             }
          }
        }
        actuel = actuel->suivant;
    }
}

/*int nbelement(avionListe *liste)
{
    int nb=0;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        nb++;
        actuel = actuel->suivant;
    }
   return nb;
}
void supp(Liste *liste)
{
    int n=nbelement(liste);
    for(int i=0;i<n;i++)
    {
        suppression(liste);
    }
}*/
int Verifier(avionListe *liste,char code[])
{
    avion *p = liste->tete;
    if(p==NULL)
    {
        return -1;
    }
    int trv=0;
     while(p != NULL)
    {
      if(strcmp(p->code,code)==0)
      {
          trv=1;
        break;
      }
     p = p->suivant;
    }
    if(trv)
    {
        return 1;
    }
    else
        return -1;
}

void esi()
{
   //system("color f0");
    printf("\n\n\n\n\n\t  \333\333\333\333\333\333\333\333\333\333\333\n"
    "\t \333\333\333\333\333\333\333\333\333\333\333\333\333\n"
    "\t\333\333\333\333         \333\333\n"
    "\t\333\333\333\333         \333\333\n"
    "\t\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\n"
    "\t\333\333\333\333\333\333\333\333\333\333\333\333\333\333\n"
    "\t\333\333\333\333\n"
    "\t \333\333\333\333\333\333\333\333\333\333\333\333\333\n"
    "\t  \333\333\333\333\333\333\333\333\333\333\333\n");
    gotoxy(33,6);
    printf("  \333\333\333\333\333\333\333\333\333\333\333\333\333");
    gotoxy(33,7);
    printf(" \333\333\333\333\333\333\333\333\333\333\333\333\333\333\333");
    gotoxy(33,8);
    printf("\333\333\333\333");
    gotoxy(33,9);
    printf("\333\333\333\333");
    gotoxy(33,10);
    printf("\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333");
    gotoxy(33,11);
    printf(" \333\333\333\333\333\333\333\333\333\333\333\333\333\333\333");
    gotoxy(33,12);
    printf("            \333\333\333\333");
    gotoxy(33,13);
    printf("\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333");
    gotoxy(33,14);
    printf(" \333\333\333\333\333\333\333\333\333\333\333\333\333");
    gotoxy(60,6);
    printf("\333\333\333\333\333\333");
    gotoxy(60,7);
    printf("\333\333\333\333\333\333");

    gotoxy(60,9);
    printf("\333\333\333\333\333\333");
    gotoxy(60,10);
    printf("\333\333\333\333\333\333");
    gotoxy(60,11);
    printf("\333\333\333\333\333\333");
    gotoxy(60,12);
    printf("\333\333\333\333\333\333");
    gotoxy(60,13);
    printf("\333\333\333\333\333\333");
    gotoxy(60,14);
    printf("\333\333\333\333\333\333\n");
    gotoxy(1,18);
    printf("-----------------< Ecole nationale superieure d'informatique >------------------");
    gotoxy(21,22);
    system("pause");
    char s[1000];
    system("cls");
                sprintf(s,"\n           (_\\     /_) ""\n"
            "             ))   (( ""\n"
            "          .-'''''''''-.  ""\n"
            "      /^\\/   _.   _.   \\/^\\ ""\n"
            "      \\(    /__\\ /__\\    )/ ""\n"
            "        \\,  \\o_/_\\o_/  ,/ ""\n"
            "          \\    (_)    / ""\n"
            "           `-.'==='.-' ""\n"
            "            __) - (__ ""\n"
            "           /  `~~~`  \\ ""\n"
            "          /  /     \\  \\ ""\n"
            "          \\ :       ; / ""\n"
            "           \\|==(*)==|/ ""\n"
            "            :       : ""\n"
            "             \\  |  / ""\n"
            "           ___)=|=(___ ""\n"
            "          {____/ \\____} \n\n\n\n        ");
            printf("%s",s);
}
