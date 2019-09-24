#pragma once
#include <string>

#include "CORE\Partie.h"
#include "CORE\Joueur.h"

// Boîte de dialogue SaisieNomFichier

class SaisieNomFichier : public CDialogEx
{
	DECLARE_DYNAMIC(SaisieNomFichier)

public:
	SaisieNomFichier(string *, CWnd* pParent = NULL);   // constructeur standard
	virtual ~SaisieNomFichier();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAISIENOMFICHIER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString saisie_nom_fichier;
	string *nom_fichier;
	afx_msg void OnBnClickedSuivant();
};
