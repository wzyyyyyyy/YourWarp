// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BoneAnimation {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BONEANIMATION
public:
    class BoneAnimation& operator=(class BoneAnimation const&) = delete;
    BoneAnimation() = delete;
#endif

public:
    MCAPI BoneAnimation(class BoneAnimation const&);
    MCAPI class BoneAnimationChannel& addAnimationChannel(enum BoneTransformType);
    MCAPI void setRotationRelativeMode(enum BoneAnimationRelativeMode);

protected:

private:

};