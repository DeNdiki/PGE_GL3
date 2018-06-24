#include "fichierh.h"
#include "En_tete/structure.h"
#include "listes_simple.h"

using namespace std;


void show_student_file(Tls_Etudiant** file)//affichage de la liste d'étudiant
{
  int i(0);
  system("cls");
  cout<<"\n\n";
  cout<<"          ===   Affichage des informations de(s) etudiants (LS)   ==="<<endl;
  cout<<"                <--------------------------------------------->\n"<<endl;
  if(*file==NULL)
  {
     cout<<"                Impossible d'afficher, la liste est vide ..."<<endl;
  }
  else
  {
   Tls_Etudiant *pointeur;
   pointeur = *file;
      while(pointeur!=NULL)
      {
        cout<<"    "<<i+1<<"- "<<pointeur->bloc.nom<<" "<<pointeur->bloc.prenom<<" -- "<<pointeur->bloc.jour_naiss<<"/"<<pointeur->bloc.mois_naiss<<"/"<<pointeur->bloc.an_naiss<<" -- "<<pointeur->bloc.poids<<"(Kg)  --   "<<pointeur->bloc.sexe<<" -- "<<pointeur->bloc.matricule<<endl;
        i++;
        pointeur=pointeur->suiv;
      }
  }
  cout<<"\n\n"<<endl;
  cout<<"              Affichage des "<<i<<" etudiant(s) realisee avec succes..."<<endl;
  cout<<"              Appuyez sur une touche pour continuer --->";
  getch();
}
//*********************************************************************

void GetStudent_liste_simple(Tls_Etudiant** file)//récuperation des infos d'un étudiant dans la manipulation par liste simple
{
   Tetudiant etud;
   Tls_Etudiant maillon;
   system("cls");
   cout<<"\n\n";
   cout<<"              ===   Saisie des informations de l'etudiant   ==="<<endl;
   cout<<"                    <----------------------------------->\n"<<endl;
   cout<<"                 Recuperation des informations de l'etudiant "<<endl;
   cout<<"                 ===========================================\n\n";
   cout<<"           Matricule : ";GetInput(etud.matricule,25);
   cout<<"                 Nom : ";GetInput(etud.nom,35);
   cout<<"              Prenom : ";GetInput(etud.prenom,55);
   cout<<"                        Date de naissance de l'etudiant"<<endl;
   GetInteger("Jour",&etud.jour_naiss);
   GetInteger("Mois",&etud.mois_naiss);
   GetInteger("Annee",&etud.an_naiss);
   cout<<"                        Date de naissaince recuperee"<<endl;
   cout<<"                Sexe : ";etud.sexe=GetSex();
   GetInteger("Poids",&etud.poids);
   maillon.bloc=etud;
   maillon.suiv=NULL;
   enfilage(maillon,file);
   cout<<"              ===   Etudiant(e) ajoute(e) avec succes   ==="<<endl;
   cout<<"                 Appuyez sur une touche pour continuer --->";
   getch();
}

void enfilage(Tls_Etudiant maillon,Tls_Etudiant** file)//ajout d'un maillon dans la file d'étudiant
{
   Tls_Etudiant* ptr = new(Tls_Etudiant);//on déclare un autre pointeur temporaire qu'on nomme ptr;
   *ptr = maillon;//on le fait pointer vers notre maillon
   ptr->suiv = NULL;

   if((*file)==NULL)//si la file est vide
       *file=ptr;//on affecte à notre file vide qui comptera désormais un élément
   else
   {
       Tls_Etudiant *pont;
       pont=*file;

       while(pont->suiv!=NULL)
           pont=pont->suiv;//on le fait avancer

       pont->suiv = ptr;//on le fait pointer vers l'élément nouveau
   }
}


void defilage(Tls_Etudiant** file)//suppression d'un élément de la file
{
  if((*file)!=NULL)
  {
      Tls_Etudiant *ptr;
      ptr = (*file);

      (*file) = (*file)->suiv;
      delete(ptr);
  }
}

//*************************************************************************************
//***********************     fonctions de tri      ***********************************

int Divise_Tableau(Tls_Etudiant Tab[], int d, int f, int ind_piv)//sert dans le tri rapide
{
   int i,k;
   Tls_Etudiant pivot,temp;

   pivot=Tab[ind_piv];
   Tab[ind_piv]=Tab[f];
   Tab[f]=pivot;
   k=d;
   for(i=d;i<=f;i++)
   {
       if(Tab[i].bloc.jour_naiss>pivot.bloc.jour_naiss)
       {
           temp=Tab[i];
           Tab[i]=Tab[k];
           Tab[k]=temp;
           k=k+1;
        }
    }
    Tab[f]=Tab[k];
    Tab[k]=pivot;
    return k; // position finale du pivot
}

void TRI_RAPIDE(Tls_Etudiant T[], int deb, int fin)//sert dans le tri rapide
{
   int mon_pivot,indice_pivot;

   if(deb<fin)
   {
       mon_pivot=Alea_Bornes(deb,fin);// choisir un nombre [deb, fin]
       indice_pivot=Divise_Tableau(T,deb,fin,mon_pivot);
       TRI_RAPIDE(T,deb,indice_pivot-1);
       TRI_RAPIDE(T,indice_pivot+1,fin);
    }
}

void tri_jour(Tls_Etudiant tab[],int i)
{
  TRI_RAPIDE(tab,0,i-1);
}

void tri_dicho(Tls_Etudiant tab[],int tail)
{
    int pos,k,borne_sup,borne_inf,milieu;
    Tls_Etudiant x;

    for(pos=1;pos<tail;pos++)
    {
        if(tab[pos].bloc.mois_naiss>tab[pos-1].bloc.mois_naiss)
        {
            borne_inf=0;
            borne_sup=pos-1;
            while(borne_inf!=borne_sup)
            {
                milieu=(borne_inf+borne_sup)/2;
                if(tab[pos].bloc.mois_naiss>=tab[milieu].bloc.mois_naiss)
                  borne_inf=milieu+1;
                else
                  borne_sup=milieu;
            }
            x=tab[pos];
            for(k=pos;k>borne_inf;k--)
              tab[k]=tab[k-1];
            tab[borne_inf]=x;
        }
    }
}

void tri_mois(Tls_Etudiant tab[],int i)
{
    tri_dicho(tab,i);
}

void tri_age(Tls_Etudiant tab[],int i)
{
   tri_jour(tab,i);
   tri_mois(tab,i);
   tri_annee(tab,i);
}

void tri_selor(Tls_Etudiant tab[],int tail)
{
    int i,j;
    Tls_Etudiant tempo;

    for(i=0;i<tail-1;i++)
    {
        j=i;
        for(int k=i+1;k<tail;k++)
        {
            if(tab[k].bloc.an_naiss>tab[j].bloc.an_naiss)
              j=k;
        }
        tempo=tab[i];
        tab[i]=tab[j];
        tab[j]=tempo;
    }
}


void tri_prenom(Tls_Etudiant tab[],int tail,int pos)
{
    Tls_Etudiant x;

    if(pos<tail-1)
    {
        for(int a=tail-1;a>pos;a--)
        {
            if(strcmp(tab[a].bloc.prenom,tab[a-1].bloc.prenom)<0)
            {
                x=tab[a];
                tab[a]=tab[a-1];
                tab[a-1]=x;
            }
        }
        tri_prenom(tab,tail,pos+1);
    }
}

void tri_alpha(Tls_Etudiant tab[],int i)
{
      tri_prenom(tab,i,0);
      tri_nom(tab,i);
}

void tri_nom(Tls_Etudiant tab[],int tail)
{
    int i,j;
    Tls_Etudiant tempo;
    for(i=0;i<tail-1;i++)
    {
        j=i;
        for(int k=i+1;k<tail;k++)
        {
            if(strcmp(tab[k].bloc.nom,tab[j].bloc.nom)<0)
              j=k;
        }
        tempo=tab[i];
        tab[i]=tab[j];
        tab[j]=tempo;
    }
}

void tri_annee(Tls_Etudiant tab[],int i)
{
    tri_selor(tab,i);
}

int taille_file(Tls_Etudiant **f)
{
    int i(0);
    if(*f==NULL)
      return i;
    else
    {
        Tls_Etudiant *pointeur;
        pointeur = *f;
        while(pointeur!=NULL)
         {
             pointeur=pointeur->suiv;
             i++;
         }
    }
    return i;
}

//fonction de tri par âge propement dite
void liste_simple_tri(Tls_Etudiant **file,int critere)
{
    if((*file)!=NULL)
    {
      int i(0),j=taille_file(file);
      Tls_Etudiant tab[j],*ptr;

      while((*file)!=NULL && i<j)
      {
          ptr=*file;
          tab[i].bloc = (*file)->bloc;
          tab[i].suiv = NULL;
          (*file) = (*file)->suiv;
          delete(ptr);
          i++;
      }
      (*file)=NULL;
      switch(critere)
      {
          case 0:tri_age(tab,j);break;
          case 1:tri_alpha(tab,j);break;
      }
      for(int p=0;p<j;p++)
      {
        enfilage(tab[p],(file));
      }
    }
}
//fin de la fonction
//fin de l'implémentation des fonctions de tri...
//sauvegarde de la liste d'étudiant

string save_default_liste(Tls_Etudiant **file,string nom)
{
 ofstream fichier(nom.c_str(),ios::binary|ios::out);
 if(fichier)
  {
    Tetudiant p;
    Tls_Etudiant *tempo = (*file);
    while(tempo!=NULL)
    {
      p = tempo->bloc;
      fichier.write(reinterpret_cast<char *> (&p),sizeof(Tetudiant));
      tempo = tempo->suiv;
    }
    fichier.close();
    return ("             Sauvegarde realisee avec succes,\n             Le fichier porte le nom de : " + nom +" ");
  }
  else
   return ("             Erreur lors de la creation du fichier, veuillez reessayer ...");
}
//------       fin de la sauvegarde
//------       restauration de la liste d'étudiant
void restor_data(Tls_Etudiant **f)
{
   system("cls");
   string name;
   ifstream fichier;
   Tetudiant p;
   Tls_Etudiant po;

   cout<<"\n\n";
   cout<<"              ===   Restauration d'un fichier d'etudiants  ==="<<endl;
   cout<<"                    <----------------------------------->\n"<<endl;
   cout<<"                       Recuperation du nom de fichier"<<endl;
   cout<<"                       ==============================\n\n";
   cout<<"              Entrez le nom du fichier a restaurer : ";
   getline(cin,name);
   if((name.find('.'))<0 ||(name.find('.'))>name.length())
        name.append(".tls");
   if((name.find('.'))== name.length()-1)
        name.append("tls");
   cout<<"              Restauration en cours ";
   for(int k=0;k<5;k++)
     {
       cout<<". \a";
       delay(1);
     }
   cout<<"\n";
   fichier.open(name.c_str(),ios::in|ios::binary);
   if(fichier)
   {
     fichier.seekg(0,ios::end);//on se positionne à la fin du fichier
     if(fichier.tellg()%sizeof(Tetudiant) == 0)//on calcule la taille totale des données pour voir si c'est un multiple d'un tuple TLs_etudiant
     {
       while((*f)!=NULL)
        defilage(f);

       fichier.seekg(0,ios::beg);//on se repositionne au début
       while(!fichier.eof())
       {
            fichier.read(reinterpret_cast<char *> (&p), sizeof(Tetudiant));
            if(fichier.gcount()== sizeof(Tetudiant))
            {
              po.bloc = p;
              po.suiv = NULL;
              enfilage(po,f);
            }
       }
       fichier.close();
       cout<<"              Restauration realisee avec succes...\n";
     }
     else
     {
       cout<<"              Restauration Avortee...\n";
       cout<<"              Les donnees presentes dans le fichier sont insuffisantes\n";
     }
       cout<<"              Appuyez sur une touche ---> ";
   }
   else
   {
       cout<<"              Impossible de realiser la restauration, veuillez reessayer SVP ...\n";
       cout<<"              "<<name<<endl;
       cout<<"              Appuyez sur une touche ---> ";
   }
   getch();
}
//------       fin de la restauration
//------       Sauvegarde personnalisée
void perso_saving_liste(Tls_Etudiant **f)
{
 char touche;
 do
 {
   system("cls");
   cout<<"\n\n";
   cout<<"              ===   Sauvegarde des informations des etudiants   ==="<<endl;
   cout<<"                    <--------------------------------------->\n"<<endl;
   cout<<"                 Recuperation du Nom de Fichier de sauvegarde  "<<endl;
   cout<<"                 ============================================\n\n";
   cout<<"                 1 - Entrer le nom du fichier.\n";
   cout<<"                 2 - Quitter.\n\n";
   cout<<"                              Votre choix : ";
   do
   {
       touche=toupper(getch());
   }
   while((touche!='1') && (touche!='2'));
   cout<<touche<<endl;
   switch(touche)
   {
     case '1':
     {
         string name;

         cout<<"                 Entrer le nom du fichier (sans extension) : ";
         getline(cin,name);
         if((name.find('.'))<0 ||(name.find('.'))>name.length())
            name.append(".tls");
         if((name.find('.'))== name.length()-1)
            name.append("tls");
         cout<<"\n";
         cout<<"                 Sauvegarde en cours ";
         for(int k=0;k<5;k++)
         {
           cout<<". \a";
           delay(1);
         }
         cout<<"\n";
         cout<<save_default_liste(f,name);
         getch();
     }break;

     case '2':{}break;
   }
 }
 while(touche!='2');
 cout<<"              Appuyer sur une touche ---> ";
 getch();
}
//------       fin
//***********************            fin            ***********************************
