#pragma once

#include "CORE\Partie.h"
#include "CORE\Joueur.h"
// Boîte de dialogue SaisieDesJoueurs

class SaisieDesJoueurs : public CDialogEx
{
	DECLARE_DYNAMIC(SaisieDesJoueurs)

public:
	SaisieDesJoueurs(CWnd* pParent = NULL);   // constructeur standard
	virtual ~SaisieDesJoueurs();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAISIEDESJOUEURS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton2();


private:
	CJoueur *lesJoueurs[4];
	CPartie *laPartie;


	CString saisie_nom_joueur_1;
	CString saisie_nom_joueur_2;
	CString saisie_nom_joueur_3;
	CString saisie_nom_joueur_4;
};


