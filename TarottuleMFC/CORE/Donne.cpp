#include "Donne.h"

//#define test_SetPreneur
//#define test_SetDefenseur
//#define test_SetnbPoints
//#define test_SetBouts
//#define test_SetTypeContrat
//#define test_SetTypePoignee
//#define test_SetPetitAuBouts
//#define test_calcul_score
//#define test_save_fin_donne


CDonne::CDonne(CJoueur *donneur)
{
	leDonneur = donneur;
	typeContrat = Prise;
	campPetitAuBout = Personne;
}

CDonne::~CDonne()
{

}

void CDonne::SetPreneur(CJoueur *preneur)
{
	lePreneur = preneur;
}

#ifdef test_SetPreneur

void main()
{
	CJoueur* lesJoueurs[4];
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur; //On crée des nouveaux joueurs
	CDonne Donne(lesJoueurs[0]); //On crée une nouvelle donne avec le Donneur numéro 0
	Donne.SetPreneur(lesJoueurs[0]); //On défini le Preneur de la donne
}
#endif

void CDonne::SetDefenseur(CJoueur *defenseur[3])
{
	for (int i = 0; i < 3; i++)
		lesDefenseurs[i] = defenseur[i];
}

#ifdef test_SetDefenseur

void main()
{
	CJoueur* lesJoueurs[4];
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur; //On crée des nouveaux joueurs
	CDonne Donne(lesJoueurs[0]); //On crée une nouvelle donne avec le Donneur numéro 0
	CJoueur* defenseur[3];
	for (int i = 0; i < 3; i++)
		defenseur[i] = lesJoueurs[i + 1]; //On défini les 3 défenseurs
	Donne.SetDefenseur(defenseur);
}
#endif

void CDonne::SetnbPoints(int point)
{
	nbPoints = point;
}

#ifdef test_SetnbPoints
void main()
{
	CJoueur* lesJoueurs[4];
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur; //On crée des nouveaux joueurs
	CDonne Donne(lesJoueurs[0]); //On crée une nouvelle donne avec le Donneur numéro 0
	Donne.SetnbPoints(51);
}
#endif

void CDonne::SetBouts(int bout)
{
	Bouts = bout;
}

#ifdef test_SetBouts
void main()
{
	CJoueur* lesJoueurs[4];
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur; //On crée des nouveaux joueurs
	CDonne Donne(lesJoueurs[0]); //On crée une nouvelle donne avec le Donneur numéro 0
	CDonne Donne2(lesJoueurs[1]);
	CDonne Donne3(lesJoueurs[2]);
	Donne.SetBouts(1);
	Donne2.SetBouts(2);
	Donne3.SetBouts(3);
}
#endif

void CDonne::SetTypeContrat(Contrat contrat)
{
	typeContrat = contrat;
}

#ifdef test_SetTypeContrat
void main()
{
	CJoueur* lesJoueurs[4];
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur; //On crée des nouveaux joueurs
	CDonne Donne(lesJoueurs[0]); //On crée une nouvelle donne avec le Donneur numéro 0
	CDonne Donne2(lesJoueurs[1]);
	CDonne Donne3(lesJoueurs[2]);
	CDonne Donne4(lesJoueurs[4]);
	Donne.SetTypeContrat(Prise);
	Donne2.SetTypeContrat(Garde);
	Donne3.SetTypeContrat(GardeSans);
	Donne4.SetTypeContrat(GardeContre);
}
#endif

void CDonne::SetTypePoignee(Poignee typepoignee)
{
	typePoignee = typepoignee;
}

#ifdef test_SetTypePoignee
void main()
{
	CJoueur* lesJoueurs[4];
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur; //On crée des nouveaux joueurs
	CDonne Donne(lesJoueurs[0]); //On crée une nouvelle donne avec le Donneur numéro 0
	CDonne Donne2(lesJoueurs[1]);
	CDonne Donne3(lesJoueurs[2]);
	Donne.SetTypePoignee(Simple);
	Donne2.SetTypePoignee(Double);
	Donne3.SetTypePoignee(Triple);
}
#endif

void CDonne::SetPetitAuBouts(bool camp)
{
	if (camp == false)
		campPetitAuBout = Defenseur;
	else
		campPetitAuBout = Preneur;
}

#ifdef test_SetPetitAuBouts
void main()
{
	CJoueur* lesJoueurs[4];
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur; //On crée des nouveaux joueurs
	CDonne Donne(lesJoueurs[0]); //On crée une nouvelle donne avec le Donneur numéro 0
	CDonne Donne2(lesJoueurs[1]);
	Donne.SetPetitAuBouts(0);
	Donne2.SetPetitAuBouts(1);
}
#endif

void CDonne::calcul_score()
{
	int PointBouts[4] = { 56,51,41,36 };
	int PointPoignee[4] = { 0, 20, 30, 40 };
	int PointContrat[5] = { 0, 1, 2, 4, 6 };

	int score = nbPoints - PointBouts[Bouts];
	if (score < 0)
		score = ((score - 25) * PointContrat[typeContrat] - PointPoignee[typePoignee]); // Ajouter Le petit au bout
	else
		score = ((score + 25) * PointContrat[typeContrat] + PointPoignee[typePoignee]);

	lePreneur->majScore(score * 3);
	lePreneur->sauvegarde_score_donne(score * 3);

	for (int i = 0; i < 3; i++)
	{
		lesDefenseurs[i]->majScore(-score);
		lesDefenseurs[i]->sauvegarde_score_donne(-score);
	}

	if (campPetitAuBout == Defenseur)
	{
		for (int i = 0; i < 3; i++)
		{
			lesDefenseurs[i]->majScore(10 * PointContrat[typeContrat]);
			lesDefenseurs[i]->sauvegarde_score_donne(10 * PointContrat[typeContrat]);
		}
	}
	else if (campPetitAuBout == Preneur)
	{
		lePreneur->majScore(10 * PointContrat[typeContrat] * 3);
		lePreneur->sauvegarde_score_donne(10 * PointContrat[typeContrat] * 3);
	}
}

#ifdef test_calcul_score
void main()
{
	CJoueur *lesJoueurs[4];
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur; //On crée des nouveaux joueurs
	CDonne Donne(lesJoueurs[0]); //On crée une nouvelle donne avec le Donneur numéro 0
	Donne.SetPreneur(lesJoueurs[0]); //On défini le Preneur de la donne

	CJoueur* defenseur[3];
	for (int i = 0; i < 3; i++)
		defenseur[i] = lesJoueurs[i + 1]; //On défini les 3 défenseurs
	Donne.SetDefenseur(defenseur);
	Donne.SetnbPoints(50); //Nombre de point du preneur = 41
	Donne.SetBouts(1);  //Nombre de bouts du preneur
	Donne.SetTypePoignee(Simple);
	Donne.SetTypeContrat(Prise);
	Donne.calcul_score();  //On calcul
	Donne.save_fin_donne(lesJoueurs, "partie.csv");  //On enregistre dans le .csv pour la lecture
}
#endif

void CDonne::save_fin_donne(CJoueur* lesJoueurs[4], string nom_fichier)
{
	ifstream test_exist(nom_fichier);
	if (test_exist.is_open()) {
		test_exist.close();
		ofstream sauvegarde(nom_fichier, ios::app);
		sauvegarde << endl;
		for (int i = 0; i < 4; i++)
			sauvegarde << lesJoueurs[i]->lireScore() << ";";

		sauvegarde << lePreneur->lireNom() << ";";
		switch (typeContrat)
		{
		case Prise:
			sauvegarde << "Prise";
			break;
		case Garde:
			sauvegarde << "Garde";
			break;
		case GardeSans:
			sauvegarde << "Garde Sans";
			break;
		case GardeContre:
			sauvegarde << "Garde Contre";
			break;
		}
		sauvegarde << ";" << Bouts << ";";
		switch (typePoignee)
		{
		case Sans:
			sauvegarde << "Sans";
			break;
		case Simple:
			sauvegarde << "Simple";
			break;
		case Double:
			sauvegarde << "Double";
			break;
		case Triple:
			sauvegarde << "Triple";
			break;
		}
		sauvegarde << ";";
		switch (campPetitAuBout)
		{
		case Personne:
			sauvegarde << "Personne";
			break;
		case Defenseur:
			sauvegarde << "Defenseur";
			break;
		case Preneur:
			sauvegarde << "Preneur";
			break;
		}
		sauvegarde.close();
	}
	else
	{
		cout << "le fichier n existe pas";
	}


}

#ifdef test_save_fin_donne

void main()
{
	CJoueur* lesJoueurs[4];
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur; //On crée des nouveaux joueurs
	CDonne Donne(lesJoueurs[0]); //On crée une nouvelle donne avec le Donneur numéro 0
	Donne.SetPreneur(lesJoueurs[0]); //On défini le Preneur de la donne

	CJoueur* defenseur[3];
	for (int i = 0; i < 3; i++)
		defenseur[i] = lesJoueurs[i + 1]; //On défini les 3 défenseurs
	Donne.SetDefenseur(defenseur);
	Donne.SetnbPoints(50); //Nombre de point du preneur = 41
	Donne.SetBouts(1);  //Nombre de bouts du preneur
	Donne.SetTypePoignee(Simple);
	Donne.SetTypeContrat(Prise);
	Donne.calcul_score();  //On calcul
	Donne.save_fin_donne(lesJoueurs, "partie.csv");  //On enregistre dans le .csv pour la lecture

}
#endif
