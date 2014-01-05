#include "Bullet.h"

USING_NS_CC;

Bullet::Bullet() : Unit(),
mHolder(NULL)
{
}

Bullet::~Bullet()
{
}

void Bullet::update(float delta)
{
}

void Bullet::render()
{
}

void Bullet::initialize(){
  mActive = false;
}

BulletList::BulletList(int size){
  mBullets = new Bullet[size];
  mCount = size;
  this->initialize();
}

BulletList::~BulletList(){
  delete [] mBullets;
}

void BulletList::initialize(){
  auto size = mCount;
  mUnused.resize(size);
  mUnused.clear();
  for (int i = 0; i < size; i++) {
    mBullets[i].initialize();
    mUnused.push_back(mBullets+ i);
  }
}

Bullet *BulletList::getUnsedBullet(){
  Bullet * ret = NULL;
  if (!mUnused.empty()) {
    ret = mUnused.front();
  }
  
  return ret;
}