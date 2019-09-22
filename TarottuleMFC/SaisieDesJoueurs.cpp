// SaisieDesJoueurs.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "TarottuleMFC.h"
#include "SaisieDesJoueurs.h"
#include "afxdialogex.h"
#include "MFC_DONNE.h"


// Boîte de dialogue SaisieDesJoueurs

IMPLEMENT_DYNAMIC(SaisieDesJoueurs, CDialogEx)

SaisieDesJoueurs::SaisieDesJoueurs(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SAISIEDESJOUEURS, pParent)
	, saisie_nom_joueur_1(_T(""))
	, saisie_nom_joueur_2(_T(""))
	, saisie_nom_joueur_3(_T(""))
	, saisie_nom_joueur_4(_T(""))
{
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = new CJoueur;

}

SaisieDesJoueurs::~SaisieDesJoueurs()
{
	delete laPartie;
}

void SaisieDesJoueurs::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CHOIX_JOUEUR1, saisie_nom_joueur_1);
	DDX_Text(pDX, IDC_CHOIX_JOUEUR2, saisie_nom_joueur_2);
	DDX_Text(pDX, IDC_CHOIX_JOUEUR3, saisie_nom_joueur_3);
	DDX_Text(pDX, IDC_CHOIX_JOUEUR4, saisie_nom_joueur_4);
}


BEGIN_MESSAGE_MAP(SaisieDesJoueurs, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SaisieDesJoueurs::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &SaisieDesJoueurs::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &SaisieDesJoueurs::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &SaisieDesJoueurs::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &SaisieDesJoueurs::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON2, &SaisieDesJoueurs::OnBnClickedButton2)
END_MESSAGE_MAP()


// Gestionnaires de messages de SaisieDesJoueurs


void SaisieDesJoueurs::OnBnClickedButton1()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	CDialogEx::OnCancel();
}


void SaisieDesJoueurs::OnEnChangeEdit1()
{
	// TODO:  S'il s'agit d'un contrôle RICHEDIT, le contrôle ne
	// envoyez cette notification sauf si vous substituez CDialogEx::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajouté au masque grâce à l'opérateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieDesJoueurs::OnEnChangeEdit2()
{
	// TODO:  S'il s'agit d'un contrôle RICHEDIT, le contrôle ne
	// envoyez cette notification sauf si vous substituez CDialogEx::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajouté au masque grâce à l'opérateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieDesJoueurs::OnEnChangeEdit3()
{
	// TODO:  S'il s'agit d'un contrôle RICHEDIT, le contrôle ne
	// envoyez cette notification sauf si vous substituez CDialogEx::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajouté au masque grâce à l'opérateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieDesJoueurs::OnEnChangeEdit4()
{
	// TODO:  S'il s'agit d'un contrôle RICHEDIT, le contrôle ne
	// envoyez cette notification sauf si vous substituez CDialogEx::OnInitDialog()
	// fonction et appelle CRichEditCtrl().SetEventMask()
	// avec l'indicateur ENM_CHANGE ajouté au masque grâce à l'opérateur OR.

	// TODO:  Ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void SaisieDesJoueurs::OnBnClickedButton2()
{
	UpdateData(true);
	
	string saisie1(CW2A(saisie_nom_joueur_1.GetString()));
	string saisie2(CW2A(saisie_nom_joueur_2.GetString()));
	string saisie3(CW2A(saisie_nom_joueur_3.GetString()));
	string saisie4(CW2A(saisie_nom_joueur_4.GetString()));
	lesJoueurs[0]->ajout_nom(saisie1);
	lesJoueurs[1]->ajout_nom(saisie2);
	lesJoueurs[2]->ajout_nom(saisie3);
	lesJoueurs[3]->ajout_nom(saisie4);

	UpdateData(false);

	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	laPartie = new CPartie(lesJoueurs);
	laPartie->Nouvelle_donne(lesJoueurs[0]);
	MFC_DONNE Vers_donne(lesJoueurs, laPartie, this);
	Vers_donne.DoModal();
	
	
}

