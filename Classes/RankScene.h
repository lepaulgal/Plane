#ifndef __RANK__SCENE__H__
#define __RANK__SCENE__H__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class RankScene : public CCLayer , public CCTableViewDataSource, public CCTableViewDelegate
{
public:
	RankScene(void);
	~RankScene(void);

	CCSize size;

	virtual bool init();

	static CCScene* scene();

	virtual void scrollViewDidScroll(CCScrollView* view);
	virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view);
	//处理触摸事件
	virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
	//每一项的宽度和高度
	virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
	//生成列表每一项的内容
	virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
	//一共多少项
	virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);


	CREATE_FUNC(RankScene);

	void createUI();

	void startGame(CCObject* pObject);
};


#endif

