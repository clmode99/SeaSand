//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  タイトル処理のソースファイル
//!
//! @date   2016/11/04		
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameTitle.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Title::Title()
{
	// タイトルBGM再生
	ADX2Le::Play(CRI_CUESHEET_0_TITLEBGM, 1.0f, true);
}

//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Title::~Title()
{
	ADX2Le::Stop();
}

//----------------------------------------------------------------------
//! @brief タイトル処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Title::Update()
{
	if (g_init == 0)
	{
		g_init = 1;
		g_TimeCnt = 0;
	}

	g_TimeCnt++;
	//スペースキー点滅用
	if (g_TimeCnt > 120)
	{
		g_TimeCnt = 0;
	}

	if (g_keyTracker->pressed.Space)
	{
		g_NextScene = PLAY;
	}
}

//----------------------------------------------------------------------
//! @brief タイトル描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Title::Render()
{
	RECT rect;			// 絵の左上の座標と右下の座標編集用
	wchar_t buf[256];	//文字列編集用
	rect = { 0, 160, 256, 224 };
	g_spriteBatch->Draw(g_TitleImage->m_pTexture, Vector2(0, 192),
		&rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(2.5, 2.5));
	rect = { 0, 224, 150, 256 };
	if (g_TimeCnt < 60)
	{
		g_spriteBatch->Draw(g_TitleImage->m_pTexture, Vector2(250, 380),
			&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);
	}
	swprintf_s(buf, 256, L"TITLE");
	g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(100, 0));
}