
// ChartCtrlDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CChartCtrlDemoApp: 
// �йش����ʵ�֣������ ChartCtrlDemo.cpp
//

class CChartCtrlDemoApp : public CWinApp
{
public:
	CChartCtrlDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CChartCtrlDemoApp theApp;