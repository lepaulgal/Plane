#ifndef __NET_CONNECT__H__
#define __NET_CONNECT__H__
#include "cocos2d.h"
#include <string>
#include "cocos-ext.h"
#include "Singleton.h"
using namespace std;
USING_NS_CC;
USING_NS_CC_EXT;


class NetConnect : public CCLayer,public::Singleton<NetConnect>
{
public:
	NetConnect(void);
	~NetConnect(void);
	
	virtual bool init();

	void createUI();

	static CCScene* scene();


	void PostMessages(string url,const char* data);
	
	void onHttpComplets(CCHttpClient* client,CCHttpResponse* response);

	CSJson::Value PostDatas;

	int type;

	CREATE_FUNC(NetConnect);

	cocos2d::CCLabelTTF* label;
};

#define  nets NetConnect::instance()
#endif