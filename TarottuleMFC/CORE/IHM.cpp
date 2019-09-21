#include "IHM.h"
#include "Partie.h"

//#define test_choix_nom_joueur
//#define test_Afficher_joueur
//#define test_Afficher_score
//#define test_Get_Donneur

IHM::IHM()
{
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur;
	nom_fichier = "partie.csv";
}

IHM::~IHM()
{
	for (int i = 0; i < 4; i++)
		delete lesJoueurs[i];
}

void IHM::nouvelle_partie()
{
	laPartie = new CPartie(lesJoueurs);
}

void IHM::choix_nom_joueur()
{
	cout << "Veuillez saisir dans l’ordre de la donne ( sens inverse d une aiguille d une montre)\n\n";
	for (int i = 0; i < 4; i++)
	{
		string nom;
		cout << "Nom du joueur " << i + 1 << " :";
		cin >> nom;
		lesJoueurs[i]->ajout_nom(nom);
	}
}

#ifdef test_choix_nom_joueur
void main()
{
	IHM ihm;
	ihm.choix_nom_joueur();
	ihm.Afficher_joueur();
}
#endif

void IHM::sauvegarde_avant_donne()
{
	ofstream save(nom_fichier);
	for (int i = 0; i < 4; i++)
	{
		save << lesJoueurs[i]->lireNom() << ";";
	}
	save << "Preneur;Contrat;Nombre de bouts;Poignee;Petit au bout;";
	save.close();
}

void IHM::Typecontrat()
{
	int numero_joueur;
	int numero_contrat;

	cout << "\nVeuillez saisir le chiffre du joueur ayant fait le plus haut contrat (preneur) : ";
	cin >> numero_joueur;
	if (numero_joueur >= 5)
	{
		while (numero_joueur >= 5)
		{
			cout << "\nNumero incorrect, veuillez un numero de joueur correct : ";
			cin >> numero_joueur;

		}
	}
	laPartie->Definir_IMH_Donne_Camp(numero_joueur);

	cout << "\nChoix du chiffre pour le contrat :\n" "1 : PRISE ou PETITE\n"  "2 : GARDE\n" "3 : GARDE SANS LE CHIEN\n" "4 : GARDE CONTRE LE CHIEN\n";
	cout << "\nVeuillez saisir le chiffre du contrat choisie : ";
	cin >> numero_contrat;
	if (numero_contrat >= 5)
	{
		while (numero_contrat >= 5)
		{
			cout << "\nNumero incorrect, veuillez saisir un numero de contrat compris entre 1 et 4 : ";
			cin >> numero_contrat;
		}
	}
	Contrat Typecontrat = static_cast<Contrat>(numero_contrat);
	laPartie->Transfert_IHM_Donne_contrat(Typecontrat);
}

void IHM::Choix_Poignee() {
	char choixPoignee;
	cout << "\nUn joueur souhaite t il annoncer une poignee ? O ou N : \n";
	cin >> choixPoignee;
	switch (choixPoignee)
	{
	case 'O':
	case 'o':
		Opoigner();
		break;


	case 'N':
	case 'n':
		////
		break;
	default:
		cout << "\nChoix incorrect";

	}


}

void IHM::Opoigner() {

	int numero_poignee;

	cout << "\nQue souhaite faire comme annonce : \n" "1 : Simple poignee\n" "2 : Double poignee\n" "3 : Triple poignee\n";
	cout << "\nSaisir le numero d annonce(1~3) : ";
	cin >> numero_poignee;
	if (numero_poignee >= 4)
	{
		while (numero_poignee >= 4)
		{
			cout << "\nNumero incorrect, veuillez saisir un numero d'annonce compris entre 1 et 3 : \n";
			cin >> numero_poignee;
		}
	}

	laPartie->Transfert_IHM_Donne_poignee(static_cast<Poignee>(numero_poignee));

}

void IHM::Point_Preneur()
{
	int preneur_point;
	int preneur_bout;
	cout << "\nVeuillez saisir le nombres de point du preneur: \n";
	cin >> preneur_point;
	laPartie->Transfert_IHM_Donne_points(preneur_point);

	cout << "\nVeuillez saisir le nombre de bout du preneur (1~3): \n";
	cin >> preneur_bout;
	laPartie->Transfert_IHM_Donne_bouts(preneur_bout);
}

void IHM::lire() {
	cout << "Voulez-vous reprendre une partie ?O ou N" << endl;
	
	char oui_non;
	cin >> oui_non;
	ifstream *get_player;
	ifstream *get_score;
	int nbligne = 0;
	switch (oui_non)
	{
	case 'O':
		cout << "Quel est le nom du fichier ? ";
		cin >> nom_fichier;
		get_player = new ifstream(nom_fichier);

		char name[100];
		for (int i = 0; i < 4; i++)
		{
			get_player->getline(name, 100, ';');
			string str_name = name;
			lesJoueurs[i]->ajout_nom(str_name);
		}
		get_player->getline(name, 100);
		
		while (get_player->getline(name, 100))
			nbligne++;
		get_player->close();
		delete get_player;

		get_score = new ifstream(nom_fichier);
		while (nbligne != 0)
		{
			get_score->getline(name, 100);
			nbligne--;
		}


		char score[100];
		int score_int;
		for (int i = 0; i < 4; i++)
		{
			get_score->getline(score,100, ';');
			score_int = atoi(score);
			lesJoueurs[i]->majScore(score_int);
		}
		get_score->close();
		break;
	case 'N':
		choix_nom_joueur();
		sauvegarde_avant_donne();
		break;
	}

}

void IHM::Saisie_petit_au_bout()
{
	char choix_Petit_au_bout;
	int numero_camp;
	bool Reussie_ou_pas;

	cout << "Est ce qu il y a un petit au bout (O/N) : \n";
	cin >> choix_Petit_au_bout;

	if (choix_Petit_au_bout == 'O' || choix_Petit_au_bout == 'o')
	{
		cout << "Quel camp à recupere le petit au bout lors de la levee ? : \n\n";

		cout << " '0' pour Defenseur et '1' pour Preneur : \n";
		cin >> numero_camp;

		if (numero_camp == 0)
			Reussie_ou_pas = false;


		else if (numero_camp == 1)
			Reussie_ou_pas = true;

		laPartie->Transfert_IHM_Donne_petit_au_bouts(Reussie_ou_pas);
	}

}

void IHM::Fin_donne()
{
	laPartie->Fin_Donne(nom_fichier);
}

void IHM::Nouvelle_donne(int joueur)
{
	joueur--;
	laPartie->Nouvelle_donne(lesJoueurs[joueur]);
}

bool IHM::Fin_partie()
{
	char reponse;
	cout << "Voulez vous continuer? N ou O \n\n";
	cin >> reponse;
	if (reponse == 'N')
	{
		delete laPartie;
		return false;
	}
	else return true;
}

void IHM::Afficher_joueur() {
	for (int i = 0; i < 4; i++)
		cout << "Joueur " << i+1 << " : " << lesJoueurs[i]->lireNom() << endl;
}

#ifdef test_Afficher_joueur
void main()
{
	IHM ihm;
	ihm.lire();
	ihm.nouvelle_partie();
	ihm.Afficher_joueur();
}
#endif

void IHM::Afficher_score()
{
	for (int i = 0; i < 4; i++) 
		cout << lesJoueurs[i]->lireNom() << "\t\t";

	cout << endl;
	for (int j = 0; j < 4; j++)
	{
		cout << lesJoueurs[j]->lireScore_donne() << "\t\t";
		lesJoueurs[j]->sauvegarde_score_donne(0);
	}

	cout << endl;
	for (int j = 0; j < 4; j++) 
		cout << lesJoueurs[j]->lireScore() << "\t\t";

	cout << endl;
}

#ifdef test_Afficher_score
void main()
{
	IHM ihm;
	int nombre_donne = 0;
	bool continuer = 1;

	ihm.lire();
	ihm.nouvelle_partie();

	while (continuer == 1)
	{
		system("cls");
		ihm.Afficher_joueur();
		cout << "Le Donneur est : " << ihm.Get_Donneur(nombre_donne % 4);
		ihm.Nouvelle_donne(nombre_donne % 4);
		ihm.Typecontrat();
		ihm.Choix_Poignee();
		ihm.Saisie_petit_au_bout();
		ihm.Point_Preneur();
		ihm.Fin_donne();
		ihm.Afficher_score();
		continuer = ihm.Fin_partie();
		nombre_donne++;
	}
}
#endif

string IHM::Get_Donneur(int joueur)
{
	return lesJoueurs[joueur]->lireNom();
}

#ifdef test_Get_Donneur
void main()
{
	IHM ihm;
	int nombre_donne = 0;
	ihm.lire();
	ihm.nouvelle_partie();
	while (nombre_donne != 5)
	{
		cout << "Le Donneur est : " << ihm.Get_Donneur(nombre_donne % 4);
		nombre_donne++;
	}
}
#endif  