#pragma once
#include "afxwin.h"
#include "CORE/Joueur.h"
#include "CORE/Partie.h"
#include "Score.h"

// Boîte de dialogue MFC_DONNE

class MFC_DONNE : public CDialogEx
{
	DECLARE_DYNAMIC(MFC_DONNE)

public:
	MFC_DONNE(CJoueur * lesJoueurs[],CPartie *laPartie, string, CWnd * pParent);
	// constructeur standard
	virtual ~MFC_DONNE();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DONNE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString STjoueur1;
	CString STjoueur2;
	CString STjoueur3;
	CString STjoueur4;
	afx_msg void OnBnClickedjoueur1();
	afx_msg void OnBnClickedjoueur2();
	afx_msg void OnBnClickedjoueur3();
	afx_msg void OnBnClickedjoueur4();
	afx_msg void OnBnClickedcontrat1();
	afx_msg void OnBnClickedcontrat2();
	afx_msg void OnBnClickedcontrat3();
	afx_msg void OnBnClickedcontrat4();
	afx_msg void OnBnClickedpoignee0();
	afx_msg void OnBnClickedpoignee1();
	afx_msg void OnBnClickedpoignee2();
	afx_msg void OnBnClickedpoignee3();

	afx_msg void OnBnClickedpab0();
	afx_msg void OnBnClickedpab1();
	afx_msg void OnBnClickedpab2();

	afx_msg void OnBnClickedboutonfindonne();
	static int nombre_donne;

private :	
	CPartie *laPartie;
	CJoueur *lesJoueurs[4];
	string nom_fichier;

	int numero_joueur = 1;
	int numero_contrat = 1;
	int numero_poignee = 0;
	int numero_pab = -1;
	bool petitaubout = 0;
	int nbre_point_preneur;
	int Nbre_bout_preneur;
public:
	afx_msg void OnEnChangeSaisiePointpreneur();
	afx_msg void OnEnChangeSaisieNbrebout();
};
