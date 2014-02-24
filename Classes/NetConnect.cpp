#include "NetConnect.h"
#include "GameData.h"
#include "RankScene.h"
#include "HelloWorldScene.h"

DECLARE_SINGLETON_MEMBER(NetConnect);


NetConnect::NetConnect(void): type(0)
{

}

NetConnect::~NetConnect(void)
{
	
}

bool NetConnect::init()
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


void NetConnect::PostMessages(string url,const char* data)
{
	CCHttpRequest* request = new CCHttpRequest();

	request->setUrl(url.c_str());

	request->setRequestType(CCHttpRequest::kHttpPost);
	
	request->setResponseCallback(this,httpresponse_selector(NetConnect::onHttpComplets));

	request->setRequestData(data,strlen(data));

	CCHttpClient::getInstance()->send(request);

	request->release();
}

void NetConnect::onHttpComplets(CCHttpClient* client,CCHttpResponse* response)
{
	if (!response->isSucceed())//failed
	{
		return;
	}
	else
	{
		std::vector<char> *buffer = response->getResponseData();
		string recieve;
		for (int i = 0;i<buffer->size();i++)
		{
			recieve += (*buffer)[i];
		}
		size_t begin= recieve.find("<body>")+6;//这里简单处理，获取<body>标签内数据，即是响应内容  
		size_t end= recieve.find("</body>");  
		string result(recieve,begin,end-begin);  

		CSJson::Reader reader;
		reader.parse(result,PostDatas);

		if (type == 1)
		{
			GameData::sharedGameData()->setTables(PostDatas.size());
			GameData::sharedGameData()->flush();
			GameData::sharedGameData()->Users = PostDatas;
			
			//char name[50];
			//sprintf(name,"%d",GameData::sharedGameData()->getTables());
			//label->setString(name);

			CCDirector::sharedDirector()->replaceScene(RankScene::scene());
		}
	}
}


CCScene* NetConnect::scene()
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = NetConnect::create();
	scene->addChild(layer);
	return scene;
}

void NetConnect::createUI()
{
	CCSprite* bg  = CCSprite::create("loading.png");
	bg->setAnchorPoint(CCPointZero);
	bg->setPosition(CCPointZero);
	this->addChild(bg);

	
}