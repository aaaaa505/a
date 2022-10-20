#pragma once
#include "BaseScene.h"
#include "Sprite.h"
#include "LoadSprite.h"
#include "Camera.h"

class EndScene : public BaseScene
{
public:

	/// <summary>
	/// ������
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// �I��
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// �X�V
	/// </summary>
	void Updata() override;

	/// <summary>
	/// �`��
	/// </summary>
	void Draw() override;

private:// �����o�ϐ�
	Sprite* sprite = nullptr;
};
