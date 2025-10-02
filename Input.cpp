#include "Input.h"

namespace Input
{
	//�L�[�{�[�h�C���v�b�g
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256] = { 0 };
	BYTE prevKeyState[256] = { 0 };
	//�}�E�X�C���v�b�g
	LPDIRECTINPUTDEVICE8 pMouseDevice = nullptr;
	DIMOUSESTATE mouseState; // �}�E�X�̏��
	DIMOUSESTATE prevMouseState; // �O��̃}�E�X�̏��
	XMVECTOR mousePosition;

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);
		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
	}

	void Update()
	{
		memcpy(prevKeyState, keyState, sizeof(keyState)); // �u���b�N�R�s�[
		for (auto i = 0; i < 256; i++)
		{
			prevKeyState[i] = keyState[i];
		}

		pKeyDevice->Acquire();
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);
	}

	bool IsKey(int keyCode)
	{
		if (keyState[keyCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	bool IsKeyUp(int keyCode)
	{
		//���͗����Ă��āA�O��͉����Ă���
		if (!IsKey(keyCode) && (prevKeyState[keyCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	bool IsKeyDown(int keyCode)
	{
		//���͉����ĂāA�O��͉����ĂȂ�
		if (IsKey(keyCode) && !(prevKeyState[keyCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	XMVECTOR GetMousePosition()
	{
		return mousePosition;
	}

	void SetMousePosition(int x, int y)
	{
		//mousePosition = XMVectorSet((float)x, (float)y, 0.0f, 0.0f);
		mousePosition = { (float)x, (float)y, 0.0f, 0.0f };
	}

	void Release()
	{
		SAFE_RELEASE(pDInput);
	}
}