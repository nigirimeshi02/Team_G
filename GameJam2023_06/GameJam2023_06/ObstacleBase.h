#pragma once
#include "Collider/SphereCollider.h"
#include "common.h"
#define D_OBSTACLE_KILL_Y (D_SCREEN_HEIGHT - 70 - 50)	//画面サイズ - UIサイズ - マージン

class ObstacleBase :
	public SphereCollider
{
	/*
	* ColliderBase:
	*	E_Collider colliderType;
	*	Location location;		//中心座標
	* SphereCollider:
	* 	float radius;			//半径
	*/
public:
	ObstacleBase();
	~ObstacleBase();
	ObstacleBase(Location location, float radius = 5, float speed = 2, 
		int score = 100, int max_frame = 0);

protected:
	float speed;		//移動速度
	bool isBroken;		//壊れたかどうか
	bool isShow;		//映す映さない
	int score;			//スコア

	int frameCount;		//アニメーション用カウンタ
	const int MAX_FRAME;//アニメーション完遂時のフレーム数

public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;

	bool GetIsBroken()const { return isBroken; }
	void ToggleIsBroken() { isBroken = !isBroken; }
	void SetFrameCount() { frameCount = MAX_FRAME; }

	virtual int GetScore() const { return score; }
	bool GetIsScreenOut()const { return (location.y > D_OBSTACLE_KILL_Y); }
	bool IsAbleDelete() const
	{
		return (isBroken == true) && (frameCount <= 0);
	}
};

