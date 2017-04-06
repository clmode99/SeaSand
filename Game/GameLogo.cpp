//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLogo.cpp
//!
//! @brief  ���S�����̃\�[�X�t�@�C��
//!
//! @date   2016/11/04		
//!
//! @author �R�c�B�^
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameLogo.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief ���S�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Logo::Logo()
{

}

//----------------------------------------------------------------------
//! @brief ���S�f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Logo::~Logo()
{

}

//----------------------------------------------------------------------
//! @brief ���S����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Logo::Update()
{
	if (g_init == 0)
	{
		g_init = 1;
	}

	if (g_mouse.leftButton)
	{
		g_NextScene = TITLE;
	}
}

//----------------------------------------------------------------------
//! @brief ���S�`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Logo::Render()
{
	wchar_t buf[256];

	swprintf_s(buf, 256, L"LOGO");
	g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(100, 0));
}
