#ifndef __MoonWarriorsx__Ship__
#define __MoonWarriorsx__Ship__

#include "cocos2d.h"
#include "UnitSprite.h"
USING_NS_CC;

class Ship : public UnitSprite{
private:
    // �ٶ�
    int m_speed;
    
    // �ӵ��ٶ�
    int m_bulletSpeed;
    
    // ����ֵ
    int m_HP;
    
    // �ӵ�����
    int m_bulletTypeValue;
    
    // �ӵ�����
    int m_bulletPowerValue;
    
    // �Ƿ���Ͷ��ը��
    bool m_throwBombing;
    
    // �Ƿ�ɱ�����
    bool m_canBeAttack;
    
    bool m_isThrowBomb;
    int m_zOder;
    
    // ����ӵ�����
    int m_maxBulletPowerValue;
    
    // ���ֵĳ�ʼλ��
    CCPoint m_appearPosition;
    int m_hurtColorLife;
    bool m_active;
    
public:
    Ship();
    ~Ship();
    
    // ������ʹ��
    void makeAttack(CCNode *pSender);
    
    // ����
    virtual void update(float dt);
    
    // ���
    void shoot(float dt);
    
    // ��ʼ��
    virtual bool init();
    
    // ������������
    virtual void hurt();
    
    // ���ٷɴ�
    virtual void destroy();
    
    // ��ȡ����״̬
    virtual bool isActive();
    
    // ��ײ����
    virtual CCRect collideRect();
    int getZoder();
    
    // ������
    CREATE_FUNC(Ship);
};

#endif /* defined(__MoonWarriorsx__Ship__) */