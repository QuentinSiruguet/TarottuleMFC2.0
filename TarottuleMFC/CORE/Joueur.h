#pragma once
#include <iostream>
#include <string>
using namespace std;

class CJoueur
{
private:
	string nom;
	int score;
	int score_donne;
public:
	CJoueur();
	~CJoueur();
	string lireNom();
	int lireScore();
	int lireScore_donne();
	void majScore(int);
	void ajout_nom(string);
	void sauvegarde_score_donne(int);
};

