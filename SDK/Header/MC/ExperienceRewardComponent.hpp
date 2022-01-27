// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ExperienceRewardComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EXPERIENCEREWARDCOMPONENT
public:
    class ExperienceRewardComponent& operator=(class ExperienceRewardComponent const&) = delete;
    ExperienceRewardComponent(class ExperienceRewardComponent const&) = delete;
    ExperienceRewardComponent() = delete;
#endif

public:
    MCAPI int getOnBredExperience(class Actor&) const;
    MCAPI int getOnDeathExperience(class Actor&) const;
    MCAPI class ExperienceRewardComponent& operator=(class ExperienceRewardComponent&&);

protected:

private:

};