#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>

struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX	matWVP; //would\view\projection�̍s��
};

class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�萔�o�b�t�@
public:
	Quad();
	~Quad();
	void Initialize();
	void Draw();
	void Release();
};

