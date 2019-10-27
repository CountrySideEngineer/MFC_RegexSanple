#include "pch.h"
#include "CRegexCheck.h"
#include <regex>

/**
 *	�f�t�H���g�R���X�g���N�^
 */
CRegexCheck::CRegexCheck()
	: m_MatchState(REGEX_CHECK_RESULT_NONE)
	, m_EventId(0)
{
	this->m_EventListeners.RemoveAll();
}

/**
 *	�m�F�����{����B
 *
 *	@param	Target	�m�F�Ώۂ̕�����
 *	@param	RegExp	���K�\��
 */
void CRegexCheck::Run(CString& Target, CString& RegExp)
{
	std::string TargetString = CT2A(Target);
	std::string RegExpString = CT2A(RegExp);

	std::regex RegExpPattern(RegExpString);
	std::cmatch Match;

	int TargetLen = Target.GetLength();
	char* TargetEnd = (char*)(TargetString.c_str() + TargetLen);
	BOOL IsMatch = std::regex_match(TargetString.c_str(), RegExpPattern);
	if (TRUE == IsMatch) {
		this->m_MatchState = REGEX_CHECK_RESULT_MATCH;
	}
	else {
		this->m_MatchState = REGEX_CHECK_RESULT_UNMATCH;
	}
	TRACE(_T("%s\n"), TRUE == IsMatch ? _T("��v") : _T("�s��v"));

	this->NotifyDataChanged();
}

/**
 *	�f�[�^�ύX��ʒm����B
 */
void CRegexCheck::NotifyDataChanged()
{
	for (INT_PTR Index = 0; Index < this->m_EventListeners.GetCount(); Index++) {
		CWnd* EventListener = this->m_EventListeners.GetAt(Index);
		if (NULL != EventListener) {
			EventListener->SendMessage(this->m_EventId, 0, (LPARAM)this);
		}
	}
}