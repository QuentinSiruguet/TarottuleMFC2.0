// Score.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "TarottuleMFC.h"
#include "Score.h"
#include "afxdialogex.h"


// Boîte de dialogue Score

IMPLEMENT_DYNAMIC(Score, CDialogEx)

Score::Score(CJoueur *lesJoueurs[], CPartie *laPartie, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SCORE, pParent)
	, nom_joueur_1(_T(""))
	, nom_joueur_2(_T(""))
	, nom_joueur_3(_T(""))
	, nom_joueur_4(_T(""))
{
	for (int i = 0; i < 4; i++)
		this->lesJoueurs[i] = lesJoueurs[i];
	this->laPartie = laPartie;
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
}


BEGIN_MESSAGE_MAP(Score, CDialogEx)
END_MESSAGE_MAP()


// Gestionnaires de messages de Score
