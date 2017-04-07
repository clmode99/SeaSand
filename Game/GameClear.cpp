//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.cpp
//!
//! @brief  ゲームクリア処理のソースファイル
//!
//! @date   2016/11/04		
//!
//! @author 山田唯真	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameClear.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief ゲームクリアコンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Clear::Clear()
{
	// 画像読み込み
	m_back_image = new Texture(L"Resources\\Images\\ResultBackImage.png");
	m_message = new Texture(L"Resources\\Images\\ResultMessage_Result.png");
}

//----------------------------------------------------------------------
//! @brief ゲームクリアデストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Clear::~Clear()
{
	auto Delete = [](Texture** t)
	{
		if (t)
		{
			delete (*t);
			*t = nullptr;
		}
	};
		
	Delete(&m_back_image);
	Delete(&m_message);

}

//----------------------------------------------------------------------
//! @brief ゲームクリア処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Clear::Update()
{
	if (g_init == 0)
	{
		g_init = 1;
	}

	// タイトルに移行
	if (g_keyTracker->pressed.Space)
	{ 
		g_NextScene = TITLE;
	}

}

//----------------------------------------------------------------------
//! @brief ゲームクリア描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Clear::Render()
{
	wchar_t buf[256];
	RECT rect;
	swprintf_s(buf, 256, L"CLEAR");

	g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(100, 0));

	DrawRectTexture(0.0f, 0.0f, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, m_back_image);
	DrawRectTexture(0.0f, 0.0f, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, m_message);
}
