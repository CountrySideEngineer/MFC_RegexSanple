#include "pch.h"
#include "CRegexCheck.h"
#include <regex>

/**
 *	デフォルトコンストラクタ
 */
CRegexCheck::CRegexCheck()
	: m_MatchState(REGEX_CHECK_RESULT_NONE)
	, m_EventId(0)
{
	this->m_EventListeners.RemoveAll();
}

/**
 *	確認を実施する。
 *
 *	@param	Target	確認対象の文字列
 *	@param	RegExp	正規表現
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
	TRACE(_T("%s\n"), TRUE == IsMatch ? _T("一致") : _T("不一致"));

	this->NotifyDataChanged();
}

/**
 *	データ変更を通知する。
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