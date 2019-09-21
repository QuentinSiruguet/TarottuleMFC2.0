#pragma once
#include "Joueur.h"
#include "Donne.h"

class CPartie
{
private:
	CJoueur *lesJoueurs[4];
	CDonne **lesDonnes;
	int nombre_donne;
public:
	CPartie(CJoueur *joueurs[4]);
	~CPartie();
	void Nouvelle_donne(CJoueur*);
	void Fin_Donne(string);
	void Transfert_IHM_Donne_points(int);
	void Transfert_IHM_Donne_bouts(int);
	void Transfert_IHM_Donne_contrat(Contrat);
	void Transfert_IHM_Donne_poignee(Poignee);
	void Transfert_IHM_Donne_petit_au_bouts(bool);
	void Definir_IMH_Donne_Camp(int);


};