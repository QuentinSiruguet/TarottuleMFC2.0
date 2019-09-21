#pragma once
enum Poignee{Sans, Simple, Double, Triple};
enum Camp{Preneur, Personne, Defenseur};
enum Contrat{Passe, Prise, Garde, GardeSans, GardeContre};
enum Chelem{SansChelem, Reussi, Perdu, SansAnnonce};

#include "Joueur.h"
#include <fstream>
#include <iostream>
using namespace std;
class CDonne
{
private:
	int nbPoints;
	int Bouts;

	Contrat typeContrat;
	Camp campPoignee;
	Poignee typePoignee;
	Camp campPetitAuBout;
	Chelem typeCelem;

	CJoueur *leDonneur;
	CJoueur *lePreneur;
	CJoueur *lesDefenseurs[3];



public:
	CDonne(CJoueur *);
	~CDonne();
	void SetPreneur(CJoueur *);
	void SetDefenseur(CJoueur *defenseur[3]);
	void SetnbPoints(int);
	void SetBouts(int);
	void SetTypeContrat(Contrat);
	void SetTypePoignee(Poignee);
	void SetPetitAuBouts(bool);

	void calcul_score();
	void save_fin_donne(CJoueur *lesJoueurs[4], string);

};

