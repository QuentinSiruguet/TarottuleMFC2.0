#include "Joueur.h"

//#define test_lireNom
//#define test_lireScore
//#define test_lireScore_donne
//#define test_majScore
//#define test_ajout_nom
//#define test_sauvegarde_score_donne

CJoueur::CJoueur()
{
	score = 0;
	score_donne = 0;
}

CJoueur::~CJoueur()
{
}

string CJoueur::lireNom()
{
	return nom;
}

#ifdef test_lireNom
void main()
{
	CJoueur emilio;
	emilio.ajout_nom("emilio");
	cout << emilio.lireNom();
}
#endif

int CJoueur::lireScore()
{
	return score;
}

#ifdef test_lireScore
void main()
{
	CJoueur joueur1;
	joueur1.majScore(23);
	cout << joueur1.lireScore();
}
#endif

int CJoueur::lireScore_donne()
{
	return score_donne;
}

#ifdef test_lireScore_donne
void main()
{
	CJoueur joueur;
	joueur.sauvegarde_score_donne(23);
	cout << joueur.lireScore_donne();
}
#endif

void CJoueur::majScore(int new_score)
{
	score += new_score;
}

#ifdef test_majScore
void main()
{
	CJoueur joueur;
	joueur.majScore(12);
}
#endif

void CJoueur::ajout_nom(string nom_joueur)
{
	nom = nom_joueur;
}

#ifdef test_ajout_nom
void main()
{
	CJoueur jesse;
	jesse.ajout_nom("Jesse");
	cout << jesse.lireNom();
}
#endif

void CJoueur::sauvegarde_score_donne(int score_recu)
{
	if (score_recu != 0)
		score_donne += score_recu;
	else
		score_donne = score_recu;
}

#ifdef test_sauvegarde_score_donne
void main()
{
	CJoueur joueur;
	joueur.sauvegarde_score_donne(23);
}
#endif