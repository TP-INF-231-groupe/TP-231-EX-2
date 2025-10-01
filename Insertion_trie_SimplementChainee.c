#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;            
    struct Node *next;   
} Node;

Node* creerNoeud(int valeur) {
    Node *nouveau = (Node*)malloc(sizeof(Node));
    if (nouveau == NULL) {
        printf("Erreur d’allocation memoire !\n");
        exit(1);
    }
    nouveau->data = valeur;
    nouveau->next = NULL;
    return nouveau;
}
Node* insererTrie(Node *tete, int valeur) {
    Node *nouveau = creerNoeud(valeur);

    if (tete == NULL || valeur < tete->data) {
        nouveau->next = tete;
        tete = nouveau;
        return tete;
    }

    Node *temp = tete;
    while (temp->next != NULL && temp->next->data < valeur) {
        temp = temp->next;
    }

    nouveau->next = temp->next;
    temp->next = nouveau;

    return tete;
}
void afficherListe(Node *tete) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Node *temp = tete;
    printf("Liste : ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void libererListe(Node *tete) {
    Node *temp;
    while (tete != NULL) {
        temp = tete;
        tete = tete->next;
        free(temp);
    }
}

int main() {
    Node *tete = NULL;
    int n, i, valeur;

    printf("Combien d elements voulez-vous inserer initialement (dans l ordre croissant) ? \n ");
    scanf("%d", &n);

    printf("Entrez les elements tries (ordre croissant) :\n");
    for (i = 0; i < n; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &valeur);
        tete = insererTrie(tete, valeur); 
    }

    printf("\nListe initiale triee :\n");
    afficherListe(tete);

   
    printf("\nEntrez la valeur a inserer dans la liste triee : ");
    scanf("%d", &valeur);

    tete = insererTrie(tete, valeur);

    printf("\nListe apres insertion de %d :\n", valeur);
    afficherListe(tete);

    libererListe(tete);

    return 0;
}
