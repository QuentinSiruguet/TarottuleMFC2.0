// Score.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "TarottuleMFC.h"
#include "Score.h"
#include "afxdialogex.h"
#include "MFC_DONNE.h"


// Boîte de dialogue Score

IMPLEMENT_DYNAMIC(Score, CDialogEx)

Score::Score(CJoueur *lesJoueurs[], CPartie *laPartie, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SCORE, pParent)
	, nom_joueur_1(_T(""))
	, nom_joueur_2(_T(""))
	, nom_joueur_3(_T(""))
	, nom_joueur_4(_T(""))
	, score_donne_1(0)
	, score_donne_2(0)
	, score_donne_3(0)
	, score_donne_4(0)
	, score_total_1(0)
	, score_total_2(0)
	, score_total_3(0)
	, score_total_4(0)
{
	for (int i = 0; i < 4; i++)
		this->lesJoueurs[i] = lesJoueurs[i];
	this->laPartie = laPartie;

	nom_joueur_1 = lesJoueurs[0]->lireNom().c_str();
	nom_joueur_2 = lesJoueurs[1]->lireNom().c_str();
	nom_joueur_3 = lesJoueurs[2]->lireNom().c_str();
	nom_joueur_4 = lesJoueurs[3]->lireNom().c_str();

	score_donne_1 = lesJoueurs[0]->lireScore_donne();
	score_donne_2 = lesJoueurs[1]->lireScore_donne();
	score_donne_3 = lesJoueurs[2]->lireScore_donne();
	score_donne_4 = lesJoueurs[3]->lireScore_donne();

	score_total_1 = lesJoueurs[0]->lireScore();
	score_total_2 = lesJoueurs[1]->lireScore();
	score_total_3 = lesJoueurs[2]->lireScore();
	score_total_4 = lesJoueurs[3]->lireScore();
}


Score::~Score()
{
}

void Score::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PLAYER_NAME1, nom_joueur_1);
	DDX_Text(pDX, IDC_PLAYER_NAME2, nom_joueur_2);
	DDX_Text(pDX, IDC_PLAYER_NAME3, nom_joueur_3);
	DDX_Text(pDX, IDC_PLAYER_NAME4, nom_joueur_4);
	DDX_Text(pDX, IDC_DONNE_SCORE_1, score_donne_1);
	DDX_Text(pDX, IDC_DONNE_SCORE_2, score_donne_2);
	DDX_Text(pDX, IDC_DONNE_SCORE_3, score_donne_3);
	DDX_Text(pDX, IDC_DONNE_SCORE_4, score_donne_4);
	DDX_Text(pDX, IDC_TOTAL_SCORE_1, score_total_1);
	DDX_Text(pDX, IDC_TOTAL_SCORE_2, score_total_2);
	DDX_Text(pDX, IDC_TOTAL_SCORE_3, score_total_3);
	DDX_Text(pDX, IDC_TOTAL_SCORE_4, score_total_4);
}



BEGIN_MESSAGE_MAP(Score, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Score::OnBnClickedButton2)
END_MESSAGE_MAP()


// Gestionnaires de messages de Score


void Score::OnBnClickedButton2()
{

}
