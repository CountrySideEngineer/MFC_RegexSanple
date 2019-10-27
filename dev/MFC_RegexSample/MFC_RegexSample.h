
// MFC_RegexSample.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFCRegexSampleApp:
// このクラスの実装については、MFC_RegexSample.cpp を参照してください
//

class CMFCRegexSampleApp : public CWinApp
{
public:
	CMFCRegexSampleApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFCRegexSampleApp theApp;
