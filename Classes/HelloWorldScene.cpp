#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

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

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    
    
    /*层*/
    //    auto layer22 = LayerColor::create(Color4B(0, 128, 128, 255));
    //    layer22->setContentSize(CCSizeMake(120, 80));
    //    layer22->setPosition(Point(50, 50));
    //    this->addChild(layer22);
    //
    //    auto sprite1 = Sprite::createWithTexture(TextureCache::getInstance()->addImage("HelloWorld.png"));
    //    this->addChild(sprite1, 0);
    
    
    
    //    auto red = LayerColor::create(Color4B(255, 100, 100, 228), visibleSize.width/2.0, visibleSize.height/2.0);
    //    red->ignoreAnchorPointForPosition(false);
    ////    red->setAnchorPoint(Point(0.5, 0.5));
    //    red->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    ////    red->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //
    //    auto green = LayerColor::create(Color4B(100, 255, 100, 128), visibleSize.width/4.0, visibleSize.height/4.0);
    //    green->ignoreAnchorPointForPosition(false);
    ////    green->setAnchorPoint(Point(1, 1));
    //    green->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2 - 100));
    //
    ////    red->setPositionZ(1);
    ////    green->setPositionZ(0);
    //
    //    this->addChild(green);
    //    this->addChild(red);
    
    
    //    auto *sprite1 = Sprite::create("HelloWorld.png");
    //    sprite1->setPosition(ccp(20,40));
    //    sprite1->setAnchorPoint(ccp(0,0));
    //    this->addChild(sprite1);  //此时添加到的是世界坐标系，也就是OpenGL坐标系
    //
    //    auto *sprite2 = Sprite::create("HelloWorld.png");
    //    sprite2->setPosition(ccp(-5,-20));
    //    sprite2->setAnchorPoint(ccp(1,1));
    //    this->addChild(sprite2); //此时添加到的是世界坐标系，也就是OpenGL坐标系
    //
    //    //将 sprite2 这个节点的坐标ccp(-5,-20) 转换为 sprite1节点 下的本地(节点)坐标系统的 位置坐标
    //    Point point1 = sprite1->convertToNodeSpace(sprite2->getPosition());
    //
    //    //将 sprite2 这个节点的坐标ccp(-5,-20) 转换为 sprite1节点 下的世界坐标系统的 位置坐标
    //    Point point2 = sprite1->convertToWorldSpace(sprite2->getPosition());
    //
    //    log("position = (%f,%f)",point1.x,point1.y);
    //    log("position = (%f,%f)",point2.x,point2.y);
    
    
    /*动作*/
    
    //     auto placeAction = Place::create(Point(10, 10));
    
    
    auto green = LayerColor::create(Color4B(100, 255, 100, 128), visibleSize.width/4.0, visibleSize.height/4.0);
    green->ignoreAnchorPointForPosition(false);
    green->setAnchorPoint(CCPointMake(0.5, 0.5));
    green->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(green);
    
    
    auto flipxAction = FlipX::create(true);
    auto moveTo = MoveTo::create(4.0f, Point(0, 0));
    
    auto hideAction = Hide::create();
    auto moveTo1 = MoveTo::create(0.4f, Point(visibleSize.width / 2, visibleSize.height / 2));
    
    auto actionMoveDone = CallFuncN::create([&](Ref* sender){
        log("Clear memory");
    });
    
    auto blink = Blink::create(5, 10);
    
    auto jump = JumpTo::create(6, Point(0, visibleSize.height/2.0), 40, 10);
    
    /**/
    ccBezierConfig bezier;
    bezier.controlPoint_1 = Point(visibleSize.width/2.0, visibleSize.height/2.0);
    bezier.controlPoint_2 = Point(visibleSize.width, 0);
    bezier.endPosition = Point(visibleSize.width, visibleSize.height/2.0);
    auto bezierAction = BezierTo::create(5.5f, bezier);
    
    auto scale = ScaleTo::create(5.8, 0.5);
    
    auto rotate = RotateTo::create(5.0, 460);
    
    //使一批动作同时执行
    auto allAction =  Spawn::create(ScaleTo::create(5.8, 3), JumpTo::create(5.8, Point(0, visibleSize.height/2.0), 40, 10), NULL);
    
    auto action = Sequence::create(allAction, rotate, scale, bezierAction, jump, blink, moveTo, moveTo1, hideAction, actionMoveDone, NULL);
    green->runAction(action);
    
    /*序列帧动画*/
    
    /*声音*/
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/background.mp3", true); //播放背景音乐
    
    
    /*人机交互*/
    // 创建按钮精灵
    auto sprite1 = Sprite::create("HelloWorld.png");
    sprite1->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    addChild(sprite1, 10);
    
    // 创建一个事件监听器类型为 OneByOne 的单点触摸
    auto listener1 = EventListenerTouchOneByOne::create();
    // 设置是否吞没事件，在 onTouchBegan 方法返回 true 时吞没
    listener1->setSwallowTouches(true);
    
    // 使用 lambda 实现 onTouchBegan 事件回调函数
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        log("+ppppppppp");
        // 获取事件所绑定的 target
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        // 获取当前点击点所在相对按钮的位置坐标
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        // 点击范围判断检测
        if (rect.containsPoint(locationInNode))
        {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            //            target->setOpacity(180);
            
            auto visibleSize = Director::getInstance()->getVisibleSize();
            auto jump = JumpTo::create(6, Point(visibleSize.width/2.0, visibleSize.height/2.0), 40, 10);
            target->runAction(jump);
            return true;
        }
        return false;
    };
    
    // 触摸移动时触发
    listener1->onTouchMoved = [](Touch* touch, Event* event){
        log("+++++++++");
    };
    
    // 点击事件结束处理
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        log("-------");
    };
    
    // 添加监听器
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite1);
    //    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite2);
    //    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), sprite3);
    
    //    scheduleUpdate();

    
    return true;
}

void HelloWorld::update(float dt)
{
    log("update");
}



void HelloWorld::menuCloseCallback(Ref* pSender)
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
