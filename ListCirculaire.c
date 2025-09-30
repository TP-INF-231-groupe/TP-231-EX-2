#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct listElement{
    int valeur;
    struct listElement *suivant;
}listElement, *Liste;

Liste New_list(void){
   return NULL;
}

bool Liste_vide(Liste li){
   if (li == NULL)
        return true;      
   return false;     
}

void Affich_list(Liste li){
    listElement *temp = li;
    if(Liste_vide(li)){
        printf("La liste est vide pour le moment.\n");
        return;
      } 
    else{
        printf(":::->");
       while(temp != NULL){
         printf("[%d]->",temp->valeur);
         temp = temp->suivant;
        }
       temp = li; 
      printf("[%d]->:::",temp->valeur);
     return;
     }
  }
    int Taille_list(Liste li){
     int size;
     if(Liste_vide(li)){
         return 0;
     }
     else{
       size = 1;
         while(li->suivant!=NULL){
            li = li->suivant;
            size++;
         }
        return size; 
      }
    }
Liste Ajout_tete(Liste li,int x){
    listElement *element;
    element = malloc(sizeof(*element));
        if(element == NULL){
            printf("erreur d'allocation.");
            exit(1);
        }
    element->valeur = x;
      if(Liste_vide(li))
         element->suivant = NULL;     
        else
         element->suivant= li;  
      return element;  
   } 
   
  Liste Ajout_queu(Liste li,int x){
    listElement *temp;
    listElement *element;
    element = malloc(sizeof(*element));
        if(element == NULL){
            printf("erreur d'allocation.");
            exit(1);
        }
    element->valeur = x;
    element->suivant = NULL;
     if(Liste_vide(li)){
         return element;     
        }
        else{
            temp = li;
            while(temp->suivant!=NULL)
                temp = temp->suivant;    
             temp->suivant= element;
            return li;
           }     
        }
        
int main(){
  int x,choix=0;
  Liste malist = New_list();
    printf("1- affichage.\n");
    printf("2- ajout en tête.\n");
    printf("3- ajout en queu.\n");
    printf("4- taille de la liste.\n"); 
    printf("0- sortir.\n");  
   do{
    printf("Quel est votre choix: ");
    scanf("%d",&choix);
  switch(choix){
     case 1: Affich_list(malist);
         break;
     case 2: printf("Entrez l'élément a ajouter en tête: ");
             scanf("%d",&x);
             malist = Ajout_tete(malist,x);
           break;
     case 3: printf("Entrez l'élément a ajouter en queu: ");
             scanf("%d",&x);
             malist = Ajout_queu(malist,x);
           break;              
     case 4: printf("La taille de la liste est T = %d .\n",Taille_list(malist));
           break;           
     case 0: printf("merci.");
         break;
       }
       
      printf("\n");
      
    }while(choix!=0);
    
       return 0;
             
 }
