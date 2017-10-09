
// ChartCtrlDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ChartCtrlDemo.h"
#include "ChartCtrlDemoDlg.h"
#include "afxdialogex.h"
#include "../ChartCtrl/ChartAxisLabel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChartCtrlDemoDlg 对话框



CChartCtrlDemoDlg::CChartCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHARTCTRLDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChartCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHARTCTRL1, m_ChartCtrl);
}

BEGIN_MESSAGE_MAP(CChartCtrlDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CChartCtrlDemoDlg 消息处理程序

BOOL CChartCtrlDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_ChartCtrl.EnableRefresh(false);

	m_ChartCtrl.SetBorderColor(RGB(0, 255, 0));
	CChartDateTimeAxis* pBottomAxis = m_ChartCtrl.CreateDateTimeAxis(CChartCtrl::BottomAxis);
	pBottomAxis->SetAxisColor(RGB(0, 255, 0));
	pBottomAxis->GetGrid()->SetVisible(false);
	
	pBottomAxis->SetTickIncrement(true, CChartDateTimeAxis::tiMonth, 1);
	pBottomAxis->SetTickLabelFormat(false, L"%Y/%m/%d");
	pBottomAxis->SetMinMax(10, 1000);
	pBottomAxis->GetLabel()->SetColor(RGB(0, 255, 0));
	pBottomAxis->GetLabel()->SetText(L"时间轴");

	CChartStandardAxis* pLeftAxis =	m_ChartCtrl.CreateStandardAxis(CChartCtrl::LeftAxis);
	pLeftAxis->SetTickIncrement(false, 2);
	pLeftAxis->SetMinMax(0, 10);
	pLeftAxis->GetGrid()->SetVisible(false);

	m_ChartCtrl.GetTitle()->SetColor(RGB(0, 255, 0));
	m_ChartCtrl.GetTitle()->AddString(L"快速图标示例demo");

	m_ChartCtrl.EnableRefresh(true);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChartCtrlDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChartCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

