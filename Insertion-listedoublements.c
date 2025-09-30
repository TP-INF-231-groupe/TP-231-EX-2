#include <stdio.h>
#include <stdlib.h>

typedef struct liste  {
    int data;
    struct liste  *prev, *next;
} liste ;

liste * insererTete(liste  *fin, int val) {
    liste  *n;
    n = (liste *)malloc(sizeof(liste ));
    n->data = val;
    if (!fin) {
        n->next = n->prev = n;
        return n;
    }
    n->next = fin->next;
    n->prev = fin;
    fin->next->prev = n;
    fin->next = n;
    return fin;
}

liste * insererQueue(liste  *fin, int val) {
    liste  *n = malloc(sizeof(liste ));
    n->data = val;
    if (!fin) {
        n->next = n->prev = n;
        return n;
    }
    n->next = fin->next;
    n->prev = fin;
    fin->next->prev = n;
    fin->next = n;
    return n;
}

void afficher(liste  *fin) {
    if (!fin) {
        printf("Liste vide\n");
        return;
    }
    liste  *temp = fin->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != fin->next);
    printf("\n");
}

int main() {
    liste  *fin = NULL;
    printf("Insertion dans une liste doublement chainee circulaire\n");
    printf("Faite un choix :\n");
    
    while(1) {
        int choix, val;
        printf("\n\n--------Votre choix----------\n");
        printf("1. Insertion en tete\n");
        printf("2. Insertion en queue\n");
        printf("0. quitter\n |");
        scanf("%d", &choix);
        if (choix == 0)
         break;
        if (choix == 1) {
            printf("Valeur a inserer : ");
            scanf("%d", &val);
            fin = insererTete(fin, val);
            printf("Valeur inserer en tete de la liste : ");
            
        } else if (choix == 2) {
            
            printf("Valeur a inserer : ");
            scanf("%d", &val);
            fin = insererQueue(fin, val);
            printf("Valeur inserer en Queue de la liste : ");
        } else {
            printf("Choix invalide\n");
            continue;
        }
        afficher(fin);
    }

    return 0;

}
