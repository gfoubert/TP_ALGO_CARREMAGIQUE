#include <stdio.h>
#include <stdlib.h>

#define TAILLE_TABLEAU 7

//Definir la taille du tableau

//BUT:Faire un carré magique qui fait en sorte que  la somme de chaque ligne horizontale, de chaque colonne verticale et de chaque diagonale est égale à un même nombre S (qu'on appelle la somme magique)
//ENTRÉE: La constante du Taille Tableau
//SORTIE: Affichage du carré magique
typedef struct Point Point;
struct Point
{
    int x;  //On créer structure point avec valeurs x et y
    int y;
};

int a,b,c,nombre,trouve;

nombre=1;       //variable qui ira dans le tableau
trouve=0;          //booléen
Point position;     //création d'un point qu'on nomme position

carre[TAILLE_TABLEAU][TAILLE_TABLEAU];  //On définit le tableau par rapport à la constante définie au début du programme

int main()  //procédure qui remplie le tableau
{
init();

avancer();

afficher();    //procédure qui affiche le tableau

}



//BUT: Placement des nombres et replacement si on dépasse les bords du carré
//ENTRÉE:
//SORTIE: Les nombres sont correctement placés et une fois qu'on dépasse le bord du carré on revient de l'autre côté
void avancer(){
position.x=((TAILLE_TABLEAU/5)-1); //Départ intial sur la cellule au nord par rapport au milieu
position.y=(TAILLE_TABLEAU/5);

carre[position.x][position.y]=nombre;   //On associe la valeur 1
for(c=0;c<(TAILLE_TABLEAU*TAILLE_TABLEAU)-1;c++){   //la boucle se répète autant de fois qu'il faut placer un nombre

    nombre++;
    position.x--;
    position.y++;
//on ajoute 1 et on avance au nord-est du milieu

    if (position.x<0){
            position.x=TAILLE_TABLEAU-1;

                    }
//une fois arrivé en haut on revient en bas

    if (position.y>TAILLE_TABLEAU-1){
            position.y=0;

                                    }
//une fois arrivé à droite on revient à gauche

    if (carre[position.x][position.y]==0){
    carre[position.x][position.y]=nombre;

                                        }
//si case valide (0), on place le nombre
    else{
        do {
        position.x--;
        position.y--;
// si case non valide alors on se déplace au nord ouest jusqu'à une case valide

         if (position.x<0){
            position.x=TAILLE_TABLEAU-1;
//si on dépasse en haut on revient en bas

                           }

     else if (position.y<0){
            position.y=TAILLE_TABLEAU-1;
//si on dépasse à gauche on revient à droite

                            }

            }while(carre[position.x][position.y]!=0);
        }

carre[position.x][position.y]=nombre;

}

}

//BUT:Afficher les cellules
//ENTRÉE:
//SORTIE: Affichage des cellules
void afficher(){

for(a=0;a<TAILLE_TABLEAU;a++){
for(b=0;b<TAILLE_TABLEAU;b++){
if (b!=TAILLE_TABLEAU-1){
        printf("%d  ",carre[a][b]);
}
else {
 printf("%d\n",carre[a][b]);
 //On affiche les cellules grâce aux boucles
}

}

}
}

//BUT:Initialiser le tableau
//ENTRÉE: Taille du tableau initialisé plus haut
//SORTIE:Initialisation du tableau
void init(){

for(a=0;a<TAILLE_TABLEAU;a++){
for(b=0;b<TAILLE_TABLEAU;b++){
carre[a][b]=0;
//Initialisation du tableau

}

}

}
