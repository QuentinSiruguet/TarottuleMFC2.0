#pragma once


// Boîte de dialogue Menu

class Menu : public CDialogEx
{
	DECLARE_DYNAMIC(Menu)

public:
	Menu(CWnd* pParent = NULL);   // constructeur standard
	virtual ~Menu();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
