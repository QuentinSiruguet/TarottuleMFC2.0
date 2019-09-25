// MFC_DONNE.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "TarottuleMFC.h"
#include "MFC_DONNE.h"
#include "afxdialogex.h"
#include "CORE/Joueur.h"


// Boîte de dialogue MFC_DONNE

IMPLEMENT_DYNAMIC(MFC_DONNE, CDialogEx)


MFC_DONNE::MFC_DONNE(CJoueur *lesJoueurs[], CPartie *laPartie,string nom_fichier, CWnd* pParent)
	: CDialogEx(IDD_MFC_DONNE, pParent)
	, STjoueur1(_T(""))
	, STjoueur2(_T(""))
	, STjoueur3(_T(""))
	, STjoueur4(_T(""))
	, nbre_point_preneur(0)
	, Nbre_bout_preneur(0)
{
	for (int i = 0; i < 4; i++)
		this->lesJoueurs[i] = lesJoueurs[i];

	this->laPartie = laPartie;
	this->nom_fichier = nom_fichier;
	MFC_DONNE::nombre_donne++;
	laPartie->Nouvelle_donne(lesJoueurs[nombre_donne%4]);

	STjoueur1 = lesJoueurs[0]->lireNom().c_str();
	STjoueur2 = lesJoueurs[1]->lireNom().c_str();
	STjoueur3 = lesJoueurs[2]->lireNom().c_str();
	STjoueur4 = lesJoueurs[3]->lireNom().c_str();

	nbre_point_preneur = 0;
	Nbre_bout_preneur = 0;
}

MFC_DONNE::~MFC_DONNE()
{
}

void MFC_DONNE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDST_Joueur1, STjoueur1);
	DDX_Text(pDX, IDST_Joueur2, STjoueur2);
	DDX_Text(pDX, IDST_Joueur3, STjoueur3);
	DDX_Text(pDX, IDST_Joueur4, STjoueur4);
	///
	DDX_Text(pDX, IDC_Saisie_PointPreneur, nbre_point_preneur);
	DDV_MinMaxInt(pDX, nbre_point_preneur, 0, 100);
	DDX_Text(pDX, IDC_Saisie_NbreBout, Nbre_bout_preneur);
	DDV_MinMaxInt(pDX, Nbre_bout_preneur, 0, 3);
}


BEGIN_MESSAGE_MAP(MFC_DONNE, CDialogEx)

	ON_BN_CLICKED(IDRB_joueur1, &MFC_DONNE::OnBnClickedjoueur1)
	ON_BN_CLICKED(IDRB_joueur2, &MFC_DONNE::OnBnClickedjoueur2)
	ON_BN_CLICKED(IDRB_joueur3, &MFC_DONNE::OnBnClickedjoueur3)
	ON_BN_CLICKED(IDRB_joueur4, &MFC_DONNE::OnBnClickedjoueur4)
	ON_BN_CLICKED(IDRB_contrat1, &MFC_DONNE::OnBnClickedcontrat1)
	ON_BN_CLICKED(IDRB_contrat2, &MFC_DONNE::OnBnClickedcontrat2)
	ON_BN_CLICKED(IDRB_contrat3, &MFC_DONNE::OnBnClickedcontrat3)
	ON_BN_CLICKED(IDRB_contrat4, &MFC_DONNE::OnBnClickedcontrat4)
	//	ON_CBN_SELCHANGE(IDC_COMBO1, &MFC_DONNE::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_poignee1, &MFC_DONNE::OnBnClickedpoignee1)
	ON_BN_CLICKED(IDC_poignee0, &MFC_DONNE::OnBnClickedpoignee0)
	ON_BN_CLICKED(IDC_poignee2, &MFC_DONNE::OnBnClickedpoignee2)
	ON_BN_CLICKED(IDC_poignee3, &MFC_DONNE::OnBnClickedpoignee3)
	ON_BN_CLICKED(IDC_pab0, &MFC_DONNE::OnBnClickedpab0)
	ON_BN_CLICKED(IDC_pab1, &MFC_DONNE::OnBnClickedpab1)
	ON_BN_CLICKED(IDC_pab2, &MFC_DONNE::OnBnClickedpab2)
	ON_BN_CLICKED(ID_bouton_fin_donne, &MFC_DONNE::OnBnClickedboutonfindonne)
	ON_EN_CHANGE(IDC_Saisie_PointPreneur, &MFC_DONNE::OnEnChangeSaisiePointpreneur)
	ON_EN_CHANGE(IDC_Saisie_NbreBout, &MFC_DONNE::OnEnChangeSaisieNbrebout)
END_MESSAGE_MAP()


// Gestionnaires de messages de MFC_DONNE




void MFC_DONNE::OnBnClickedjoueur1()
{
	numero_joueur = 1;
}

void MFC_DONNE::OnBnClickedjoueur2()
{
	numero_joueur = 2;
}

void MFC_DONNE::OnBnClickedjoueur3()
{
	numero_joueur = 3;
}

void MFC_DONNE::OnBnClickedjoueur4()
{
	numero_joueur = 4;
}

void MFC_DONNE::OnBnClickedcontrat1()
{
	numero_contrat = 1;
}

void MFC_DONNE::OnBnClickedcontrat2()
{
	numero_contrat = 2;
}

void MFC_DONNE::OnBnClickedcontrat3()
{
	numero_contrat = 3;
}

void MFC_DONNE::OnBnClickedcontrat4()
{
	numero_contrat = 4;
}

void MFC_DONNE::OnBnClickedpoignee0()
{
	numero_poignee = 0;
}

void MFC_DONNE::OnBnClickedpoignee1()
{
	numero_poignee = 1;
}

void MFC_DONNE::OnBnClickedpoignee2()
{
	numero_poignee = 2;
}

void MFC_DONNE::OnBnClickedpoignee3()
{
	numero_poignee = 3;
}

void MFC_DONNE::OnBnClickedpab0()
{
	numero_pab = -1;
}

void MFC_DONNE::OnBnClickedpab1()
{
	numero_pab = 0;
}

void MFC_DONNE::OnBnClickedpab2()
{
	numero_pab = 1;
}

void MFC_DONNE::OnBnClickedboutonfindonne()
{
	UpdateData(true);
	int point_preneur = nbre_point_preneur;
	int bout_preneur = Nbre_bout_preneur;
	UpdateData(false);

	laPartie->Definir_IMH_Donne_Camp(numero_joueur);
	laPartie->Transfert_IHM_Donne_contrat(static_cast<Contrat>(numero_contrat));
	laPartie->Transfert_IHM_Donne_poignee(static_cast<Poignee>(numero_poignee));
	if (numero_pab == 0)
		laPartie->Transfert_IHM_Donne_petit_au_bouts(false);
	else if (numero_pab == 1)
		laPartie->Transfert_IHM_Donne_petit_au_bouts(true);
	laPartie->Transfert_IHM_Donne_points(point_preneur);
	laPartie->Transfert_IHM_Donne_bouts(bout_preneur);
	laPartie->Fin_Donne(nom_fichier);
	
	Score score(lesJoueurs, laPartie, nom_fichier, this);
	PostMessage(WM_KEYDOWN, VK_ESCAPE, 0);
	score.DoModal();
}


void MFC_DONNE::OnEnChangeSaisiePointpreneur()
{
	UpdateData(true);
	if (nbre_point_preneur < 0 || nbre_point_preneur > 100)
		nbre_point_preneur = 0;
	UpdateData(false);
}


void MFC_DONNE::OnEnChangeSaisieNbrebout()
{
	UpdateData(true);
	if (Nbre_bout_preneur < 0 || Nbre_bout_preneur > 3)
		Nbre_bout_preneur = 0;
	UpdateData(false);
}