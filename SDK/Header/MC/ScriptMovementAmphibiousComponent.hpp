// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Scripting.hpp"
#include "ScriptActorComponent.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptMovementAmphibiousComponent : public ScriptActorComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTMOVEMENTAMPHIBIOUSCOMPONENT
public:
    class ScriptMovementAmphibiousComponent& operator=(class ScriptMovementAmphibiousComponent const&) = delete;
    ScriptMovementAmphibiousComponent(class ScriptMovementAmphibiousComponent const&) = delete;
    ScriptMovementAmphibiousComponent() = delete;
#endif

public:
    /*0*/ virtual ~ScriptMovementAmphibiousComponent();
    /*
    inline  ~ScriptMovementAmphibiousComponent(){
         (ScriptMovementAmphibiousComponent::*rv)();
        *((void**)&rv) = dlsym("??1ScriptMovementAmphibiousComponent@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI class Scripting::Result<float> getMaxTurn() const;
    MCAPI static class Scripting::ClassBindingBuilder<class ScriptMovementAmphibiousComponent> bind(struct Scripting::Version);

protected:

private:

};