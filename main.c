#include <stdio.h>
#include <stdlib.h>

#define TAILLE_TABLEAU 7

//Definir la taille du tableau

//BUT:Faire un carr� magique qui fait en sorte que  la somme de chaque ligne horizontale, de chaque colonne verticale et de chaque diagonale est �gale � un m�me nombre S (qu'on appelle la somme magique)
//ENTR�E: La constante du Taille Tableau
//SORTIE: Affichage du carr� magique
typedef struct Point Point;
struct Point
{
    int x;  //On cr�er structure point avec valeurs x et y
    int y;
};

int a,b,c,nombre,trouve;

nombre=1;       //variable qui ira dans le tableau
trouve=0;          //bool�en
Point position;     //cr�ation d'un point qu'on nomme position

carre[TAILLE_TABLEAU][TAILLE_TABLEAU];  //On d�finit le tableau par rapport � la constante d�finie au d�but du programme

int main()  //proc�dure qui remplie le tableau
{
init();

avancer();

afficher();    //proc�dure qui affiche le tableau

}



//BUT: Placement des nombres et replacement si on d�passe les bords du carr�
//ENTR�E:
//SORTIE: Les nombres sont correctement plac�s et une fois qu'on d�passe le bord du carr� on revient de l'autre c�t�
void avancer(){
position.x=((TAILLE_TABLEAU/5)-1); //D�part intial sur la cellule au nord par rapport au milieu
position.y=(TAILLE_TABLEAU/5);

carre[position.x][position.y]=nombre;   //On associe la valeur 1
for(c=0;c<(TAILLE_TABLEAU*TAILLE_TABLEAU)-1;c++){   //la boucle se r�p�te autant de fois qu'il faut placer un nombre

    nombre++;
    position.x--;
    position.y++;
//on ajoute 1 et on avance au nord-est du milieu

    if (position.x<0){
            position.x=TAILLE_TABLEAU-1;

                    }
//une fois arriv� en haut on revient en bas

    if (position.y>TAILLE_TABLEAU-1){
            position.y=0;

                                    }
//une fois arriv� � droite on revient � gauche

    if (carre[position.x][position.y]==0){
    carre[position.x][position.y]=nombre;

                                        }
//si case valide (0), on place le nombre
    else{
        do {
        position.x--;
        position.y--;
// si case non valide alors on se d�place au nord ouest jusqu'� une case valide

         if (position.x<0){
            position.x=TAILLE_TABLEAU-1;
//si on d�passe en haut on revient en bas

                           }

     else if (position.y<0){
            position.y=TAILLE_TABLEAU-1;
//si on d�passe � gauche on revient � droite

                            }

            }while(carre[position.x][position.y]!=0);
        }

carre[position.x][position.y]=nombre;

}

}

//BUT:Afficher les cellules
//ENTR�E:
//SORTIE: Affichage des cellules
void afficher(){

for(a=0;a<TAILLE_TABLEAU;a++){
for(b=0;b<TAILLE_TABLEAU;b++){
if (b!=TAILLE_TABLEAU-1){
        printf("%d  ",carre[a][b]);
}
else {
 printf("%d\n",carre[a][b]);
 //On affiche les cellules gr�ce aux boucles
}

}

}
}

//BUT:Initialiser le tableau
//ENTR�E: Taille du tableau initialis� plus haut
//SORTIE:Initialisation du tableau
void init(){

for(a=0;a<TAILLE_TABLEAU;a++){
for(b=0;b<TAILLE_TABLEAU;b++){
carre[a][b]=0;
//Initialisation du tableau

}

}

}
