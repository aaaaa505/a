#include "SceneManager.h"

#include <cassert>

SceneManager::~SceneManager()
{
	// �Ō�̃V�[���̏I���Ɖ��
	nowScene->Finalize();
	delete nowScene;
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;

	return &instance;
}

void SceneManager::Updata()
{
	// �V�[���؂�ւ�������Ȃ�
	if (nextScene)
	{
		// ���V�[���̏I��
		if (nowScene)
		{
			nowScene->Finalize();
			delete nowScene;
		}

		// �V�[���؂�ւ�
		nowScene = nextScene;
		nextScene = nullptr;

		// ���̃V�[���̏�����
		nowScene->Initialize();
	}

	// ���݂̃V�[���X�V
	nowScene->Updata();
}

void SceneManager::Draw()
{
	// ���݂̃V�[���`��
	nowScene->Draw();
}

void SceneManager::ChangeScene(const std::string& sceneName)
{
	assert(sceneFactory);
	assert(nextScene == nullptr);

	// ���V�[�����Z�b�g
	nextScene = sceneFactory->CreateScene(sceneName);
}