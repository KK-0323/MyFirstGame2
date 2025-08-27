#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>
#include "Transform.h"

using namespace DirectX;

struct CONSTANT_BUFFER
{
	XMMATRIX matWVP; //would\view\projection�̍s��
	XMMATRIX matNormal;//�@���ϊ��p�̍s��
	XMMATRIX matWorld; //���[���h�s��
};

//���_���
struct VERTEX
{
	XMFLOAT4 pos;	//�ʒu
	XMFLOAT2 uv;	//UV���W
	XMFLOAT4 normal;//�@���x�N�g��
};

//�O���錾
class Texture;

class Quad
{
public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(Transform& transform);
	void Release();
protected:
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�萔�o�b�t�@
	Texture* pTexture_;	//�e�N�X�`��
};

