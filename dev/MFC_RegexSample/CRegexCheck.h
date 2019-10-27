#pragma once

class CRegexCheck
{
public:
	enum {
		REGEX_CHECK_RESULT_NONE = 0,
		REGEX_CHECK_RESULT_MATCH,
		REGEX_CHECK_RESULT_UNMATCH,
		REGEX_CHECK_RESULT_MAX,
	};

public:
	CRegexCheck();
	virtual ~CRegexCheck() {}


	void Run(CString& Target, CString& RegExp);
	
	virtual	void SetEventId(INT_PTR EventId) { this->m_EventId = EventId; }
	virtual void AddEventListener(CWnd* EventListener) { this->m_EventListeners.Add(EventListener); }

	virtual INT_PTR GetState() const { return this->m_MatchState; }

protected:
	virtual void NotifyDataChanged();

protected:
	INT_PTR	m_MatchState;
	INT_PTR	m_EventId;
	CArray<CWnd*>	m_EventListeners;
};

