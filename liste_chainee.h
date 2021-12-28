#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE


typedef struct
{
   int annee;
   int mois;
   int jour;

} date;

typedef struct avion avion;
struct avion
{
     char  code[10];
     int stockage;
     char etat;
     date dateFabrication;
     int NbVol;
     avion *suivant;
};

typedef struct avionListe avionListe;
struct avionListe
{
    avion *tete;
};

avionListe *initialisation(char code[],int stock,char etat,date dateFabrication,int NbVol);
void insertion(avionListe *liste, char code[],int stock,char etat,date dateFabrication,int NbVol);
void suppression(avionListe *liste);
void afficherListe(avionListe *liste);

#endif

