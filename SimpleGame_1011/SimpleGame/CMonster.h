#pragma once

class CObj;
class CMonster : public CObj
{

public:
	void Initialize();
	void Update(float);
	void Render();
	void Release();

public:
	CMonster();
	~CMonster();
};