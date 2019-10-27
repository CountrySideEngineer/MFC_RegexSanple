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
 *	�f�t�H���g�R���X�g���N�^
 */
CStateStatic::CStateStatic()
	: m_State(0)
{}

void CStateStatic::OnPaint()
{
	CStatic::OnPaint();
}

/**
 *	��ԍX�V�C�x���g�̃C�x���g���X�i
 */
LRESULT CStateStatic::OnUpdateState(WPARAM wParam, LPARAM lParam)
{
	CRegexCheck* Src = (CRegexCheck*)lParam;
	if (CRegexCheck::REGEX_CHECK_RESULT_MATCH == Src->GetState()) {
		this->SetWindowText(_T("��v"));
	}
	else {
		this->SetWindowText(_T("�s��v"));
	}

	return 0;
}


