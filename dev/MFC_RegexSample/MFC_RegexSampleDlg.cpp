
// MFC_RegexSampleDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "MFC_RegexSample.h"
#include "MFC_RegexSampleDlg.h"
#include "afxdialogex.h"
#include "CRegexCheck.h"
#include "MyMessage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCRegexSampleDlg ダイアログ



CMFCRegexSampleDlg::CMFCRegexSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_REGEXSAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCRegexSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CHECK_STRING, this->m_CheckString);
	DDX_Text(pDX, IDC_EDIT_REG_EXPRESS, this->m_RegExpress);

	DDX_Control(pDX, IDC_RESULT_LABEL, m_ResultLabel);
}

BEGIN_MESSAGE_MAP(CMFCRegexSampleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCRegexSampleDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCRegexSampleDlg メッセージ ハンドラー

BOOL CMFCRegexSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	//イベントリスナー、およびイベント情報を設定する。
	this->m_RegExCheck.SetEventId(REGEX_SAMPLE_MESSAGE_UPDATE_STATE);
	this->m_RegExCheck.AddEventListener(&(this->m_ResultLabel));

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMFCRegexSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMFCRegexSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/**
 *	確認実施ボタンに対するイベントハンドラ
 */
void CMFCRegexSampleDlg::OnBnClickedButton1()
{
	this->UpdateData();	//現在の入力を取得する。

	if ((_T("") == this->m_CheckString) || (_T("") == this->m_RegExpress)) {
		AfxMessageBox(_T("確認対象の文字列、正規表現の両方を入力してください。"), MB_OK);
		return;
	}

	this->m_RegExCheck.Run(this->m_CheckString, this->m_RegExpress);
}

/**
 *	キー入力のイベントリスナ
 *	※ENTERキーとESCキーの押下をキャンセルするために、追加で実装。
 */
BOOL CMFCRegexSampleDlg::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message) {
		if (VK_RETURN == pMsg->wParam) {
			TRACE(_T("ENTER KEY pressed.\n"));
			return TRUE;
		}
		else if (VK_ESCAPE == pMsg->lParam) {
			TRACE(_T("ESCAPE KEY pressed.\n"));
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
