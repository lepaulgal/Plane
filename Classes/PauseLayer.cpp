#include "PauseLayer.h"
#include "SimpleAudioEngine.h"
#include <limits>

using namespace CocosDenshion;

CCMenu *menu;
bool PauseLayer::init()
{
    // ccc4的最后一个参数才是透明度
    if (!CCLayerColor::initWithColor(ccc4(0, 0, 0, 100))) {
        return  false;
    }
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // 开启触控
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
    // NDK编译，需加上头 #include <limits>
    // 优先级数字设为最小，那么具有最高优先级，最后参数设为true，则触摸会被这里吞掉，下面的层不会接收到触摸事件
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