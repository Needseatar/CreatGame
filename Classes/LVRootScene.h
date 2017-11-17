//
//  LVRootSene.h
//  CreatGame
//
//  Created by LV on 2017/11/16.
//
//

#ifndef __LVROOTSCENE_SCENE_H__
#define __LVROOTSCENE_SCENE_H__

#include "cocos2d.h"

class LVRootScene : public cocos2d::Scene
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    virtual void update(float dt);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(LVRootScene);
    
    static LVRootScene * myCreate()
    {
        LVRootScene *pRet = new(std::nothrow) LVRootScene();
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
};

#endif /* LVRootSene_h */
