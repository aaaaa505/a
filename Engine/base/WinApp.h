#pragma once
#include<windows.h>

//WindowAPI
class WinApp
{
public://�ÓI�����o�֐�
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://�����o�֐�
	//������
	void Initialize();

	//�X�V
	void Updata();

	//getter
	HWND GetHwnd() { return hwnd; }
	HINSTANCE GetInstance() { return w.hInstance; }

	//�I��
	void Finalize();

	//���b�Z�[�W����
	bool ProcessMessage();


private://�����o�ϐ�
	//�E�B���h�E�n���h��
	HWND hwnd = nullptr;

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};


public://�萔
	//�E�B���h�E����
	static const int window_width = 1280;

	//�E�B���h�E�c��
	static const int window_height = 720;

};
