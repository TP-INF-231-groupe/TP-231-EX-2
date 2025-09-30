#include <stdio.h>
#include "Listes.h"

int main () 
{
    int nb ;
    Liste Lc ;
    printf("Entrer le nombre de cellule de la liste \n ") ;
    scanf ("%d", &nb ) ;
    Lc = New_Liste ( nb ) ;
    Affiche_Liste ( Lc ) ;
    return 0 ;
        

}
