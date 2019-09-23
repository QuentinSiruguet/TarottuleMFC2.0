// Menu.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "TarottuleMFC.h"
#include "Menu.h"
#include "afxdialogex.h"
#include "SaisieDesJoueurs.h"


// Boîte de dialogue Menu

IMPLEMENT_DYNAMIC(Menu, CDialogEx)

Menu::Menu(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MENU, pParent)
{
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur;

	laPartie = new CPartie(lesJoueurs);

	nom_fichier = "save.csv";
}

Menu::~Menu()
{
	delete laPartie;
}

void Menu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Menu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Menu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Menu::OnBnClickedButton4)
END_MESSAGE_MAP()


// Gestionnaires de messages de Menu


void Menu::OnBnClickedButton1()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	SaisieDesJoueurs DialogJoueurs(lesJoueurs, laPartie, this, nom_fichier);
	PostMessage(WM_KEYDOWN, VK_ESCAPE, 0);
	DialogJoueurs.DoModal();

}


void Menu::OnBnClickedButton4()
{



	ifstream *get_player;
	ifstream *get_score;
	int nbligne = 0;
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
		get_score->getline(score, 100, ';');
		score_int = atoi(score);
		lesJoueurs[i]->majScore(score_int);
	}
	get_score->close();


	MFC_DONNE Vers_donne(lesJoueurs, laPartie, nom_fichier, this);
	PostMessage(WM_KEYDOWN, VK_ESCAPE, 0);
	Vers_donne.DoModal();
}
