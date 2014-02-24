#ifndef __GAME__DATA__H__
#define __GAME__DATA__H__

#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
USING_NS_CC_EXT;

class GameData : public CCObject
{
public:
	GameData(void);
	~GameData(void);

	static GameData* sharedGameData();

	CC_SYNTHESIZE(int,tables,Tables);

	void purge();

	void flush();

	CSJson::Value Users;

};




#endif

