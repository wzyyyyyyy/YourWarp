// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "MobEffect.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class InstantaneousMobEffect : public MobEffect {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INSTANTANEOUSMOBEFFECT
public:
    class InstantaneousMobEffect& operator=(class InstantaneousMobEffect const&) = delete;
    InstantaneousMobEffect(class InstantaneousMobEffect const&) = delete;
    InstantaneousMobEffect() = delete;
#endif

public:
    /*0*/ virtual ~InstantaneousMobEffect();
    /*1*/ virtual bool isInstantaneous() const;
    /*2*/ virtual bool isDurationEffectTick(int, int) const;
    MCAPI InstantaneousMobEffect(int, std::string const&, std::string const&, bool, int, int);

protected:

private:

};