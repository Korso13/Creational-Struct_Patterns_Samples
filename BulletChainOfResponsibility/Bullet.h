#pragma once
#include "KillDataRequester.h"

class Actor;

class Bullet : public KillDataRequester
{
public:

    Bullet(KillDataRequester* parent);

    bool requestKillData(KillData& data) override;

private:

    void onHit(const Actor& hitTarget);
    
};
