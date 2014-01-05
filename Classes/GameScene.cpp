#include "GameScene.h"
#include <CCDrawingPrimitives.h>
#include "Util.h"

USING_NS_CC;

Scene* Game::createScene()
{
  // 'scene' is an autorelease object
  auto scene = Scene::create();
    
  // 'layer' is an autorelease object
  auto layer = Game::create();

  // add layer as a child to scene
  scene->addChild(layer);

  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool Game::init()
{
  //////////////////////////////
  // 1. super init first
  if ( !Layer::init() )
    {
      return false;
    }
    
  mTouchEventListener = NULL;
  mScore = 0;
  mMeter = 0;
  mBomb = 0;
    
  this->scheduleUpdate();
  this->changeScene(eSTATE_WAIT);
    
  return true;
}

void Game::update(const float delta){
  switch(mState){
  case eSTATE_WAIT:
    this->updateWait(delta);
    break;
  case eSTATE_GAME:
    this->updateGame(delta);
    break;
  case eSTATE_DEAD:
    break;
  default:
    break;
  }
}

void Game::updateWait(const float delta){
  this->changeScene(eSTATE_GAME);
}

void Game::updateGame(const float delta){
  mPlayer.update(delta);
}

void Game::updateDead(const float delta){
    
}

void Game::changeScene(const eState next_state)
{
  if (mTouchEventListener != NULL) {
    Director::getInstance()->getEventDispatcher()->removeEventListener(mTouchEventListener);
  }
    
  switch(mState){
  case eSTATE_WAIT:
    this->releaseWait();
    break;
  case eSTATE_GAME:
    this->releaseGame();
    break;
  case eSTATE_DEAD:
    this->releaseDead();
    break;
  default:
    break;
  }
    
  switch(next_state){
  case eSTATE_WAIT:
    this->initWait();
    break;
  case eSTATE_GAME:
    this->initGame();
    break;
  case eSTATE_DEAD:
    this->initDead();
    break;
  default:
    break;
  }
    
  mState = next_state;
}

void Game::initWait(){
  mPlayer.initialize();

  auto label = this->createLabel("Game Start");
  label->setPosition(Point(100, 100));
  this->addChild(label);
}

void Game::initGame(){
  auto listener = EventListenerTouchOneByOne::create();
  listener->onTouchBegan = CC_CALLBACK_2(Game::gameOnTouchBegan, this);
  listener->onTouchEnded = CC_CALLBACK_2(Game::gameOnTouchEnded, this);
  Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
  mTouchEventListener = listener;
}

void Game::initDead(){
    
}

void  Game::releaseWait(){
    
}

void Game::releaseGame(){
    
}

void Game::releaseDead(){
}

void Game::draw(){
  switch(mState){
    case eSTATE_WAIT:
      this->drawWait();
      break;
    case eSTATE_GAME:
      this->drawGame();
      break;
    case eSTATE_DEAD:
      this->drawDead();
      break;
    default:
      break;
  }
}

void Game::drawWait(){
}

void Game::drawGame(){
  // player
  DrawPrimitives::setDrawColor4F(1.0f, 1.0f, 1.0f, 1.0f);
  DrawPrimitives::drawSolidCircle(mPlayer.getPosition(), 1.0f, CC_DEGREES_TO_RADIANS(360.f), 100, mPlayer.getSize().size.width, mPlayer.getSize().size.height);
  
  // enemies
  
  // bullets
  
  // effects
}

void Game::drawDead(){
  
}

bool Game::gameOnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
  auto p = touch->getLocation();
  auto center = Util::getCenterPosition();
  Point move_power = Point(1.0f, 0.0f);
  if (center.x > p.x){
    move_power = move_power * -1.0f;
  }
  mPlayer.setVelocity(move_power);

  return true;
}

void Game::gameOnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
  mPlayer.clearVelocity();
}
