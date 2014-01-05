#include "Unit.h"

Unit::Unit()
{
  mPosition.setPoint(.0f, .0f);
  mDrawState = eDRAW_STATE_DISABLE;
}

Unit::~Unit()
{
}

void Unit::collision(Unit &unit){
  
}