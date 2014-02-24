#include "WelcomeScene.h"
#include "RankScene.h"
#include <string>
#include "NetConnect.h"
#include "GameData.h"

using namespace std;


WelcomeScene::WelcomeScene(void)
{
	
}


WelcomeScene::~WelcomeScene(void)
{
}

bool WelcomeScene::init()
{
	bool isRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		size = CCDirector::sharedDirector()->getWinSize();
		createUi();
		isRet = true;
	} while (0);

	return isRet;
}

CCScene* WelcomeScene::scene()
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = WelcomeScene::create();
	scene->addChild(layer);
	return scene;
}

void WelcomeScene::createUi()
{
	CCSprite* bg = CCSprite::create("loading.png");
	bg->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(bg);

	CCSprite* logo = CCSprite::create("logo.png");
	logo->setAnchorPoint(ccp(0.5,0));
	logo->setPosition(ccp(size.width/2,size.height/2 + 80));
	bg->addChild(logo);

	//text
	CCScale9Sprite* spr = CCScale9Sprite::create("edit.png");
	userTTF = CCEditBox::create(CCSizeMake(200,50),spr);
	userTTF->setPlaceHolder("username");
	userTTF->setPosition(ccp(logo->getPositionX(),logo->getPositionY() - 50));
	userTTF->setInputFlag(kEditBoxInputFlagSensitive);
	userTTF->setReturnType(kKeyboardReturnTypeDone);
	bg->addChild(userTTF);
	//pwd
	CCScale9Sprite* pwdSpr = CCScale9Sprite::create("edit.png");
	pwdTTF = CCEditBox::create(CCSizeMake(200,50),pwdSpr);
	pwdTTF->setPlaceHolder("pwd");
	pwdTTF->setInputFlag(kEditBoxInputFlagPassword);
	pwdTTF->setReturnType(kKeyboardReturnTypeGo);
	
	pwdTTF->setPosition(ccp(userTTF->getPositionX(),userTTF->getPositionY() - 80));
	bg->addChild(pwdTTF);

	CCMenuItemImage* start = CCMenuItemImage::create("game.png","game.png",this,menu_selector(WelcomeScene::gameStart));
	CCMenu* menu = CCMenu::create(start,NULL);
	bg->addChild(menu,10);
	menu->setPosition(ccp(pwdTTF->getPositionX(),pwdTTF->getPositionY() - 100));

	ttf= CCLabelTTF::create();
	ttf->setPosition(ccp(pwdTTF->getPositionX(),pwdTTF->getPositionY()-50));
	bg->addChild(ttf);
}

void WelcomeScene::gameStart(CCObject* pObject)
{
	std::cout<<"startgame"<<std::endl;
	CCHttpRequest* request = new CCHttpRequest();
	string str = "www.nkami.com/game/index.php";

	string name = userTTF->getText();
	string pwd = pwdTTF->getText();

	string struser = "username=";
	string strpwd = "&password=";

	name = struser + name + strpwd + pwd;

	request->setUrl(str.c_str());
	request->setRequestType(CCHttpRequest::kHttpPost);
	request->setResponseCallback(this,httpresponse_selector(WelcomeScene::onHttpComplete));

	const char* postData = name.c_str();
	request->setRequestData(postData,strlen(postData));
	request->setTag("postname");
	CCHttpClient::getInstance()->send(request);
	request->release();
}

void WelcomeScene::onHttpComplete(CCHttpClient* client,CCHttpResponse* response)
{
	if (!response->isSucceed())//failed
	{
		ttf->setString("failed");
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

		ttf->setString(result.c_str());

		CSJson::Value TheData;
		CSJson::Reader reader;
		reader.parse(result,TheData);

		ttf->setString(TheData["login"].asCString());
		//int canLogin;
		//sscanf(result.c_str(),"%d",&canLogin);

		//if (canLogin)
		//{
			//CCDirector::sharedDirector()->replaceScene(RankScene::scene());
		//}
	
		if (TheData["login"].asString() == "success")
		{
			CCScene* scene = NetConnect::scene();
			CCDirector::sharedDirector()->replaceScene(scene);
			nets->type = 1;
			const char * data = "names";
			nets->PostMessages("www.nkami.com/game/len.php",data);

		}
		

	}
}




