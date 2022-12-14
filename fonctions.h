#include <iostream>
#include <string>
#include <fstream>

using namespace std;


// fonction qui recupère une date valide 
void getDate(int &jour, int &mois, int &annee)
{
    cout << "Entrez une date valide (jj/mm/aaaa) supérieur ou égale au 20 décembre 1582 : \n";
    cin >> jour;
    cin.ignore();
    cin >> mois;
    cin.ignore();
    cin >> annee;
    

    // année bissextile
    if (annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0)
    {
        if (mois == 2 && jour > 29)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
    }
    else
    {
        if (mois == 2 && jour > 28)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
    }

    // mois de 30 jours
    if (mois == 4 || mois == 6 || mois == 9 || mois == 11)
    {
        if (jour > 30)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
    }

    // mois de 31 jours
    if (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12)
    {
        if (jour > 31)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
    }

    // mois invalide
    if (mois > 12 || mois < 1)
    {
        cout << "Date invalide" << endl;
        getDate(jour, mois, annee);
    }

    // date inférieure au 20 décembre 1582
    if (annee < 1582)
    {
        cout << "Date invalide" << endl;
        getDate(jour, mois, annee);
    }
    else if (annee == 1582)
    {
        if (mois < 12)
        {
            cout << "Date invalide" << endl;
            getDate(jour, mois, annee);
        }
        else if (mois == 12)
        {
            if (jour < 20)
            {
                cout << "Date invalide" << endl;
                getDate(jour, mois, annee);
            }
        }
    }

}


// fonction qui calcule le nombre seculaire
void nbre_seculaire(int &jour, int &mois, int &annee, int &nbre_secu){
    int siecle_ref = 15;
    int nb_sec_ref = 1;
    nbre_secu = nb_sec_ref;
    int s = annee/100;
    while (siecle_ref != s)
    {
        if (nbre_secu == 1)
            nbre_secu = 0;
        else if (nbre_secu == 0)
            nbre_secu = 5;
        else if (nbre_secu == 5)
            nbre_secu = 3;
        else if (nbre_secu == 3)
            nbre_secu = 1;
        siecle_ref++;
    }

}


// nombre annuel 
void nbre_annuel(int &jour, int &mois, int &annee, int &annuel){
     annuel = (annee%100) + (annee%100)/4 - 5;
    
}


// fontion qui calcule le nombre mensuel
void nbre_mensuel(int &mois, int &annee,int &mensuel){
    // si l'année est bisextile
    if(annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0){
        if(mois == 1){
            mensuel = 3;
        }
        if(mois == 2){
            mensuel = 6;
        }
    }
    else{
        if(mois == 1){
            mensuel = 4;
        }
        if(mois == 2){
            mensuel = 0;
        }
    }


    // pour les autres mois quelque soit le type de l'année
    if (mois == 3 || mois == 11){
        mensuel = 0;
    }
    if (mois == 6){
        mensuel = 1;
    }
    if (mois == 9 || mois == 12){
        mensuel = 2;
    }
    if (mois == 4 || mois == 7){
        mensuel = 3;
    }
    if (mois == 10){
        mensuel = 4;
    }
    if (mois == 5){
        mensuel = 5;
    }
    if (mois == 8){
        mensuel = 6;
    }
}


// fonction qui calcule le quantième 
void nbre_quantieme(int &jour, int &quantieme){
    quantieme = jour;
}



// fonction qui calcule le jour de la semaine
void jour_semaine(int &nbre_secu, int &annuel, int &mensuel, int &quantieme, int &res){
    res = (nbre_secu + annuel + mensuel + quantieme) % 7;
}


// fonction qui affiche le jour de la semaine
void affiche_jour_semaine(int &res){
    if(res == 0){
        cout << "Dimanche" << endl;
    }
    if(res == 1){
        cout << "Lundi" << endl;
    }
    if(res == 2){
        cout << "Mardi" << endl;
    }
    if(res == 3){
        cout << "Mercredi" << endl;
    }
    if(res == 4){
        cout << "Jeudi" << endl;
    }
    if(res == 5){
        cout << "Vendredi" << endl;
    }
    if(res == 6){
        cout << "Samedi" << endl;
    }
}



//fonction 1 : jour semaine
void option1(int &jour, int &mois, int &annee, int &nbre_secu, int &annuel, int &mensuel, int &quantieme, int &res){
    getDate(jour, mois, annee);
    nbre_seculaire(jour, mois, annee, nbre_secu);
    nbre_annuel(jour, mois, annee, annuel);
    nbre_mensuel(mois, annee, mensuel);
    nbre_quantieme(jour, quantieme);
    jour_semaine(nbre_secu, annuel, mensuel, quantieme, res);
    affiche_jour_semaine(res);
}


// fonction 2 : vendredi 13
void option2(int &jour, int &mois, int &annee, int &nbre_secu, int &annuel, int &mensuel, int &quantieme, int &res){
    // saisir une année
    cout << "Saisir une année supérieure à 1582 : ";
    cin >> annee;

    // verifier si l'annee est supérieure à 1582
    while(annee < 1582)
    {
        cout << "Date invalide" << endl;
        cout << "Saisir une année supérieure à 1582 : ";
        cin >> annee;
    }

    // calculer le jour de la semaine pour tous les 13 du mois
    for (int i = 1; i <= 12; i++)
    {
        mois = i;
        jour = 13;
        nbre_seculaire(jour, mois, annee, nbre_secu);
        nbre_annuel(jour, mois, annee, annuel);
        nbre_mensuel(mois, annee, mensuel);
        nbre_quantieme(jour, quantieme);
        jour_semaine(nbre_secu, annuel, mensuel, quantieme, res);

        if (res == 5)
        {
            cout << "Le 13 " << mois << " " << annee << " est un vendredi" << endl;
        }
    }
}


// fonction 3 : edition de calendrier 
void option3(int &jour, int &mois, int &annee, int &nbre_secu, int &annuel, int &mensuel, int &quantieme, int &res){
    // saisir une année
    cout << "Saisir une année : ";
    cin >> annee;

    while(annee < 1582)
    {
        cout << "Date invalide" << endl;
        cout << "Saisir une année supérieure à 1582 : ";
        cin >> annee;
    }

    //convertir le res en jour de la semaine stocker dans un tableau
    string jours[7] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};

    //ecriture dans un fichier
    ofstream fichier("calendrier.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

    // si l'ouverture a réussi
    if(fichier)
    {
        // gerer les mois qui ont 31 jours, 30 jours, 28 ou 29 jours pour fevrier
        for (int i = 1; i <= 12; i++)
        {
            mois = i;
            if (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12)
            {
                for (int j = 1; j <= 31; j++)
                {
                    jour = j;
                    nbre_seculaire(jour, mois, annee, nbre_secu);
                    nbre_annuel(jour, mois, annee, annuel);
                    nbre_mensuel(mois, annee, mensuel);
                    nbre_quantieme(jour, quantieme);
                    jour_semaine(nbre_secu, annuel, mensuel, quantieme, res);
                    fichier << jour << "-" << mois << "-" << annee << " " << jours[res] << endl;
                }
            }
            if (mois == 4 || mois == 6 || mois == 9 || mois == 11)
            {
                for (int j = 1; j <= 30; j++)
                {
                    jour = j;
                    nbre_seculaire(jour, mois, annee, nbre_secu);
                    nbre_annuel(jour, mois, annee, annuel);
                    nbre_mensuel(mois, annee, mensuel);
                    nbre_quantieme(jour, quantieme);
                    jour_semaine(nbre_secu, annuel, mensuel, quantieme, res);
                    fichier << jour << "-" << mois << "-" << annee << " " << jours[res] << endl;
                }
            }
            if (mois == 2)
            {
                if(annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0){
                    for (int j = 1; j <= 29; j++)
                    {
                        jour = j;
                        nbre_seculaire(jour, mois, annee, nbre_secu);
                        nbre_annuel(jour, mois, annee, annuel);
                        nbre_mensuel(mois, annee, mensuel);
                        nbre_quantieme(jour, quantieme);
                        jour_semaine(nbre_secu, annuel, mensuel, quantieme, res);
                        fichier << jour << "-" << mois << "-" << annee << " " << jours[res] << endl;
                    }
                }
                else{
                    for (int j = 1; j <= 28; j++)
                    {
                        jour = j;
                        nbre_seculaire(jour, mois, annee, nbre_secu);
                        nbre_annuel(jour, mois, annee, annuel);
                        nbre_mensuel(mois, annee, mensuel);
                        nbre_quantieme(jour, quantieme);
                        jour_semaine(nbre_secu, annuel, mensuel, quantieme, res);
                        fichier << jour << "-" << mois << "-" << annee << " " << jours[res] << endl;
                    }
                }
            }
        }
    
        // on ferme le fichier
        fichier.close();
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
    cout << "Calendrier généré avec succès" << endl;
}







