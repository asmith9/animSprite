#include "../include/entity.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Entity::Entity()
{
    hp=100, mp=20, ynt=10, mnd=10, cha=10, dex=10, agi=10,
        eva=50, str=10, att=50, def=50, vit=10;
        std::cout << "hello\n";
}
void Entity::attack(Entity& a)
{
/*    if (rand()%a.eva+rand()%(a.agi/2) >= rand()%this->acc+(this->dex/2))
        cout << "You missed!";
        else if ()
        */
}
void Entity::instantiate(int lvl)
{
    hp+=hp%lvl, mp+=mp%lvl, ynt+=ynt%lvl, mnd+=mnd%lvl,
    cha+=cha%lvl, dex+=dex%lvl, agi+=agi%lvl, eva+=eva%lvl,
    str+=str%lvl, att+=att%lvl, def+=def%lvl, vit+=vit%lvl;
}
Thief::Thief()
{
    hp=76, mp=0, ynt=7, mnd=6, cha=5, dex=12, agi=11,
        eva=63, str=7, att=47, def=39, vit=7;
}
void Thief::flee() {

}
ForestHare::ForestHare()
{
    instantiate(3);

}
void Monk::hype()
{
    this->att+=0.2*this->att;
}
void WhiteMagic::cure()
{

}
