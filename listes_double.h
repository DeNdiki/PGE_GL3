#ifndef LISTES_DOUBLE_H_INCLUDED
#define LISTES_DOUBLE_H_INCLUDED
#include "En_tete/structure.h"

void show_student_filedb(Tld_Etudiant** file);//affichage de la liste d'étudiant
void GetStudent_liste_simpledb(Tld_Etudiant** file);//récuperation des infos d'un étudiant dans la manipulation par liste simple
void enfilagedb(Tld_Etudiant maillon,Tld_Etudiant** file);//ajout d'un maillon dans la file d'étudiant
void defilagedb(Tld_Etudiant** file);//suppression d'un élément de la file
//fonctions de tri******************************************************
int Divise_Tableaudb(Tld_Etudiant Tab[], int d, int f, int ind_piv);//sert dans le tri rapide
void TRI_RAPIDEdb(Tld_Etudiant T[], int deb, int fin);//sert dans le tri rapide
void tri_jourdb(Tld_Etudiant tab[],int i);
void tri_dichodb(Tld_Etudiant tab[],int tail);
void tri_moisdb(Tld_Etudiant tab[],int i);
void tri_selordb(Tld_Etudiant tab[],int tail);
void tri_prenomdb(Tld_Etudiant tab[],int tail,int pos);
void tri_alphadb(Tld_Etudiant tab[],int i);
void tri_nomdb(Tld_Etudiant tab[],int tail);
void tri_anneedb(Tld_Etudiant tab[],int i);
void tri_agedb(Tld_Etudiant tab[],int i);
void liste_simple_tridb(Tld_Etudiant **file,int critere);//tri la file par rapport au critère, 0:age; 1:ordre alphabétique.
//fonctions de tri******************************************************
int taille_filedb(Tld_Etudiant **f);//renvoie la taille de la file
std::string save_default_listedb(Tld_Etudiant **file,std::string nom);//sauvegarde la liste d'étudiant et renvoi le nom physique du fichier
void restor_datadb(Tld_Etudiant **f);//restauration du fichier d'étudiant dans la file
void perso_saving_listedb(Tld_Etudiant **f);//sauvegarde personnalisée de la liste d'étudiants
void ManByList2(Tld_Etudiant **liste);//fonction principale de manipulation par listes doublement chaînée;
#endif // LISTES_DOUBLE_H_INCLUDED
