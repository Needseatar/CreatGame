//
//  LVRootScene.cpp
//  CreatGame
//
//  Created by LV on 2017/11/16.
//
//

#include "SimpleAudioEngine.h"
#include "LVRootScene.h"

USING_NS_CC;

Scene* LVRootScene::createScene()
{
    return LVRootScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void searchScene(){
    printf("error");
}

// on "init" you need to initialize your instance
bool LVRootScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(LVRootScene::menuCloseCallback, this));
    
    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }
    
    /*粒子系统*/
    auto _emitter = ParticleSystemQuad::createWithTotalParticles(50);
    addChild(_emitter, 10);
    _emitter->setTexture(Director::getInstance()->getTextureCache()->addImage("CloseNormal.png"));
    _emitter->setAnchorPoint(Point(0, 0));
    // duration
    _emitter->setDuration(ParticleSystem::DURATION_INFINITY);
    
    // radius mode
    _emitter->setEmitterMode(ParticleSystem::Mode::RADIUS);
    
    // radius mode: start and end radius in pixels
    _emitter->setStartRadius(4);
    _emitter->setStartRadiusVar(100);
    _emitter->setEndRadius(ParticleSystem::START_RADIUS_EQUAL_TO_END_RADIUS);
    _emitter->setEndRadiusVar(100);
    
    // radius mode: degrees per second
    _emitter->setRotatePerSecond(100);
    _emitter->setRotatePerSecondVar(0);
    
    // angle
    _emitter->setAngle(90);
    _emitter->setAngleVar(0);
    
    // emitter position
    auto size = Director::getInstance()->getWinSize();
    _emitter->setPosVar(Point::ZERO);
    
    // life of particles
    _emitter->setLife(0.5);
    _emitter->setLifeVar(0);
    
    // spin of particles
    _emitter->setStartSpin(0);
    _emitter->setStartSpinVar(0);
    _emitter->setEndSpin(0);
    _emitter->setEndSpinVar(0);
    
    // color of particles
    Color4F startColor(0.0f, 0.8f, 0.9f, 1.0f);
    _emitter->setStartColor(startColor);
    
    Color4F startColorVar(0, 0, 0, 1.0f);
    _emitter->setStartColorVar(startColorVar);
    
    Color4F endColor(1.0f, 1.0f, 1.0f, 0.1f);
    _emitter->setEndColor(endColor);
    
    Color4F endColorVar(0, 0, 0, 0.1f);
    _emitter->setEndColorVar(endColorVar);
    
    // size, in pixels
    _emitter->setStartSize(20);
    _emitter->setStartSizeVar(1);
    _emitter->setEndSize(0);
    
    // emits per second
    _emitter->setEmissionRate(_emitter->getTotalParticles() / _emitter->getLife());
    
    // additive
    _emitter->setBlendAdditive(false);
    
    //addChild(_emitter);
    _emitter->setPosition(Point(200,200));
    
    
    scheduleUpdate();
    return true;
}

void LVRootScene::update(float dt)
{
    log("update");
}



void LVRootScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
