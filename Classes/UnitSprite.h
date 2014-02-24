#ifndef __UNIT__SPRITE__H__
#define __UNIT__SPRITE__H__

#include "cocos2d.h"
USING_NS_CC;

class CostomeKeyPadDelegae : public CCKeypadDelegate , public CCNode{

public:
	virtual void keyBackClicked();
};

class UnitSprite : public CCSprite{

public:
	UnitSprite();
	~UnitSprite();
	virtual void destroy() = 0;
	virtual void hurt() = 0 ;
	virtual CCRect collideRect() = 0;
	virtual bool isActive() = 0;
};


#endif


