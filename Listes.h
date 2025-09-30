#ifndef LISTES_H
#define LISTES_H

// ---------- Definition de la structure -------------
    typedef struct element {
        float x ;
        struct element * next ;
    } elt , *Liste ;

// --------------- Prototype ----------------

    void Affiche_Liste ( Liste ) ;
    Liste New_Liste ( int ) ;

#endif