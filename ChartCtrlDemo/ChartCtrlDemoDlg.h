
// ChartCtrlDemoDlg.h : ͷ�ļ�
//

#pragma once

#include "../ChartCtrl/ChartCtrl.h"
#include "F:\Project\ChartCtrl\ChartCtrlDemo\ChartCtrl\ChartCtrl.h"


// CChartCtrlDemoDlg �Ի���
class CChartCtrlDemoDlg : public CDialogEx
{
// ����
public:
	CChartCtrlDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHARTCTRLDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CChartCtrl m_ChartCtrl;
};
