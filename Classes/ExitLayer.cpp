#include "ExitLayer.h"
#include "resource.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool ExitLayer::init()
{
	bool bRet = false;
	if(!CCLayer::init())
	{
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	do
	{
		CCSprite *bg = CCSprite::create(s_loading);
		bg->setAnchorPoint(CCPointZero);
		bg->setPosition(CCPointZero);
		addChild(bg);

		//1. go back
		CCLabelBMFont *backLb = CCLabelBMFont::create("Go Back", s_font);
		CCMenuItemLabel *goBack = CCMenuItemLabel::create(backLb, this, menu_selector(ExitLayer::goBack));
		goBack->setScale(0.6);
		// director��ͣ����������С�
/*		CCActionInterval *fadeIn = CCFadeTo::create(1, 80);
		CCActionInterval *fadeOut = CCFadeTo::create(1, 255);
		CCEaseSineInOut *ease1 = CCEaseSineInOut::create(fadeIn);
		CCEaseSineInOut *ease2 = CCEaseSineInOut::create(fadeOut);
		CCActionInterval *seq = CCSequence::create(ease1, ease2, NULL);
		goBack->runAction(CCRepeatForever::create(seq));
*/
		//2. quit
		CCLabelBMFont *quitLb = CCLabelBMFont::create("Quit", s_font);
		CCMenuItemLabel *quit = CCMenuItemLabel::create(quitLb, this, menu_selector(ExitLayer::exitGame));
		quit->setScale(0.6);
//		quit->runAction(CCRepeatForever::create((CCActionInterval*)seq->copy()));

		CCMenu *menu = CCMenu::create(quit, goBack, NULL);
		menu->alignItemsVerticallyWithPadding(80);
		menu->setPosition(winSize.width / 2, winSize.height / 2);
		addChild(menu);


		bRet = true;
	}while(0);

	return bRet;
}

void ExitLayer::goBack(CCObject* pSender)
{


	CCDirector::sharedDirector()->resume();
	SimpleAudioEngine::sharedEngine()->resumeAllEffects();
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	
//	CCActionInterval* del = CCDelayTime::create(0.5);
//	this->runAction(del);

    CCDirector::sharedDirector()->popScene();
//	CCDirector::sharedDirector()->getRunningScene()->resumeSchedulerAndActions();
}

void ExitLayer::exitGame(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}