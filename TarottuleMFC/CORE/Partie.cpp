#include "Partie.h"

CPartie::CPartie(CJoueur *joueurs[4])
{
	for (int i = 0; i < 4; i++)
		lesJoueurs[i] = joueurs[i];
	lesDonnes = new CDonne*[100];
	nombre_donne = 0;
}

CPartie::~CPartie()
{
	delete lesDonnes;
}

void CPartie::Nouvelle_donne(CJoueur* donneur)
{
	lesDonnes[nombre_donne] = new CDonne(donneur);
}

void CPartie::Fin_Donne(string nom_fichier)
{
	lesDonnes[nombre_donne]->calcul_score();
	lesDonnes[nombre_donne]->save_fin_donne(lesJoueurs, nom_fichier);
	delete lesDonnes[nombre_donne];
	nombre_donne++;
}

void CPartie::Transfert_IHM_Donne_points(int point)
{
	lesDonnes[nombre_donne]->SetnbPoints(point);
}

void CPartie::Transfert_IHM_Donne_bouts(int bout)
{
	lesDonnes[nombre_donne]->SetBouts(bout);
}

void CPartie::Transfert_IHM_Donne_contrat(Contrat contrat)
{
	lesDonnes[nombre_donne]->SetTypeContrat(contrat);
}

void CPartie::Transfert_IHM_Donne_poignee(Poignee typepoignee)
{
	lesDonnes[nombre_donne]->SetTypePoignee(typepoignee);
}

void CPartie::Transfert_IHM_Donne_petit_au_bouts(bool camp)
{
	lesDonnes[nombre_donne]->SetPetitAuBouts(camp);
}

void CPartie::Definir_IMH_Donne_Camp(int preneur)
{
	CJoueur *defenseur[3];
	int nombre_defenseur = 0;
	lesDonnes[nombre_donne]->SetPreneur(lesJoueurs[preneur - 1]);
	for (int i = 0; i < 4; i++)
	{
		if (i != (preneur - 1))
		{
			defenseur[nombre_defenseur] = lesJoueurs[i];
			nombre_defenseur++;
		}
	}
	lesDonnes[nombre_donne]->SetDefenseur(defenseur);
}
