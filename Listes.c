
#include "Listes.h"
#include <stdio.h>
#include <stdlib.h>
Liste New_Liste ( int lenghs ) 
{
    Liste L = (Liste) malloc ( sizeof(elt) ) ;
    printf ("Entrer la valeur de element 1 :") ;
    scanf ("%f", &L->x ) ;
    Liste temp = L ;
    for ( int i = 1 ; i<lenghs ; i++ ){
        Liste le = (Liste) malloc ( sizeof(elt) ) ;
        printf ("Entrer la valeur de element 1 :") ;
        scanf ("%f", &le->x ) ;
        temp->next = le ;
        temp = temp->next ;
    }
    int cl ;
    printf("Voulez vous que la liste soit circulaire \n 1- OUI \n 2- NON \n ");
    scanf ("%d", &cl );
    if ( cl == 1 )
        temp->next = L ;
    else
        temp->next = NULL ;
    return L ; 
}

void Affiche_Liste ( Liste L )
{
    if ( L == NULL )
        printf ("La liste est vide \n");
    Liste temp = L ;
    do {
        printf(" -[%f]- ", temp->x) ;
        temp = temp->next ;
    }while ( temp != NULL ) ;
}
