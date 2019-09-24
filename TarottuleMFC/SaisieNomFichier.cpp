// SaisieNomFichier.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "TarottuleMFC.h"
#include "SaisieNomFichier.h"
#include "afxdialogex.h"


// Boîte de dialogue SaisieNomFichier

IMPLEMENT_DYNAMIC(SaisieNomFichier, CDialogEx)

SaisieNomFichier::SaisieNomFichier(string *nom_fichier, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SAISIENOMFICHIER, pParent)
	, saisie_nom_fichier(_T(""))
{
	this->nom_fichier = nom_fichier;
}

SaisieNomFichier::~SaisieNomFichier()
{
}

void SaisieNomFichier::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SAISIENOMFICHIER, saisie_nom_fichier);
}


BEGIN_MESSAGE_MAP(SaisieNomFichier, CDialogEx)
	ON_BN_CLICKED(IDC_SUIVANT, &SaisieNomFichier::OnBnClickedSuivant)
END_MESSAGE_MAP()


// Gestionnaires de messages de SaisieNomFichier


void SaisieNomFichier::OnBnClickedSuivant()
{
	UpdateData(true);
	string saisie(CW2A(saisie_nom_fichier.GetString()));
	*nom_fichier = saisie;
	UpdateData(false);
	PostMessage(WM_KEYDOWN, VK_ESCAPE, 0);
}
