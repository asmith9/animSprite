#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    public:
        Entity();
        void instantiate(int);
        void attack(Entity&);
        int hp, mp, ynt, mnd, cha, dex, agi,
        eva, acc, str, att, def, vit, lvl;
        bool fire, thunder, stone, water, light, dark,
            h2h, pierce, slash;
    protected:
    private:
        char* drops;
};
class WhiteMagic {
    public:
    protected:
    private:
        void cure();
        void regen();
        void dia();
        void flash();
        void holy();
        void stoneskin();
};
class BlackMagic {
    public:
    protected:
    private:
        void fire();
        void water();
        void thunder();
        void stone();
        void poison();
        void bio();
        void drain();
        void aspir();
};
class RedMagic {
    public:
    protected:
    private:
        void refresh();
        void phalanx();
};
class DarkMagic {
    public:
    protected:
    private:
        void darkSpikes();
        void absorbStat();
};
class BlackMage: private Entity, private BlackMagic {
    public:
    protected:
    private:
        void darkSeal();
};
class WhiteMage: private Entity {
    public:
    protected:
    private:
        void lightSeal();
};
class Warrior: private Entity {
    public:
    protected:
    private:
        void provoke();
        void defender();
        void berserk();
};
class RedMage: private Entity, private WhiteMagic, private BlackMagic,
    private RedMagic {
    public:
    protected:
    private:
};
class Monk: private Entity {
    public:
    protected:
    private:
        void hype();
        void chiBlast();
        void dodge();
        void focus();
};
class Dragoon: private Entity {
    public:
    protected:
    private:
        void jump();
        void highJump();
};
class DarkKnight: private Entity, private BlackMagic {
    public:
    protected:
    private:
        void lastResort();
        void soulEater();
};
class Paladin: private Entity, private WhiteMagic {
    public:
    protected:
    private:
        void sentinel();
};
class Thief: public Entity {
    public:
        Thief();
    protected:
    private:
        void flee();
        void steal();
        void mug();
};
class Samurai: private Entity {
    public:
    protected:
    private:
        void meditate();
        void thirdEye();
};
class Ranger: private Entity {
    public:
    protected:
    private:
        void barrage();
        void shadowBind();
};

class ForestHare: public Thief {
    public:
        ForestHare();
    protected:
    private:
        int swiftKick();
        int dustKick();

};
class Worm: public BlackMage {
    public:
    protected:
    private:
        void tornado();
        void stoneskin();
};
class Sheep: private Warrior {
    public:
    protected:
    private:
        void sheepSong();
        void charge();
};
class Beetle: private Paladin {
    public:
    protected:
    private:
};

#endif // ENTITY_H
