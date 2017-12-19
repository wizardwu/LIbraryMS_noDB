#if !defined(AFX_REGIST_H__34DD55E4_7E08_453C_8F0B_342ED1B76159__INCLUDED_)
#define AFX_REGIST_H__34DD55E4_7E08_453C_8F0B_342ED1B76159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Regist.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegist dialog

class CRegist : public CDialog
{
// Construction
public:
	CRegist(CWnd* pParent = NULL);   // standard constructor
	bool IsAdmin;
// Dialog Data
	//{{AFX_DATA(CRegist)
	enum { IDD = IDD_REGIST };
	CString	m_Password;
	CString	m_PasswordRep;
	CString	m_UserName;
	CString	m_UserType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegist)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CRegist)
	afx_msg void OnRegistClear();
	afx_msg void OnRegistSubmit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGIST_H__34DD55E4_7E08_453C_8F0B_342ED1B76159__INCLUDED_)
