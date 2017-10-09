
// ChartCtrlDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChartCtrlDemo.h"
#include "ChartCtrlDemoDlg.h"
#include "afxdialogex.h"
#include "../ChartCtrl/ChartAxisLabel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChartCtrlDemoDlg �Ի���



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


// CChartCtrlDemoDlg ��Ϣ�������

BOOL CChartCtrlDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_ChartCtrl.EnableRefresh(false);

	m_ChartCtrl.SetBorderColor(RGB(0, 255, 0));
	CChartDateTimeAxis* pBottomAxis = m_ChartCtrl.CreateDateTimeAxis(CChartCtrl::BottomAxis);
	pBottomAxis->SetAxisColor(RGB(0, 255, 0));
	pBottomAxis->GetGrid()->SetVisible(false);
	
	pBottomAxis->SetTickIncrement(true, CChartDateTimeAxis::tiMonth, 1);
	pBottomAxis->SetTickLabelFormat(false, L"%Y/%m/%d");
	pBottomAxis->SetMinMax(10, 1000);
	pBottomAxis->GetLabel()->SetColor(RGB(0, 255, 0));
	pBottomAxis->GetLabel()->SetText(L"ʱ����");

	CChartStandardAxis* pLeftAxis =	m_ChartCtrl.CreateStandardAxis(CChartCtrl::LeftAxis);
	pLeftAxis->SetTickIncrement(false, 2);
	pLeftAxis->SetMinMax(0, 10);
	pLeftAxis->GetGrid()->SetVisible(false);

	m_ChartCtrl.GetTitle()->SetColor(RGB(0, 255, 0));
	m_ChartCtrl.GetTitle()->AddString(L"����ͼ��ʾ��demo");

	m_ChartCtrl.EnableRefresh(true);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChartCtrlDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CChartCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

