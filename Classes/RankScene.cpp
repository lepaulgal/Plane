#include "RankScene.h"
#include "GameData.h"
#include "GameLayer.h"

RankScene::RankScene(void)
{
}


RankScene::~RankScene(void)
{
}


bool RankScene::init()
{
	bool isRet = false;

	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		createUI();

		isRet = true;
	} while (0);
	return isRet;
}

CCScene* RankScene::scene()
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = RankScene::create();
	scene->addChild(layer);
	return scene;
}

void RankScene::createUI()
{
	size = CCDirector::sharedDirector()->getWinSize();
	//bg
	CCSprite* bg = CCSprite::create("rankBg.png");
	bg->setAnchorPoint(CCPointZero);
	this->addChild(bg);

	CCSprite* top = CCSprite::create("top.png");
	top->setAnchorPoint(ccp(0.5,0));
	top->setPosition(ccp(size.width/2,80));
	bg->addChild(top,1);

	CCMenuItemImage* startItem = CCMenuItemImage::create("game.png","game.png",this,menu_selector(RankScene::startGame));
	CCMenu* menu = CCMenu::create(startItem,NULL);
	menu->setAnchorPoint(CCPointZero);
	menu->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,40));
	bg->addChild(menu,5);


	CCTableView* pTableView = CCTableView::create(this,CCSizeMake(320,330));
	pTableView->setDirection(kCCScrollViewDirectionVertical);
	pTableView->setAnchorPoint(ccp(0.5,0));
	pTableView->setPosition(ccp(12,115));
	pTableView->setDelegate(this);
	pTableView->setVerticalFillOrder(kCCTableViewFillTopDown);
	addChild(pTableView);
	pTableView->reloadData();
}

CCTableViewCell* RankScene::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx)
{
	CCTableViewCell* pCell = table->dequeueCell();

	if (!pCell)
	{
		pCell = new CCTableViewCell();
		pCell->autorelease();
	}

	pCell->removeAllChildrenWithCleanup(true);

	CCSprite* bg = CCSprite::create("itembg.png");
	bg->setAnchorPoint(CCPointZero);
	pCell->addChild(bg);

	CCSprite* icon = CCSprite::create("head.png");
	bg->addChild(icon);
	icon->setAnchorPoint(ccp(0,0));
	icon->setPosition(ccp(5,5));

	CCLabelTTF* user = CCLabelTTF::create("","Font/Connie.ttf",25);
	//GameData::sharedGameData()->Users[idx]["usr"].asString();
	user->setString(GameData::sharedGameData()->Users[idx]["usr"].asCString());
	bg->addChild(user,2);
	user->setColor(ccc3(130,55,30));
	user->setAnchorPoint(CCPointZero);
	user->setPosition(ccp(icon->getPositionX() + 80,icon->getPositionY() + 10));

	CCLabelTTF* score = CCLabelTTF::create("","Font/Connie.ttf",25);
	score->setHorizontalAlignment(kCCTextAlignmentCenter);
	score->setString(GameData::sharedGameData()->Users[idx]["score"].asCString());
	score->setAnchorPoint(CCPointZero);
	score->setColor(ccc3(130,55,30));
	score->setPosition(ccp(user->getPositionX()+ 80,user->getPositionY()));
	bg->addChild(score);

	return pCell;
}

unsigned int RankScene::numberOfCellsInTableView(cocos2d::extension::CCTableView *table)
{
	return GameData::sharedGameData()->getTables();
}

void RankScene::scrollViewDidScroll(CCScrollView* view)
{

}

void RankScene::scrollViewDidZoom(cocos2d::extension::CCScrollView* view)
{

}

CCSize RankScene::cellSizeForTable(cocos2d::extension::CCTableView *table)
{
	return CCSizeMake(300,65);
}

void RankScene::tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell)
{

}





void RankScene::startGame(CCObject* pObject)
{
	CCDirector::sharedDirector()->replaceScene(GameLayer::scene());
}
