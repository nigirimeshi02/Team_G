#pragma once
class Result
{
public:
	Result(int score, int value);
	~Result();

	void Update();
	void Draw();

private:
	int r_score;
	int r_value;

	int backImg;
	int enemyImg;
};
