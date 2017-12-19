// LibraryDlg.h : header file
//

#if !defined(AFX_LIBRARYDLG_H__E9CFAAA4_C2FB_424C_BCA3_9FBFCFE1AAFA__INCLUDED_)
#define AFX_LIBRARYDLG_H__E9CFAAA4_C2FB_424C_BCA3_9FBFCFE1AAFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLibraryDlg dialog

class CLibraryDlg : public CDialog
{
// Construction
public:
	CLibraryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLibraryDlg)
	enum { IDD = IDD_LIBRARY_DIALOG };
	CString	m_UserName;
	CString	m_Password;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibraryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CLibraryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLogin();
	afx_msg void OnRegist();
	afx_msg void OnUser();
	afx_msg void OnBack();
	afx_msg void OnExit();
	afx_msg void OnBook();
	afx_msg void OnQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void SetVisable0(int nCmdShow);
	void SetVisable1(int nCmdShow);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBRARYDLG_H__E9CFAAA4_C2FB_424C_BCA3_9FBFCFE1AAFA__INCLUDED_)
