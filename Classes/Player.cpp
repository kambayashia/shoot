#include "Player.h"
#include "Util.h"

USING_NS_CC;

const auto Player::DEFAULT_SPEED = 5.0f;
const auto Player::START_POSITION = 100.0f;
const auto Player::DEFAULT_SIZE = Rect(0, 0, 20, 20);
const auto Player::MAX_BULLETS = 30;

Player::Player() : Unit(),
mSpeed(Player::DEFAULT_SPEED),
mBulletList(Player::MAX_BULLETS)
{
}

Player::~Player()
{
}

void Player::update(float delta)
{
  this->addPosition(mVelocity);

  auto position = this->getPosition();
  auto size = this->getSize();
  auto display_size = Util::getDisplaySize();
  auto min_x = size.getMidX();
  auto max_x = display_size.width - size.getMidX();
  if (position.x < min_x) {
    position.x = min_x;
  }
  else if (position.x > max_x){
    position.x = max_x;
  }
  this->setPosition(position);
}

void Player::render()
{
}

void Player::collision(Unit &unit){
  
}

void Player::initialize(){
  auto point = Util::getCenterPosition();
  point.x -= DEFAULT_SIZE.size.width / 2;
  point.y = START_POSITION;
  setPosition(point);
  setSize(DEFAULT_SIZE);
  this->clearVelocity();
  
  // bullets
  mBulletList.initialize();
}

void Player::setVelocity(const cocos2d::Point &vector){
  mVelocity = vector * mSpeed;
}

void Player::clearVelocity(){
  this->setVelocity(Point(0.0f, 0.0f));
}
