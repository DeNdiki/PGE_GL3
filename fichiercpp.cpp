#include "fichierh.h"
#include "En_tete/structure.h"
#include "listes_simple.h"
#include "listes_double.h"

using namespace std;


void textcolor (int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),color + (__BACKGROUND << 4));
}

void delay(float temps)
{
    clock_t arrivee=clock()+(temps*CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arrêter

    while(clock()<arrivee);
}

void textbackground (int color)
{
    __BACKGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),__FOREGROUND + (color << 4));
}

//fonction permettant de vider le buffer en cas de dépassement au moment de la saisie de l'utilisateur
void EmptyBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
//fin de cette fonction

//fonction de lecture sécurisée
int GetInput(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            EmptyBuffer();
        }
        return 1;
    }
    else
    {
        EmptyBuffer();
        return 0;
    }
}
//fin de cette fonction


void GetInteger(string mot,UI *entier)
{
  bool ok(false);
  string ligne;

  cout<<"                "<<mot<<" : ";
  while(!ok) do
  {
      getline(cin,ligne);
      istringstream tampon (ligne);
      if(tampon >> (*entier))
       ok=true;
      else
      {
          ok=false;
          cout<<"                Information incorrecte - donnez un nombre entier"<<endl;
          cout<<"                "<<mot<<" : ";
      }
  }
 while(!ok);
}

void menuprincipal()
{
            system("cls");cout<<"\n\n\n\n\a"<<endl;
            cout<<"                            ANNEE SCOLAIRE 2012-2013"<<endl;
            cout<<"                       PROGRAMME DE GESTION DES ETUDIANTS"<<endl;
            cout<<"\n"<<endl;
            cout<<"                       ----------MENU PRINCIPAL----------"<<endl;
            cout<<"\n"<<endl;
            cout<<"                       1-gestion par tableau"<<endl;
            cout<<"                       2-gestion par liste chainee simple"<<endl;
            cout<<"                       3-gestion par liste doublement chainee"<<endl;
            cout<<"                       4-apropos"<<endl;
            cout<<"                       5-sortir du programme"<<endl;
            cout<<"\n"<<endl;
            cout<<"                       Votre Choix:  ";
}


void corps(char touche,Tetudiant tab[],Tindex petit_tab[],int taille_tableau,Tls_Etudiant **liste,Tld_Etudiant **liste_double)
{
       switch(touche)
       {
           case '1':
           {
              ManByArray0152(tab,taille_tableau,petit_tab);
           };break;
           case '2':
           {
              ManByList1(liste);
           };break;
           case '3':
           {
              ManByList2(liste_double);
           };break;
           case '4':
           {
              Apropos();
           };break;
           case '5':{};break;
       }
}

void deroulement()
{
    char touche;
    //constante pour la manipulation par tableau
    int const kandorette = 4;
    //tableau d'étudiant
    Tetudiant tab[kandorette];
    //tableau index de poids
    Tindex petit_tab[kandorette];
    //liste simplement chaînée
    Tls_Etudiant *liste_simple=NULL;//initialiser à NULL à la création
    Tld_Etudiant *liste_double=NULL;//initialiser à NULL à la création

    init_array(tab);
    do
    {
       menuprincipal();
       do
       {
         touche=toupper(getch());
       }
       while((touche!='1') && (touche!='2') && (touche!='3') && (touche!='4') && (touche!='5'));
       corps(touche,tab,petit_tab,kandorette,&liste_simple,&liste_double);
    }
    while(touche!='5');
}

void gestionpartab(int i)
{
  system("cls");cout<<"\n\n\n\n\a"<<endl;
  cout<<"                   GESTION PAR TABLEAU ###"<<i<<endl;
  cout<<"                   ========================"<<endl;
  cout<<""<<endl;
  cout<<"                   1-Affichage des etudiants"<<endl;
  cout<<"                   2-Affichage des etudiants par index(poids)"<<endl;
  cout<<"                   3-saisie des etudiants"<<endl;
  cout<<"                   4-tri des etudiants par ordre Alphabetique"<<endl;
  cout<<"                   5-tri des etudiants par age"<<endl;
  cout<<"                   6-tri des etudiants par index(poids)"<<endl;
  cout<<"                   7-sauvegarder le tableau d'etudiants"<<endl;
  cout<<"                   8-Restaurer un tableau d'etudiants"<<endl;
  cout<<"                   9-Retour au menu principal\n"<<endl;
  cout<<"                   VOTRE CHOIX : ";
}

void gestionpartls(string a)
{
  system("cls");cout<<"\n\n\n\n\a"<<endl;
  cout<<"                   GESTION PAR "<<a<<endl;
  cout<<"                   ========================\n"<<endl;
  cout<<"                   1-Afficher la liste des etudiants"<<endl;
  cout<<"                   2-Ajout d'un etudiant"<<endl;
  cout<<"                   3-supprimer un etudiant" <<endl;
  cout<<"                   4-tri des etudiants par ordre alphabetique"<<endl;
  cout<<"                   5-tri des etudiants par age"<<endl;
  cout<<"                   6-sauvegarder la liste des etudiants"<<endl;
  cout<<"                   7-Restaurer une liste d'etudiants"<<endl;
  cout<<"                   8-Retour au menu principal\n"<<endl;
  cout<<"                   VOTRE CHOIX : ";
}

void Apropos()

{
    system("cls");cout<<"\n\n\n\n\a"<<endl;
  cout<<"                 ANNEE SCOLAIRE 2012/2013- TP POO"<<endl;
  cout<<"               Diriger par : Mr OMGBA Clestin Alexis"<<endl;
  cout<<"               =====================================\n"<<endl;
  cout<<"               Realise par"<<endl;
  cout<<"               1 - KIBONGUE STEPHANE IVALAIN (responsable)"<<endl;
  cout<<"               2 - TUENE BEBE BELL"<<endl;
  cout<<"               3 - MVOGO DJUISSI ANNABELLE"<<endl;
  cout<<"               4 - MBANGA EBISSENDE SYLVIE"<<endl;
  cout<<"               5 - NKOULOU ALBERT STEPHANE (presentateur)\n"<<endl;
  cout<<"               Appuyer sur une touche : ";getch();
}
void not_save(string a)
{
                 system("cls");
                 cout<<"\n\n";
                 cout<<"          ===   Sauvegarde du tableau d'etudiants   ==="<<endl;
                 cout<<"                <------------------------------->\n"<<endl;
                 cout<<"                Impossible de sauvegarder,"<<a<<" est vide ..."<<endl;
                 cout<<"\n\n"<<endl;
                 cout<<"              Appuyez sur une touche pour continuer --->";
                 getch();
}


string save_default_array(Tetudiant tab[],int a,string nom)
{
 ofstream fichier(nom.c_str(),ios::binary|ios::out);
 if(fichier)
  {
   for(int i=0;i<a;i++)
   {
    fichier.write(reinterpret_cast<char *> (&tab[i]),sizeof(Tetudiant));
   }
   fichier.close();
   return ("             Sauvegarde realisee avec succes,\n             Le fichier porte le nom de : " + nom +" ");
  }
  else
   return ("             Erreur lors de la creation du fichier, veuillez reessayer ...");
}

void perso_saving_array(Tetudiant tab[],int i)
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

         cout<<"                 Entrer le nom du fichier : ";
         getline(cin,name);
         if((name.find('.'))<0 ||(name.find('.'))>name.length())
            name.append(".tet");
         if((name.find('.'))== name.length()-1)
            name.append("tet");
         cout<<"\n";
         cout<<"                 Sauvegarde en cours ";
         for(int k=0;k<5;k++)
         {
           cout<<". \a";
           delay(1);
         }
         cout<<"\n";
         cout<<save_default_array(tab,i,name);
         getch();
     }break;

     case '2':{}break;
   }
 }
 while(touche!='2');
 cout<<"              Appuyer sur une touche ---> ";
 getch();
}

void transfert(Tetudiant tab[],int i,Tindex petit_tab[])
{
  for(int k=0;k<i;k++)
  {
      petit_tab[k].poids=tab[k].poids;
      petit_tab[k].pos=k;
  }
}

void tri_age(Tetudiant tab[],int i)
{
                     tri_jour(tab,i);
                     tri_mois(tab,i);
                     tri_annee(tab,i);
}

void gestion_tri_age(Tetudiant tab[],int i,Tindex petit_tab[])
{
                if(!ArrayEmpty(tab))
                {
                     system("cls");
                     cout<<"\n\n";
                     tri_age(tab,i);
                     transfert(tab,i,petit_tab);
                     cout<<"                     Tri par age en cours ";
                     for(int k=0;k<5;k++)
                     {
                       cout<<"* \a";
                       delay(1);
                     }
                     cout<<">";
                     cout<<"\n                     Tri realise avec succes.";
                     cout<<"\n                     Appuyez sur une touche pour revenir --->";
                     getch();

                }
                else
                {
                     system("cls");
                     cout<<"\n\n";
                     cout<<"          ===   tri du tableau d'etudiants par age   ==="<<endl;
                     cout<<"                <-------------------------------->\n"<<endl;
                     cout<<"                Impossible de trier, le tableau est vide ..."<<endl;
                     cout<<"\n\n"<<endl;
                     cout<<"              Appuyez sur une touche pour continuer --->";
                     getch();
                }
}

void gestion_index(Tetudiant tab[],int i,Tindex petit_tab[])
{
                if(!ArrayEmpty(tab))
                {
                     system("cls");
                     cout<<"\n\n";
                     tri_insert_sequen(petit_tab,i);
                     cout<<"                     Tri par index de poids en cours ";
                     for(int k=0;k<5;k++)
                     {
                       cout<<"* \a";
                       delay(1);
                     }
                     cout<<">";
                     cout<<"\n                     Tri realise avec succes.";
                     cout<<"\n                     Appuyez sur une touche pour revenir --->";
                     getch();

                }
                else
                {
                     system("cls");
                     cout<<"\n\n";
                     cout<<"          ===   tri du tableau d'etudiants par index de poids   ==="<<endl;
                     cout<<"                <------------------------------------------->\n"<<endl;
                     cout<<"                Impossible de trier, le tableau est vide ..."<<endl;
                     cout<<"\n\n"<<endl;
                     cout<<"              Appuyez sur une touche pour continuer --->";
                     getch();
                }
}

void ManByArray0152(Tetudiant tab[],int i,Tindex petit_tab[])
{
    char touche;
    do
    {
       gestionpartab(i);
       do
       {
         touche=toupper(getch());
       }
       while((touche!='1') && (touche!='2') && (touche!='3') && (touche!='4') && (touche!='5')&& (touche!= '6') && (touche!='7') && (touche!='8') && (touche!='9'));
       switch(touche)
       {
           case '1':{
               show_student_array(tab,i);
           };break;
           case '2':{
             index_poids(tab,i,petit_tab);
           };break;
           case '3':{
             saisie_etudiant_tableau(tab,i,petit_tab);
           };break;
           case '4':{
              gestion_tri_alpha(tab,i,petit_tab);
           };break;
           case '5':{
            gestion_tri_age(tab,i,petit_tab);
           };break;
           case'6': {
                gestion_index(tab,i,petit_tab);
            };break;
           case'7':{
                sauvegarde_tableau(tab,i);
            };break;
            case'8':{
                restor_data(tab,i,petit_tab);
            };break;
            case'9':break;
       }
    }
    while(touche!='9');
}

void sauvegarde_tableau(Tetudiant tab[],int i)
{
               if(!ArrayEmpty(tab))
               {
                 switch(save_mode())
                 {
                   case '1':
                   {
                     system("cls");
                     cout<<"\n\n";
                     cout<<"                     Sauvegarde en cours ";
                     for(int k=0;k<5;k++)
                     {
                       cout<<". \a";
                       delay(1);
                     }
                     cout<<"\n";
                     cout<<save_default_array(tab,i,"default_student.tet");
                     getch();
                   }break;
                   case '2':
                   {
                       perso_saving_array(tab,i);

                   }break;
                   case '3':
                   {}break;
                 }
               }
               else
                 not_save(" Le tableau ");
}

void ManByList1(Tls_Etudiant **liste)
{
  char touche;
    do
    {
       gestionpartls("Liste SIMPLE");
       do
       {
         touche=toupper(getch());
       }
       while((touche!='1') && (touche!='2') && (touche!='3') && (touche!='4') && (touche!='5')&& (touche!= '6') && (touche!='7') && (touche!='8') && (touche!='9'));
       switch(touche)
       {
           case '1':
           {
              show_student_file(liste);
           };break;
           case '2':
           {
              GetStudent_liste_simple(liste);
           };break;
           case '3':
           {
               char touche;
               do
               {
                     system("cls");
                     cout<<"\n\n";
                     cout<<"        Voulez-vous vraiment supprimer le premier etudiant de la liste ? \n";
                     cout<<"                     ====================== \n\n";
                     cout<<"                       1 - Confirmez.\n";
                     cout<<"                       2 - Annulez...\n\n";
                     cout<<"                           Votre choix : ";
                     touche = toupper(getch());
               }
               while(touche!='1' && touche!='2');
               switch(touche)
               {
                   case '1':
                   {
                       if(*liste!=NULL)
                       {
                         cout<<"\n\n";
                         defilage(liste);
                         cout<<"                       suppression en cours ";
                         for(int k=0;k<3;k++)
                         {
                           cout<<"* \a";
                           delay(1);
                         }
                         cout<<">";
                         cout<<"\n                       suppression realise avec succes.";
                         cout<<"\n                       Appuyez sur une touche pour revenir --->";
                         getch();
                       }
                       else
                       {
                             system("cls");
                             cout<<"\n\n";
                             cout<<"          ===   Suppression d'un etudiant de la liste   ==="<<endl;
                             cout<<"                <----------------------------------->\n"<<endl;
                             cout<<"                Impossible de supprimer, la liste est vide ..."<<endl;
                             cout<<"\n\n"<<endl;
                             cout<<"                Appuyez sur une touche pour continuer --->";
                             getch();
                       }
                   }break;
                   case '2':break;
               }
               getch();
           };break;
           case '4':
           {
                if(*liste != NULL)
                {
                     system("cls");
                     cout<<"\n\n";
                     liste_simple_tri(liste,1);
                     cout<<"                       Tri par ordre alphabetique en cours ";
                     for(int k=0;k<5;k++)
                     {
                       cout<<"* \a";
                       delay(1);
                     }
                     cout<<">";
                     cout<<"\n                       Tri realise avec succes.";
                     cout<<"\n                       Appuyez sur une touche pour revenir --->";
                     getch();

                }
                else
                {
                     system("cls");
                     cout<<"\n\n";
                     cout<<"          ===   tri de la liste d'etudiants par ordre alphabetique   ==="<<endl;
                     cout<<"                <------------------------------------------------>\n"<<endl;
                     cout<<"                Impossible de trier, la liste est vide ..."<<endl;
                     cout<<"\n\n"<<endl;
                     cout<<"                Appuyez sur une touche pour continuer --->";
                     getch();
                }

           };break;
           case '5':
           {
                if(*liste != NULL)
                {
                     system("cls");
                     cout<<"\n\n";
                     liste_simple_tri(liste,0);
                     cout<<"                       Tri par Age en cours ";
                     for(int k=0;k<5;k++)
                     {
                       cout<<"* \a";
                       delay(1);
                     }
                     cout<<">";
                     cout<<"\n                       Tri realise avec succes.";
                     cout<<"\n                       Appuyez sur une touche pour revenir --->";
                     getch();

                }
                else
                {
                     system("cls");
                     cout<<"\n\n";
                     cout<<"          ===   tri de la liste d'etudiants par age   ==="<<endl;
                     cout<<"                <--------------------------------->\n"<<endl;
                     cout<<"                Impossible de trier, la liste est vide ..."<<endl;
                     cout<<"\n\n"<<endl;
                     cout<<"                Appuyez sur une touche pour continuer --->";
                     getch();
                }

           };break;
           case'6':
            {
               if(!(*liste==NULL))
               {
                 switch(save_mode())
                 {
                   case '1':
                   {
                     system("cls");
                     cout<<"\n\n";
                     cout<<"             Sauvegarde en cours ";
                     for(int k=0;k<5;k++)
                     {
                       cout<<". \a";
                       delay(1);
                     }
                     cout<<"\n";
                     cout<<save_default_liste(liste,"default_student.tls");
                     getch();
                   }break;
                   case '2':
                   {
                     perso_saving_liste(liste);
                   }break;
                   case '3':
                   {}break;
                 }
               }
               else
                 not_save("La liste");
            };break;
           case'7':
            {
                restor_data(liste);
            };break;
            case'8':
            {
            };break;



       }
    }
    while(touche!='8');
}

char GetSex()
{
    char touche;

    do
    {
       touche=toupper(getch());
    }
    while(touche!='M' && touche!='F');
    cout<<touche<<endl;
    return touche;
}


void init_array(Tetudiant tab[])
{
    tab[0].an_naiss=10008952;
}

bool ArrayEmpty(Tetudiant tab[])
{
    return (tab[0].an_naiss == 10008952 ? true:false);
}

Tetudiant GetStudent(int i,int taille)
{
   Tetudiant etud;
   system("cls");
   cout<<"\n\n";
   cout<<"              ===   Saisie des informations de "<<taille<<" etudiants   ==="<<endl;
   cout<<"                    <------------------------------------>\n"<<endl;
   cout<<"              Recuperation des informations de l'etudiant N : "<<i+1<<endl;
   cout<<"              ==================================================\n\n";
   cout<<"           Matricule : ";GetInput(etud.matricule,24);
   cout<<"                 Nom : ";GetInput(etud.nom,35);
   cout<<"              Prenom : ";GetInput(etud.prenom,55);
   cout<<"                        Date de naissance de l'etudiant"<<endl;
   GetInteger("Jour",&etud.jour_naiss);
   GetInteger("Mois",&etud.mois_naiss);
   GetInteger("Annee",&etud.an_naiss);
   cout<<"                        Date de naissaince recuperee"<<endl;
   cout<<"                Sexe : ";etud.sexe=GetSex();
   GetInteger("Poids",&etud.poids);
   return etud;
}

void saisie_etudiant_tableau(Tetudiant tab[],int i,Tindex petit_tab[])
{
    for(int ii=0;ii<i;ii++)
    {
      tab[ii]=GetStudent(ii,i);
      petit_tab[ii].poids=tab[ii].poids;
      petit_tab[ii].pos=ii;
      cout<<""<<endl;
    }
    cout<<""<<endl;
    majiscule(tab,i);
    cout<<"              Saisie des "<<i<<" etudiant(s) realisee avec succes..."<<endl;
    cout<<"              Appuyez sur une touche pour continuer --->";
    getch();
}

void show_student_array(Tetudiant tab[],int i)
{
   system("cls");
   cout<<"\n\n";
   cout<<"          ===   Affichage des informations de(s) "<<i<<" etudiants   ==="<<endl;
   cout<<"                <------------------------------------------>\n"<<endl;
   if(!ArrayEmpty(tab))
   {
     for(int it=0;it<i;it++)
     {
       cout<<"    "<<it+1<<"- "<<tab[it].nom<<" "<<tab[it].prenom<<" -- "<<tab[it].jour_naiss<<"/"<<tab[it].mois_naiss<<"/"<<tab[it].an_naiss<<" -- "<<tab[it].poids<<"(Kg)  --   "<<tab[it].sexe<<"  --  "<<tab[it].matricule<<endl;
     }
   }
   else
   {
     cout<<"                Impossible d'afficher, le tableau est vide ..."<<endl;
   }
   cout<<"\n\n"<<endl;
   cout<<"              Affichage des "<<i<<" etudiant(s) realisee avec succes..."<<endl;
   cout<<"              Appuyez sur une touche pour continuer --->";
   getch();
}

char save_mode()
{
  char touche;
  do
  {
    system("cls");
    cout<<"\n\n";
    cout<<"              <--- Veuillez selectionner le mode de sauvegarde --->\n"<<endl;
    cout<<"              1 - Sauvegarge par defaut."<<endl;
    cout<<"              2 - Sauvegarde personnalisee."<<endl;
    cout<<"              3 - Annuler."<<endl;
    cout<<"                             Votre choix : ";
    touche = toupper(getch());
  }
  while((touche!='1') && (touche!='2') && (touche!='3'));
  return touche;
}

void restor_data(Tetudiant tab[],int i,Tindex petit_tab[])
{
   system("cls");
   string name;
   ifstream fichier;
   int k(0);
   Tetudiant po;

   cout<<"\n\n";
   cout<<"              ===   Restauration d'un fichier d'etudiants  ==="<<endl;
   cout<<"                    <----------------------------------->\n"<<endl;
   cout<<"                       Recuperation du nom de fichier"<<endl;
   cout<<"                       ==============================\n\n";
   cout<<"              Entrez le nom du fichier a restaurer : ";
   getline(cin,name);
   if((name.find('.'))<0 ||(name.find('.'))>name.length())
        name.append(".tet");
   if((name.find('.'))== name.length()-1)
        name.append("tet");
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
         if(fichier.tellg()/sizeof(Tetudiant) >= i)
         {
           fichier.seekg(0,ios::beg);//on se repositionne au début
           while((k<i) && (!fichier.eof()))
           {
                fichier.read(reinterpret_cast<char *> (&po), sizeof(Tetudiant));
                if(fichier.gcount()== sizeof(Tetudiant))
                {
                  tab[k]=po;
                  petit_tab[k].poids = tab[k].poids;
                  petit_tab[k].pos = k;
                }
                k++;
           }
           majiscule(tab,i);
           fichier.close();
           cout<<"              Restauration realisee avec succes...\n";
         }
         else
         {
            cout<<"              Restauration Avortee...\n";
            cout<<"              Le nombre d'enregistrements presents\n";
            cout<<"              dans le fichier est inferieur a la taille du tableau...\n";
         }
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

void tri_insert_sequen(Tindex tab[],int n)
{
    Tindex temp;
    int k;

    for(int i=1;i<n;i++)
    {
        temp = tab[i];
        k = i-1;
        while((k>=0) && (tab[k].poids > temp.poids))
        {
            tab[k+1] = tab[k];
            k--;
        }
        tab[k+1] = temp;
    }
}

void index_poids(Tetudiant tab[],int tail,Tindex t[])
{
    if(!ArrayEmpty(tab))
    {
          tri_insert_sequen(t,tail);
          system("cls");
          cout<<"\n\n";
          cout<<"          ===   Affichage des informations par index de poids  ==="<<endl;
          cout<<"                <------------------------------------------->\n"<<endl;
          for(int it=0;it<tail;it++)
          {
           cout<<"    "<<it+1<<"- "<<tab[t[it].pos].nom<<" "<<tab[t[it].pos].prenom<<" -- "<<tab[t[it].pos].jour_naiss<<"/"<<tab[t[it].pos].mois_naiss<<"/"<<tab[t[it].pos].an_naiss<<" -- "<<tab[t[it].pos].poids<<"(Kg)  --   "<<tab[t[it].pos].sexe<<endl;
          }
          cout<<"\n\n"<<endl;
          cout<<"              Affichage des "<<tail<<" etudiant(s) realisee avec succes..."<<endl;
          cout<<"              Appuyez sur une touche pour continuer --->";
          getch();
    }
    else
    {
         system("cls");
         cout<<"\n\n";
         cout<<"          ===   Affichage du tableau d'etudiants par index de poids   ==="<<endl;
         cout<<"                <------------------------------------------------->\n"<<endl;
         cout<<"                Impossible d'afficher, le tableau est vide ..."<<endl;
         cout<<"\n\n"<<endl;
         cout<<"                Appuyez sur une touche pour continuer --->";
         getch();
    }
}

//fonctions de tri
int Alea_Bornes(int a, int b)
{
   srand(time(NULL));
   return (a+rand()%(b-a+1));
}

int Divise_Tableau(Tetudiant Tab[], int d, int f, int ind_piv)
{
   int i,k;
   Tetudiant pivot,temp;

   pivot=Tab[ind_piv];
   Tab[ind_piv]=Tab[f];
   Tab[f]=pivot;
   k=d;
   for(i=d;i<=f;i++)
   {
       if(Tab[i].jour_naiss>pivot.jour_naiss)//venez modifiez ici, si le prof demande de changer l'ordre tri (le ">" devient "<"
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

void TRI_RAPIDE(Tetudiant T[], int deb, int fin)
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

void tri_jour(Tetudiant tab[],int i)
{
  TRI_RAPIDE(tab,0,i-1);
}

void tri_dicho(Tetudiant tab[],int tail)
{
    int pos,k,borne_sup,borne_inf,milieu;
    Tetudiant x;

    for(pos=1;pos<tail;pos++)
    {
        if(tab[pos].mois_naiss>tab[pos-1].mois_naiss)
        {
            borne_inf=0;
            borne_sup=pos-1;
            while(borne_inf!=borne_sup)
            {
                milieu=(borne_inf+borne_sup)/2;
                if(tab[pos].mois_naiss>=tab[milieu].mois_naiss)//venez modifiez ici, si le prof demande de chaner l'ordre tri (le ">=" devient "<="
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

void tri_mois(Tetudiant tab[],int i)
{
    tri_dicho(tab,i);
}

void tri_selor(Tetudiant tab[],int tail)
{
    int i,j;
    Tetudiant tempo;

    for(i=0;i<tail-1;i++)
    {
        j=i;
        for(int k=i+1;k<tail;k++)
        {
            if(tab[k].an_naiss>tab[j].an_naiss)//venez modifiez ici, si le prof demande de chaner l'ordre tri (le ">" devient "<")
              j=k;
        }
        tempo=tab[i];
        tab[i]=tab[j];
        tab[j]=tempo;
    }
}


void tri_prenom(Tetudiant tab[],int tail,int pos)
{
    Tetudiant x;

    if(pos<tail-1)
    {
        for(int a=tail-1;a>pos;a--)
        {
            if(strcmp(tab[a].prenom,tab[a-1].prenom)<0)//venez modifiez ici, si le prof demande de chaner l'ordre tri (le "<" devient ">"
            {
                x=tab[a];
                tab[a]=tab[a-1];
                tab[a-1]=x;
            }
        }
        tri_prenom(tab,tail,pos+1);
    }
}

void tri_alpha(Tetudiant tab[],int i)
{
      tri_prenom(tab,i,0);
      tri_nom(tab,i);
}

void tri_nom(Tetudiant tab[],int tail)
{
    int i,j;
    Tetudiant tempo;
    for(i=0;i<tail-1;i++)
    {
        j=i;
        for(int k=i+1;k<tail;k++)
        {
            if(strcmp(tab[k].nom,tab[j].nom)<0)//venez modifiez ici, si le prof demande de chaner l'ordre tri (le "<" devient ">"
              j=k;
        }
        tempo=tab[i];
        tab[i]=tab[j];
        tab[j]=tempo;
    }
}

void tri_annee(Tetudiant tab[],int i)
{
    tri_selor(tab,i);
}
//fin de l'implémentation des fonctions de tri...

void gestion_tri_alpha(Tetudiant tab[],int i,Tindex petit_tab[])
{
                if(!ArrayEmpty(tab))
                {
                     system("cls");
                     cout<<"\n\n";
                     tri_alpha(tab,i);
                     transfert(tab,i,petit_tab);
                     cout<<"                     Tri par ordre alphabetique en cours ";
                     for(int k=0;k<5;k++)
                     {
                       cout<<"* \a";
                       delay(1);
                     }
                     cout<<">";
                     cout<<"\n                     Tri realise avec succes.";
                     cout<<"\n                     Appuyez sur une touche pour revenir --->";
                     getch();

                }
                else
                {
                     system("cls");
                     cout<<"\n\n";
                     cout<<"          ===   tri du tableau d'etudiants par order alphabetique   ==="<<endl;
                     cout<<"                <----------------------------------------------->\n"<<endl;
                     cout<<"                Impossible de trier, le tableau est vide ..."<<endl;
                     cout<<"\n\n"<<endl;
                     cout<<"                Appuyez sur une touche pour continuer --->";
                     getch();
                }
}

bool compare_array(const char t1[],const char t2[])
{
  int taille=(strlen(t1)<=strlen(t2)?strlen(t1):strlen(t2)),i=0;
  bool trouve(true);

  while((i<taille) && (trouve))
  {
     if(t1[i]>t2[i])
       trouve=false;

     i++;
  }
  return trouve;
}

void majiscule(Tetudiant tab[],int i)
{
 for(int k=0;k<i;k++)
 {
     strcpy(tab[k].nom,strupr(tab[k].nom));
     strcpy(tab[k].prenom,strupr(tab[k].prenom));
 }
}
