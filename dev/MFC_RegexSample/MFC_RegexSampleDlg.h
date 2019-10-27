
// MFC_RegexSampleDlg.h : ヘッダー ファイル
//
#include "CStateStatic.h"
#include "CRegexCheck.h"
#pragma once


// CMFCRegexSampleDlg ダイアログ
class CMFCRegexSampleDlg : public CDialogEx
{
// コンストラクション
public:
	CMFCRegexSampleDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_REGEXSAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	CString m_CheckString;	//確認対象の文字列
	CString m_RegExpress;	//正規表現

	CRegexCheck	m_RegExCheck;

protected:	//メソッド

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnEnChangeEditCheckString();
	CStateStatic m_ResultLabel;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
