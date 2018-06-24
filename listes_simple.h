#ifndef LISTES_SIMPLE_H_INCLUDED
#define LISTES_SIMPLE_H_INCLUDED

void show_student_file(Tls_Etudiant** file);//affichage de la liste d'�tudiant
void GetStudent_liste_simple(Tls_Etudiant** file);//r�cuperation des infos d'un �tudiant dans la manipulation par liste simple
void enfilage(Tls_Etudiant maillon,Tls_Etudiant** file);//ajout d'un maillon dans la file d'�tudiant
void defilage(Tls_Etudiant** file);//suppression d'un �l�ment de la file
//fonctions de tri******************************************************
int Divise_Tableau(Tls_Etudiant Tab[], int d, int f, int ind_piv);//sert dans le tri rapide
void TRI_RAPIDE(Tls_Etudiant T[], int deb, int fin);//sert dans le tri rapide
void tri_jour(Tls_Etudiant tab[],int i);
void tri_dicho(Tls_Etudiant tab[],int tail);
void tri_mois(Tls_Etudiant tab[],int i);
void tri_selor(Tls_Etudiant tab[],int tail);
void tri_prenom(Tls_Etudiant tab[],int tail,int pos);
void tri_alpha(Tls_Etudiant tab[],int i);
void tri_nom(Tls_Etudiant tab[],int tail);
void tri_annee(Tls_Etudiant tab[],int i);
void tri_age(Tls_Etudiant tab[],int i);
void liste_simple_tri(Tls_Etudiant **file,int critere);//tri la file par rapport au crit�re, 0:age; 1:ordre alphab�tique.
//fonctions de tri******************************************************
int taille_file(Tls_Etudiant **f);//renvoie la taille de la file
std::string save_default_liste(Tls_Etudiant **file,std::string nom);//sauvegarde la liste d'�tudiant et renvoi le nom physique du fichier
void restor_data(Tls_Etudiant **f);//restauration du fichier d'�tudiant dans la file
void perso_saving_liste(Tls_Etudiant **f);//sauvegarde personnalis�e de la liste d'�tudiants
#endif // LISTES_SIMPLE_H_INCLUDED
