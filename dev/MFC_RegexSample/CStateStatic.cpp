#include "pch.h"
#include "MyMessage.h"
#include "CStateStatic.h"
#include "CRegexCheck.h"


IMPLEMENT_DYNAMIC(CStateStatic, CStatic)

BEGIN_MESSAGE_MAP(CStateStatic, CStatic)
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_MOVE()
	ON_MESSAGE(REGEX_SAMPLE_MESSAGE_UPDATE_STATE, OnUpdateState)
END_MESSAGE_MAP()

/**
 *	デフォルトコンストラクタ
 */
CStateStatic::CStateStatic()
	: m_State(0)
{}

void CStateStatic::OnPaint()
{
	CStatic::OnPaint();
}

/**
 *	状態更新イベントのイベントリスナ
 */
LRESULT CStateStatic::OnUpdateState(WPARAM wParam, LPARAM lParam)
{
	CRegexCheck* Src = (CRegexCheck*)lParam;
	if (CRegexCheck::REGEX_CHECK_RESULT_MATCH == Src->GetState()) {
		this->SetWindowText(_T("一致"));
	}
	else {
		this->SetWindowText(_T("不一致"));
	}

	return 0;
}


