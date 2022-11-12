#include "LoadSprite.h"
#include "SpriteCommon.h"

void LoadSprite::StaticInitialize(SpriteCommon* spriteCommon)
{
	// デバッグテキスト用テクスチャ読み込み
	if (!spriteCommon->LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(NumberNumber, L"Resources/drawNumber.png")) {
		assert(0);
		return;
	}
#pragma region タイトル関連画像
	if (!spriteCommon->LoadTexture(title_None_Number, L"Resources/Title/title_None.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(title_Start_Number, L"Resources/Title/title_Start.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(title_Manual_Number, L"Resources/Title/title_Manual.png")) {
		assert(0);
		return;
	}
#pragma endregion

	// マニュアル画像
	if (!spriteCommon->LoadTexture(manual_Number, L"Resources/manual.png")) {
		assert(0);
		return;
	}

	// エンド画像
	if (!spriteCommon->LoadTexture(end_Number, L"Resources/end.png")) {
		assert(0);
		return;
	}

#pragma region カウントダウン画像
	if (!spriteCommon->LoadTexture(third_Number, L"Resources/CountDown/third.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(second_Number, L"Resources/CountDown/second.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(first_Number, L"Resources/CountDown/first.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(zero_Number, L"Resources/CountDown/zero.png")) {
		assert(0);
		return;
	}
#pragma endregion
}
