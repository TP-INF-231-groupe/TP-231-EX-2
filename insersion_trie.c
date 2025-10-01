#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *precedent;
    struct Noeud *suivant;
} Noeud;

Noeud* creer_noeud(int val) {
    Noeud* nouveau = (Noeud*) malloc(sizeof(Noeud));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->valeur = val;
    nouveau->precedent = NULL;
    nouveau->suivant = NULL;
    return nouveau;
}

void inserer_fin(Noeud** tete, int val) {
    Noeud* nouveau = creer_noeud(val);
    if (*tete == NULL) {
        *tete = nouveau;
        return;
    }
    Noeud* temp = *tete;
    while (temp->suivant != NULL)
        temp = temp->suivant;
    temp->suivant = nouveau;
    nouveau->precedent = temp;
}

void afficher_liste(Noeud* tete) {
    Noeud* temp = tete;
    while (temp != NULL) {
        printf("%d <-> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

void trier_liste(Noeud* tete) {
    if (tete == NULL) return;
    int echange;
    Noeud* ptr;
    Noeud* dernier = NULL;
    do {
        echange = 0;
        ptr = tete;
        while (ptr->suivant != dernier) {
            if (ptr->valeur > ptr->suivant->valeur) {
                int temp = ptr->valeur;
                ptr->valeur = ptr->suivant->valeur;
                ptr->suivant->valeur = temp;
                echange = 1;
            }
            ptr = ptr->suivant;
        }
        dernier = ptr;
    } while (echange);
}

void inserer_trie(Noeud** tete, int val) {
    Noeud* nouveau = creer_noeud(val);

    if (*tete == NULL) {
        *tete = nouveau;
        return;
    }

    Noeud* temp = *tete;

    if (val < temp->valeur) {
        nouveau->suivant = temp;
        temp->precedent = nouveau;
        *tete = nouveau;
        return;
    }

    while (temp->suivant != NULL && temp->suivant->valeur < val) {
        temp = temp->suivant;
    }

    nouveau->suivant = temp->suivant;
    if (temp->suivant != NULL)
        temp->suivant->precedent = nouveau;
    temp->suivant = nouveau;
    nouveau->precedent = temp;
}

int main() {
    Noeud* tete = NULL;
    int n = 10, valeur;

    printf("=== Création d'une liste doublement chaînée avec %d éléments ===\n", n);
    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d: ", i+1);
        scanf("%d", &valeur);
        inserer_fin(&tete, valeur);
    }

    printf("\nListe avant tri:\n");
    afficher_liste(tete);

    trier_liste(tete);
    printf("\nListe après tri:\n");
    afficher_liste(tete);

    printf("\nEntrez un élément à insérer dans la liste triée: ");
    scanf("%d", &valeur);
    inserer_trie(&tete, valeur);

    printf("\nListe après insertion de %d:\n", valeur);
    afficher_liste(tete);

    return 0;
}