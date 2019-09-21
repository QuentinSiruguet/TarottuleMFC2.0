#pragma once
#include "CORE\Joueur.h"
#include "CORE\Partie.h"
// Boîte de dialogue Score

class Score : public CDialogEx
{
	DECLARE_DYNAMIC(Score)

public:
	Score(CJoueur *lesJoueurs[], CPartie *laPartie, CWnd* pParent = NULL);   // constructeur standard
	virtual ~Score();

	// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	CJoueur *lesJoueurs[4];
	CPartie *laPartie;
	CString nom_joueur_1;
	CString nom_joueur_2;
	CString nom_joueur_3;
	CString nom_joueur_4;
};
