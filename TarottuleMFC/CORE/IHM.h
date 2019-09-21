#pragma once
#include "Donne.h"
#include "Joueur.h"
#include "Partie.h"

#include <iostream>
#include <fstream>

using namespace std;

class IHM
{
private:
	CJoueur *lesJoueurs[4];
	CPartie *laPartie;
	string nom_fichier;
public:
	IHM();
	~IHM();

	void nouvelle_partie();
	void choix_nom_joueur();
	void sauvegarde_avant_donne();
	void Typecontrat();
	void Choix_Poignee();

	void lire();
	void Saisie_petit_au_bout();

	void Fin_donne();
	void Nouvelle_donne(int);
	bool Fin_partie();
	void Point_Preneur();
	void Opoigner();
	string Get_Donneur(int);
	void Afficher_joueur();
	void Afficher_score();
};

