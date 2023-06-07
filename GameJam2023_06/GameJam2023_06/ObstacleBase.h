#pragma once
#include "Collider/SphereCollider.h"
#include "common.h"
#define D_OBSTACLE_KILL_Y (D_SCREEN_HEIGHT - 70 - 50)	//��ʃT�C�Y - UI�T�C�Y - �}�[�W��

class ObstacleBase :
	public SphereCollider
{
	/*
	* ColliderBase:
	*	E_Collider colliderType;
	*	Location location;		//���S���W
	* SphereCollider:
	* 	float radius;			//���a
	*/
public:
	ObstacleBase();
	~ObstacleBase();
	ObstacleBase(Location location, float radius, float speed, int score);

protected:
	float speed;		//�ړ����x
	bool isBroken;		//��ꂽ���ǂ���
	bool isShow;		//�f���f���Ȃ�
	int score;			//�X�R�A

public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;

	bool GetIsBroken()const { return isBroken; }
	void ToggleIsBroken() { isBroken = !isBroken; }
	bool GetIsShow()const { return isShow; }
	void ToggleIsShow() { isShow = !isShow; }
	int GetScore() const { return score; }
	bool GetIsScreenOut()const { return (location.y > D_OBSTACLE_KILL_Y); }
};

