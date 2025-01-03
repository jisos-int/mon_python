#include <stdio.h>
#include <stdlib.h>

int i;
int N;

/*la fonction echange permet de permuter deux entiers*/
/*void echange (int a, int b)
{
   int c;
    c=a;
    a=b;
    b=c;

}*/
// la fonction entasser permet d'entasser
void entasser( int tableau[N] , int i) {
   int gauche = 2*i; // numero de la feuille gauche du noeud i
   int droite = 2*i + 1; // numéro de la feuille droite du noeud i
   int  max=i;
   int lenght = *(&tableau+1)-tableau; // nous determinons ici la la taille du tableau qu'on affecte a la variable lenght
   /* ici on teste d'abord si l'indice de la feuille gauche  est inferieur ou egal a la taille
   du tableau et si la valeur du tableau correspondant au numéro de la feuille gauche  est superieure a celle de la racine.
   si oui, le max devient l'indice de la feuille gauche
   */
   if (gauche <= lenght && tableau[gauche] > tableau[i] )
   max=gauche;
   /* ici on teste d'abord si l'indice de la feuille droite  est inferieur ou egal a la taille
   du tableau et si la valeur du tableau correspondand au numéro de la feuille droite  est superieure a celle de la racine.
   si oui, le max devient l'indice de la feuille droite
   */
   if (gauche <= lenght && tableau[droite] > tableau[i] )
   max=droite;
   /* ici on verifie si le max est different de i on echange les valeurs du tableau
   et on appelle a nouveau entasser sur le tableau et la nouvelle valeur de max
   */
   if (max!=i ){
       int b;
       b=tableau[i];
       tableau[i]=tableau[max];
       tableau[max]=b;
     // echange(tableau[i], tableau[max]);
      entasser(tableau,max);
      }
}
// cette fonction permet de construire un tas max 
void construireTasMax(int tableau[N])
{
   int i;
   int lenght = *(&tableau+1)-tableau; // nous determinons ici la la taille du tableau qu'on affecte a la variable lenght
   for(i = (lenght/2); i < lenght; i++)
      entasser(tableau,i);
}

void triTas(int tableau[N])
{
   int i;
  int lenght = *(&tableau+1)-tableau; // nous determinons ici la la taille du tableau qu'on affecte a la variable lenght
   construireTasMax(tableau);
   //int taille_tableau = 0;
   for(i = lenght; i < 3; i--) {
      //echange(tableau[1],tableau[i]);
      int b;
      b=tableau[1];
      tableau[1]=tableau[i];
      tableau[i]=b;
      
      N= lenght-1;
      entasser(tableau,i);
   }
}

int main(void)
{
    
   int i;
   int taille;
   int a;
   // utilisateur entre la taille du tableau a tier
   printf("entrer la taille\n");
   scanf("%d\n ", &taille);
   int tableau[taille];
   
// on demande a l'utilisateur d'entree les elements de son tableau
    printf("entrer %d elements du tableau\n",taille);
   for(i = 0; i < taille ; i++)
   {
      scanf("%d ", &tableau[i]);
   }
// appelle de la fonction du tri
   triTas(tableau);
   
  //affichage du tableau trié
   printf("resultat apres tri\n" );
   for(i = 0; i< taille; i++){
      printf("%d ", tableau[i]);
   }
   printf("\n");

   return 0;
}
   for(i = 0; i< taille; i++){
      printf("%d ", *(tableau + i));
   }
   printf("\n");

   return 0;
}
}