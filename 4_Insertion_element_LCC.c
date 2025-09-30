#include <stdio.h>
#include <stdlib.h>

// ---------- Definition de la structure -------------
typedef struct element {
    float x ;
    struct element * next ;
} elt , *Liste ;

// --------------- Prototype ----------------

Liste New_Liste ( int lenghs ) 
{
    Liste L = (Liste) malloc ( sizeof(elt) ) ;
    if ( L == NULL ){
        printf (" Erreur d'allocation \n") ;
        exit (1) ;
    }
    printf ("Entrer la valeur de element 1 :") ;
    scanf ("%f", &L->x ) ;
    Liste temp = L ;
    for ( int i = 1 ; i<lenghs ; i++ ){
        Liste le = (Liste) malloc ( sizeof(elt) ) ;
        if ( le == NULL ){
            printf (" Erreur d'allocation \n") ;
            exit (1) ;
        }   
        printf ("Entrer la valeur de element 1 :") ;
        scanf ("%f", &le->x ) ;
        temp->next = le ;
        temp = temp->next ;
    }
    temp->next = L ;
    return L ; 
}

void Affiche_Liste ( Liste L )
{
    if ( L == NULL )
        printf ("La liste est vide \n");
    else {
    Liste temp = L ;
    {
        do {
            printf(" -[%.2f]- ", temp->x) ;
            temp = temp->next ;
            }while ( temp != L ) ;
            printf("\n") ;
        }
    }
}

// Insertion d'un element en tete ou en queue 
Liste Insert ( Liste L )
{
    int ch ;
    Liste temp = L, Lcc = (Liste) malloc ( sizeof(elt) ) ;
    if ( Lcc == NULL ){
        printf (" Erreur d'allocation \n") ;
        exit (1) ;
    }
    printf ("Entrez lelement que vous souhaitez inserer \n ") ;
    scanf ("%f", &Lcc->x ) ;
    Lcc->next = L ;
    do {
        temp = temp->next ;
    }while (temp->next != L) ;
    temp->next = Lcc ;
    printf ("Voulez vous inserer en tete ou en queue de la liste :\n 1-Tete \n 2- Queue \n ") ;
    scanf ("%d", &ch ) ;
    if ( ch = 1 )
        return Lcc ;
    else if ( ch = 2 )
        return L ;
    printf ("Valeur incorrecte \n ") ;
}

// ---------Fonction principale ------------
int main () 
{
    int nb, choix ;
    Liste Lc = NULL ;
    printf ("       ====== MENU ====== \n");
    printf (" 1- Creation d'une liste chainee circulaire \n") ;
    printf (" 2- Affichage d'une liste chainee circulaire \n") ;
    printf (" 3- Insertion d'un element dans une liste chainee circulaire \n") ;
    printf (" 0- Sortir \n\n ") ;
    do 
    {    
        printf (" Faites un choix  \n") ;
        scanf ("%d", &choix ) ;
        switch ( choix )  
        {
            case 1 :
                printf("Entrer le nombre de cellule de la liste ( minimum deux ) \n ") ;
                scanf ("%d", &nb ) ;
                if ( nb <= 1 ) {
                    printf (" Nombre de cellule incorrecte pour une liste chainee circulaire \n ") ;
                }else {
                    Lc = New_Liste ( nb ) ;
                }
                break ;
            case 2 :
                Affiche_Liste ( Lc ) ;
                break ;
            case 3 :
                Lc = Insert ( Lc ) ;
                break ;
            default : printf ("Valeur incorrecte \n ") ;
        }
    }while ( choix != 0 ) ;          

    return 0 ;   
}