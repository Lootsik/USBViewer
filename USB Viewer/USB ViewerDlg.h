
// USB ViewerDlg.h : header file
//
#pragma once
#include "USBInfo.h"
#include "afxcmn.h"
#include "afxwin.h"

#define WM_ShellNote (WM_APP + 1)
#define WM_ShowWindow (WM_ShellNote + 1)
#define ID_TrayIcon 1123

// CUSBViewerDlg dialog
class CUSBViewerDlg : public CDialog
{
// Construction
public:
	CUSBViewerDlg(CWnd* pParent = NULL);	// standard constructor
	~CUSBViewerDlg();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USBVIEWER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	//Tray icon event handler
	LRESULT  OnTrayEvent( WPARAM wParam , LPARAM lParam );
	//Notification appears on the screen after Timeout ms
	void SendNotification(const TCHAR* Title,const  TCHAR* Text, UINT Timeout);
	
	int OnDeviceChange(UINT nEventType,DWORD_PTR dwData);
	void SilentUpdateDevices();
	
	//update ListBox with informatio about devices
	void UpdateDeviceView();
	//show error message and close program
	void СrashShutdown();


	BOOL CreateTrayIcon();
	void ShowMainWindow();
	void FoldUpToTray();

	LRESULT DestroyTrayIncon(WPARAM wParam, LPARAM lParam);

	NOTIFYICONDATA nid;
	BOOL isTrayIconSet = false;
	//list of usb devices
	USB::DeviceInfoSet USBDevices;
	CListBox ListBoxCtrl;
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuUpdate();
	afx_msg void OnMenuExit();
	afx_msg void OnAboutInfo();
	afx_msg void OnLbnSelchangeList();
	afx_msg void OnBnClickedChangeState();
};
