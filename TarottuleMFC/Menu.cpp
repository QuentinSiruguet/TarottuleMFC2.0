// Menu.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "TarottuleMFC.h"
#include "Menu.h"
#include "afxdialogex.h"
#include "SaisieDesJoueurs.h"


// Boîte de dialogue Menu

IMPLEMENT_DYNAMIC(Menu, CDialogEx)

Menu::Menu(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MENU, pParent)
{

}

Menu::~Menu()
{
}

void Menu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Menu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Menu::OnBnClickedButton1)
END_MESSAGE_MAP()


// Gestionnaires de messages de Menu


void Menu::OnBnClickedButton1()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	SaisieDesJoueurs DialogJoueurs(this);
	DialogJoueurs.DoModal();

}
