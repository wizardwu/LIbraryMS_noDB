// LibraryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "LibraryDlg.h"
#include "Regist.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLibraryDlg dialog
extern MSXML2::IXMLDOMDocumentPtr pDoc;
extern MSXML2::IXMLDOMElementPtr xmlRoot;
CLibraryDlg::CLibraryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLibraryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLibraryDlg)
	m_UserName = _T("");
	m_Password = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLibraryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLibraryDlg)
	DDX_Text(pDX, IDC_USERNAME, m_UserName);
	DDX_Text(pDX, IDC_PASSWORD, m_Password);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLibraryDlg, CDialog)
	//{{AFX_MSG_MAP(CLibraryDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	ON_BN_CLICKED(IDC_REGIST, OnRegist)
	ON_BN_CLICKED(IDC_USER, OnUser)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_BOOK, OnBook)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibraryDlg message handlers

BOOL CLibraryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	HRESULT hr=pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument));
	if(FAILED(hr)){
		MessageBox(_T("�޷�����DOMDocument����"));
		CDialog::OnCancel();
	}
	CFileFind find;
	if(find.FindFile(_T("./lib.dat"))){
		pDoc->load(_T("./lib.dat"));							//��ʼ��ȫ�ֱ���
		xmlRoot=pDoc->selectSingleNode((_bstr_t)"Library");
		if(xmlRoot==NULL){
			MessageBox("��Ϣ�洢�ļ��д���");
			CDialog::OnCancel();
		}
	}
	else{
		int nRet=MessageBox(_T("�����Ϣ�����ڣ��Ƿ񴴽���"),0,MB_YESNO|MB_ICONQUESTION);
		if(nRet==IDYES){
			MessageBox(_T("�²����Ĺ���Ա�˻��û����������Ϊadmin,\n�뾡���½�޸ģ�"),0,MB_ICONWARNING);
			xmlRoot=pDoc->createElement((_bstr_t)"Library");	//�½����ڵ�
			pDoc->appendChild(xmlRoot);
			MSXML2::IXMLDOMElementPtr pNode=pDoc->createElement((_bstr_t)"User");	//�½��ڵ�User
			pNode->setAttribute((_bstr_t)"Name",_T("admin"));						//����Name="admin"
			xmlRoot->appendChild(pNode);											//���ýڵ㸽�ڸ��ڵ���
			
			MSXML2::IXMLDOMElementPtr pSubNode=pDoc->createElement((_bstr_t)"Password");
			pSubNode->Puttext((_bstr_t)"admin");
			pNode->appendChild(pSubNode);

			pSubNode=pDoc->createElement((_bstr_t)"Type");
			pSubNode->Puttext((_bstr_t)"admin");
			pNode->appendChild(pSubNode);

			hr=pDoc->save(_T("./lib.dat"));
			if(FAILED(hr)){
				MessageBox(_T("�ļ�����ʧ�ܣ�"));
				CDialog::OnCancel();
			}
		}
		else CDialog::OnCancel();
	}
	SetVisable1(SW_HIDE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLibraryDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLibraryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLibraryDlg::SetVisable0(int nCmdShow)
{
	(CButton *)GetDlgItem(IDC_USER)->ShowWindow(nCmdShow);
	(CButton *)GetDlgItem(IDC_BOOK)->ShowWindow(nCmdShow);
	(CButton *)GetDlgItem(IDC_QUERY)->ShowWindow(nCmdShow);
}
void CLibraryDlg::SetVisable1(int nCmdShow)
{
	(CStatic *)GetDlgItem(IDC_STATIC0)->ShowWindow(nCmdShow);
	(CStatic *)GetDlgItem(IDC_STATIC1)->ShowWindow(nCmdShow);
	(CStatic *)GetDlgItem(IDC_STATIC2)->ShowWindow(nCmdShow);
	(CEdit *)GetDlgItem(IDC_USERNAME)->ShowWindow(nCmdShow);
	(CEdit *)GetDlgItem(IDC_PASSWORD)->ShowWindow(nCmdShow);
	(CButton *)GetDlgItem(IDC_REGIST)->ShowWindow(nCmdShow);
	(CButton *)GetDlgItem(IDC_LOGIN)->ShowWindow(nCmdShow);
	(CButton *)GetDlgItem(IDC_BACK)->ShowWindow(nCmdShow);
}

void CLibraryDlg::OnUser() 
{
	// TODO: Add your control notification handler code here
	SetVisable0(SW_HIDE);
	SetVisable1(SW_SHOW);
}

void CLibraryDlg::OnBack() 
{
	// TODO: Add your control notification handler code here
	SetVisable0(SW_SHOW);
	SetVisable1(SW_HIDE);
}

void CLibraryDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CLibraryDlg::OnLogin() 
{
	// TODO: Add your control notification handler code here
//	if(1)this->ShowWindow(SW_HIDE);
	UpdateData(TRUE);
	CString strAdminSel;
	strAdminSel.Format("/Library/User[@Name=\'%s\']",m_UserName);
	MSXML2::IXMLDOMElementPtr pNode=pDoc->selectSingleNode((_bstr_t)strAdminSel);
	
	if(pNode){		
		if(pNode->selectSingleNode("./Password")->Gettext()==m_Password){
			CString Msg("��½�ɹ���\n��ã�");
			CString UType((char *)(pNode->selectSingleNode("./Type")->Gettext()));
			Msg=Msg+m_UserName+"!\n"+"�ʻ����ͣ�"+UType;
			MessageBox(_T(Msg));
//			if(UType=="admin")	//�򿪹���Ա����
//			else				//����ͨ�û�����
		}
		else MessageBox("�������");
	}
	else MessageBox("�û��������ڣ�");

}

void CLibraryDlg::OnRegist() 
{
	// TODO: Add your control notification handler code here
	CRegist Regist;
	Regist.DoModal();
}

void CLibraryDlg::OnBook() 
{
	// TODO: Add your control notification handler code here
	
}

void CLibraryDlg::OnQuery() 
{
	// TODO: Add your control notification handler code here
	
}
