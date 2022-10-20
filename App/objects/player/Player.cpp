#include "Player.h"
#include "Input.h"

Player* Player::Create()
{
	// �C���X�^���X����
	Player* instance = new Player();
	// �C���X�^���X������
	instance->Initialize();

	return instance;
}

Player::~Player()
{
	// �J�������
	delete camera;
	// ���f�����
	delete model_Bike;
	// �I�u�W�F�N�g���
	delete obj_Bike;
}

void Player::Initialize()
{
	// �J�����������Z�b�g
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);

	// ���f���ǂݍ���
	model_Bike = Model::LoadFromOBJ("bike", true);
	// �I�u�W�F�N�g����
	obj_Bike = Object3d::Create(model_Bike);
	// �������W
	pos = { 0.0f, 0.0f, 0.0f };
	// ������]
	rot = { 0.0f, 0.0f, 0.0f };
	// �X�P�[��
	obj_Bike->SetScale({ 0.5f, 0.5f, 0.5f });
	// �����x
	speed = { 0.1f, 0.0f, 0.1f };

	// ���f���ǂݍ���
	model_Dome = Model::LoadFromOBJ("skydome");
	// �I�u�W�F�N�g����
	obj_Dome = Object3d::Create(model_Dome);
}

void Player::BesideMove()
{
	// ���ړ�
	if (Input::GetInstacne()->PushKey(DIK_A))
	{
		pos.x -= speed.x;
	}

	// �E�ړ�
	if (Input::GetInstacne()->PushKey(DIK_D))
	{
		pos.x += speed.x;
	}
}

float Player::Fluctuation()
{
	// ����
	if (Input::GetInstacne()->PushKey(DIK_W) && speed.z <= 1.5f)
	{
		speed.z += 0.01f;
	}

	// �K��l����Ȃ�
	if (speed.z >= 0.12f)
	{
		// �Đ����s
		if (Input::GetInstacne()->AwayKey(DIK_W))
		{
			speed.z -= 0.005f;
		}
		// �u���[�L
		if (Input::GetInstacne()->PushKey(DIK_S))
		{
			speed.z -= 0.01f;
		}
	}

	return speed.z;
}

void Player::AutoSprint()
{
	// ���W�ɑ��x�����Z
	pos.z += Fluctuation();
	// �X�V�������W���Z�b�g
	obj_Bike->SetPosition(pos);
}

void Player::DebugMove()
{
	if (Input::GetInstacne()->PushMoveKey())
	{
		if (Input::GetInstacne()->PushKey(DIK_W))
		{
			pos.z += 0.1f;
		}

		if (Input::GetInstacne()->PushKey(DIK_A))
		{
			pos.x -= 0.1f;
		}

		if (Input::GetInstacne()->PushKey(DIK_S))
		{
			pos.z -= 0.1f;
		}

		if (Input::GetInstacne()->PushKey(DIK_D))
		{
			pos.x += 0.1f;
		}

		obj_Bike->SetPosition(pos);
	}
}

void Player::Update()
{
	// ���ړ�
	BesideMove();
	// �����ړ�
	AutoSprint();
	//DebugMove();
	// �J�����Ǐ]
	camera->SetEye({pos.x, pos.y + 1.7f, pos.z - 0.3f});
	camera->SetTarget({pos.x, pos.y + 1.7f, pos.z + 1.0f});

	// �J�����X�V
	camera->Update();
	// �o�C�N�X�V
	obj_Bike->Update();
	// �X�J�C�h�[���X�V
	obj_Dome->SetPosition({ pos.x, pos.y, pos.z + 20.0f });
	obj_Dome->Update();
}

void Player::Draw()
{
	// �o�C�N�X�V
	obj_Bike->Draw();
	// �X�J�C�h�[���X�V
	obj_Dome->Draw();
}