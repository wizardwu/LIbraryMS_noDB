// Regist.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "Regist.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegist dialog

extern MSXML2::IXMLDOMDocumentPtr pDoc;
extern MSXML2::IXMLDOMElementPtr xmlRoot;

CRegist::CRegist(CWnd* pParent /*=NULL*/)
	: CDialog(CRegist::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegist)
	IsAdmin = false;
	m_Password = _T("");
	m_PasswordRep = _T("");
	m_UserName = _T("");
	m_UserType = _T("student");
	//}}AFX_DATA_INIT
}


void CRegist::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegist)
	DDX_Text(pDX, IDC_REGIST_PWD, m_Password);
	DDX_Text(pDX, IDC_REGIST_PWD_REP, m_PasswordRep);
	DDX_Text(pDX, IDC_REGIST_UNAME, m_UserName);
	DDX_CBString(pDX, IDC_REGIST_UTYPE, m_UserType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegist, CDialog)
	//{{AFX_MSG_MAP(CRegist)
	ON_BN_CLICKED(IDC_REGIST_CLEAR, OnRegistClear)
	ON_BN_CLICKED(IDC_REGIST_SUBMIT, OnRegistSubmit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegist message handlers

void CRegist::OnRegistClear() 
{
	// TODO: Add your control notification handler code here
	m_Password="";
	m_PasswordRep="";
	m_UserName="";
	m_UserType="";
	UpdateData(FALSE);
}

void CRegist::OnRegistSubmit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_UserName.IsEmpty()||m_UserType.IsEmpty()||m_Password.IsEmpty()||m_PasswordRep.IsEmpty()){
		MessageBox(_T("信息不全！"));
		return;
	}
	CString strFilter;
	strFilter.Format("/Library/User[@Name='%s']",m_UserName);
	MSXML2::IXMLDOMElementPtr pNode=pDoc->selectSingleNode((_bstr_t)strFilter);
	if(pNode==NULL){
		if(m_UserType=="admin"&&!IsAdmin){
			MessageBox(_T("非管理员用户不能创建管理员用户！"));
			return;
		}
		if(m_Password!=m_PasswordRep)
			MessageBox(_T("两次输入的密码不一致！"));

		pNode=pDoc->createElement((_bstr_t)"User");
		pNode->setAttribute((_bstr_t)"Name",m_UserName.GetBuffer(0));
		xmlRoot->appendChild(pNode);

		MSXML2::IXMLDOMElementPtr pSubNode=pDoc->createElement((_bstr_t)"Password");
		pSubNode->Puttext((_bstr_t)m_Password);
		pNode->appendChild(pSubNode);

		pSubNode=pDoc->createElement((_bstr_t)"Type");
		pSubNode->Puttext((_bstr_t)m_UserType);
		pNode->appendChild(pSubNode);
		
		HRESULT hr=pDoc->save(_T("./lib.dat"));
		if(FAILED(hr))MessageBox(_T("保存文件失败！"));
		else{
			MessageBox("添加用户成功！");
		}

	}
	else MessageBox(_T("用户名已存在！"));
}
