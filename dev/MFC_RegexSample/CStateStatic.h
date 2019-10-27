#pragma once
#include <afxwin.h>
class CStateStatic :
	public CStatic
{
	DECLARE_DYNAMIC(CStateStatic)

public:
	CStateStatic();
	virtual ~CStateStatic() {}

protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg	void	OnPaint();
	afx_msg LRESULT	OnUpdateState(WPARAM wParam, LPARAM lParam);

protected:
	INT_PTR	m_State;

};

