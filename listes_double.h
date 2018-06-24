#ifndef LISTES_DOUBLE_H_INCLUDED
#define LISTES_DOUBLE_H_INCLUDED
#include "En_tete/structure.h"

void show_student_filedb(Tld_Etudiant** file);//affichage de la liste d'�tudiant
void GetStudent_liste_simpledb(Tld_Etudiant** file);//r�cuperation des infos d'un �tudiant dans la manipulation par liste simple
void enfilagedb(Tld_Etudiant maillon,Tld_Etudiant** file);//ajout d'un maillon dans la file d'�tudiant
void defilagedb(Tld_Etudiant** file);//suppression d'un �l�ment de la file
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
void liste_simple_tridb(Tld_Etudiant **file,int critere);//tri la file par rapport au crit�re, 0:age; 1:ordre alphab�tique.
//fonctions de tri******************************************************
int taille_filedb(Tld_Etudiant **f);//renvoie la taille de la file
std::string save_default_listedb(Tld_Etudiant **file,std::string nom);//sauvegarde la liste d'�tudiant et renvoi le nom physique du fichier
void restor_datadb(Tld_Etudiant **f);//restauration du fichier d'�tudiant dans la file
void perso_saving_listedb(Tld_Etudiant **f);//sauvegarde personnalis�e de la liste d'�tudiants
void ManByList2(Tld_Etudiant **liste);//fonction principale de manipulation par listes doublement cha�n�e;
#endif // LISTES_DOUBLE_H_INCLUDED
