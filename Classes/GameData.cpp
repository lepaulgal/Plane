#include "GameData.h"

static GameData* _data = NULL;
GameData::GameData(void)
{
}


GameData::~GameData(void)
{
	CC_SAFE_RELEASE(_data);
}

GameData* GameData::sharedGameData()
{
	if (_data == NULL)
	{
		_data = new GameData();
	}

	return _data;
}

void GameData::purge()
{

}

void GameData::flush()
{
	CCUserDefault::sharedUserDefault()->setIntegerForKey("tabel_num",getTables());
	CCUserDefault::sharedUserDefault()->flush();
	CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
}


