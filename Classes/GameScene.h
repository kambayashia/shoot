#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "MyLayer.h"
#include "Player.h"
#include "Enemy.h"

#define MAX_ENEMY_COUNT 50

class Game : public MyLayer
{
  enum eState{
    eSTATE_WAIT,
    eSTATE_GAME,
    eSTATE_DEAD,
        
    eSTATE_MAX
  };
    
public:
  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  static cocos2d::Scene* createScene();

  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();  
        
  // implement the "static create()" method manually
  CREATE_FUNC(Game);
    
  void update(const float delta);
  void draw();
private:
  void updateWait(const float delta);
  void updateGame(const float delta);
  void updateDead(const float delta);
    
  void changeScene(const eState next_state);
  void initWait();
  void initGame();
  void initDead();
    
  void releaseWait();
  void releaseGame();
  void releaseDead();
  
  void drawWait();
  void drawGame();
  void drawDead();
    
  bool gameOnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
  void gameOnTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
  
private:
  cocos2d::EventListener *mTouchEventListener;
    
  Player mPlayer;
  Enemy  mEnemies[MAX_ENEMY_COUNT];
  eState mState;
  int mScore;
  int mMeter;
  int mBomb;
};

#endif // __GAME_SCENE_H__
