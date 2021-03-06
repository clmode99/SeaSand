//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  プレイシーンのヘッダファイル
//!
//! @date   2016/12/12
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once
#include "GameBase.h"
#include "Object\Player.h"

class Food;
class MessagePlate;

//定数
const int FOOD_NUM = 4;		//画面内に1度に出てくる食材の数
const int BREAD_NUM = 5;	//パンの残り枚数

//クラス
class Play:public GameBase
{
private:
	// 背景画像
	Texture* m_backplay_image;	// 背景
	Player** m_bread;			// 食パン
	Food* m_food[FOOD_NUM];

	MessagePlate* m_plate;	//メッセージ板
	int m_bread_num;		//パンの残り枚数
	int m_time;				//時間		
	bool m_wave_clear;		//1WAVEが終わったかどうかの判定
	int m_time_ms;				// 時間(ミリ秒)

	void InitBread();			// パン初期化
	void ReleaseBread();		// パン開放
	void FoodAwake();			// 食材の出現
	void UpdateWave();			// WAVEの更新処理

public:
	Play();
	~Play();
	void Update();
	void Render();

};
