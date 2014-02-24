#include "PauseLayer.h"
#include "SimpleAudioEngine.h"
#include <limits>

using namespace CocosDenshion;

CCMenu *menu;
bool PauseLayer::init()
{
    // ccc4�����һ����������͸����
    if (!CCLayerColor::initWithColor(ccc4(0, 0, 0, 100))) {
        return  false;
    }
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // ��������
//    setTouchEnabled(true);
	CCMenuItemImage *play = CCMenuItemImage::create("play.png", "play.png", this, menu_selector(PauseLayer::doResume));
    play->setAnchorPoint(ccp(1, 1));
    play->setTag(10);
	play->setPosition(ccp(winSize.width, winSize.height));
    
    
    menu = CCMenu::create(play, NULL);
    menu->setAnchorPoint(ccp(0, 0));
    addChild(menu, 1, 10);
    menu->setPosition(CCPointZero);
    
    return true;
}


void PauseLayer::doResume(CCObject *pSender)
{
	CCLog("resume!");
	CCDirector::sharedDirector()->resume();
	SimpleAudioEngine::sharedEngine()->resumeAllEffects();
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	removeFromParent();
}
/*
void PauseLayer::registerWithTouchDispatcher()
{
    // NDK���룬�����ͷ #include <limits>
    // ���ȼ�������Ϊ��С����ô����������ȼ�����������Ϊtrue�������ᱻ�����̵�������Ĳ㲻����յ������¼�
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCLayer::registerWithTouchDispatcher();
}

bool PauseLayer::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
  
//    CCRect rect =  menu->getChildByTag(10)->boundingBox();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCRect rect = CCRectMake(winSize.width-50, winSize.height-50, winSize.width, winSize.height);
    if (rect.containsPoint(touch->getLocation())) {
        CCLog("touch play");
        doResume(this);
    }
    return true;
}
void PauseLayer::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    
}
void PauseLayer::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    
}*/