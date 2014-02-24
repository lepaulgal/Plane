#ifndef __WELCOME__SCENE__H__
#define __WELCOME__SCENE__H__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;

class WelcomeScene : public CCLayer
{
public:
	WelcomeScene(void);
	~WelcomeScene(void);
	
	virtual bool init();

	static CCScene* scene();

	void createUi(); 

	void gameStart(CCObject* pObject);

	CCSize size;
	CREATE_FUNC(WelcomeScene);

private:
	CCEditBox* userTTF;
	CCEditBox* pwdTTF;

	cocos2d::CCLabelTTF* ttf;
	void onHttpComplete(CCHttpClient* client,CCHttpResponse* response);
};

#endif



