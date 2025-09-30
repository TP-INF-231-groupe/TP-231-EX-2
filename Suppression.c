#include <stdio.h>
#include <stdlib.h>
typedef struct liste {
    int info;
    struct liste *suiv;
}liste;
liste* delete(liste *l){
   int val;
   liste *t = l;
   printf ("Entrez la valeur a supprimer\n");
   scanf("%d", &val);
   if (l == NULL){
    return NULL;
   }
   while(t->suiv != NULL){
        if (t->info == val){
            liste *temp = (liste *)malloc(sizeof(liste));
            temp = t->suiv;
            t->info = temp->info;
            t->suiv = temp ->suiv;
            free(temp);
        }
        else{
            t=t->suiv;
        }
    }
   return l;
}

int main() {
    liste *l = NULL;
    l= delete(l);
    return 0;
}
