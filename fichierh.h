#ifndef FICHIERH_H_INCLUDED
#define FICHIERH_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "En_tete/structure.h"
#include <cstdlib>
#include <windows.h>
#include <conio2.h>

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

// fonction de manipulation des couleurs
void textcolor (int color);
void textbackground (int color);
//fin

//fonction permettant de patienter
void delay(float temps);
//fin

//récupérer éfficacement les saisies en vidant le buffer
void EmptyBuffer();
int GetInput(char *chaine, int longueur);
void GetInteger(std::string mot,UI *entier);
//fin

//affichage des memus
void menuprincipal();
void gestionpartab(int i);
void gestionpartls(std::string a);
void Apropos();
//fin

//gestion par tableau
bool ArrayEmpty(Tetudiant tab[]);//teste si un tableau et vide ou pas
std::string save_default_array(Tetudiant tab[],int a,std::string nom);//permet de suavegarder le contenu d'un tableau dans un fichier
void init_array(Tetudiant tab[]);//initialise le tableau pour faire des tests après
void ManByArray0152(Tetudiant tab[],int i,Tindex petit_tab[]);//fonction globale de manipulation par tableau
void show_student_array(Tetudiant tab[],int i);//affiche le tableau d'étudiants
void perso_saving_array(Tetudiant tab[],int i);//sauvegarde personnalisée
char save_mode();//mode de sauvegarde
void not_save();//affichage de l'impossibilité de la réalisation de la sauvegarde
void restor_data(Tetudiant tab[],int i,Tindex petit_tab[]);//affichage de l'impossibilité de la réalisation de la sauvegarde
void tri_insert_sequen(Tindex tab[],int n);//tri par insertion séquentielle
void index_poids(Tetudiant tab[],int tail,Tindex petit_tab[]);//affichage des étudiants par l'index de poids
void tri_jour(Tetudiant tab[],int i);
void tri_mois(Tetudiant tab[],int i);
void tri_annee(Tetudiant tab[],int i);
 int Alea_Bornes(int a, int b);
int Divise_Tableau(Tetudiant Tab[], int d, int f, int ind_piv);
void TRI_RAPIDE(Tetudiant T[], int deb, int fin);
void tri_dicho(Tetudiant tab[],int tail);
void tri_selor(Tetudiant tab[],int tail);
void gestion_index(Tetudiant tab[],int i,Tindex petit_tab[]);
void transfert(Tetudiant tab[],int i,Tindex petit_tab[]);//transfert les poids et les indices des étudiants le tableau des index.
void gestion_tri_age(Tetudiant tab[],int i,Tindex petit_tab[]);//tri le tableau d'étudiant par age
void tri_age(Tetudiant tab[],int i);
void tri_prenom(Tetudiant tab[],int i,int pos);
void tri_nom(Tetudiant tab[],int i);
void tri_alpha(Tetudiant tab[],int i);
void gestion_tri_alpha(Tetudiant tab[],int i,Tindex petit_tab[]);
bool compare_array(const char t1[],const char t2[]);
void majiscule(Tetudiant tab[],int i);//met tous les noms et prenoms du tableau en majiscules
void not_save(std::string a);
void sauvegarde_tableau(Tetudiant tab[],int i);//sauvegarde du tableau
//fin

//gestion par liste simple
void ManByList1(Tls_Etudiant **liste);
//fin

//recupération des données
char GetSex();//recupération du sexe (M|F)
Tetudiant GetStudent(int i,int taille);//recupération d'un étudiant
void saisie_etudiant_tableau(Tetudiant tab[],int i,Tindex petit_tab[]);
//fin

//fonction de centralisation
void corps(char touche,Tetudiant tab[],Tindex petit_tab[],int taille_tableau,Tls_Etudiant **liste,Tld_Etudiant **liste_double);//fonction d'éxécution principale.
void deroulement();//déroulement principale du programme.
//fin
//--------------------------------------
#endif // FICHIERH_H_INCLUDED
