// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class AttributeBuff {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ATTRIBUTEBUFF
public:
    class AttributeBuff& operator=(class AttributeBuff const&) = delete;
    AttributeBuff(class AttributeBuff const&) = delete;
    AttributeBuff() = delete;
#endif

public:
    /*0*/ virtual ~AttributeBuff();
    /*1*/ virtual bool isInstantaneous() const = 0;
    /*2*/ virtual bool isSerializable() const = 0;
    /*3*/ virtual void setDurationAmplifier(class std::shared_ptr<class Amplifier>);
    /*
    inline  ~AttributeBuff(){
         (AttributeBuff::*rv)();
        *((void**)&rv) = dlsym("??1AttributeBuff@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI float getAmount() const;
    MCAPI unsigned __int64 getId() const;
    MCAPI int getOperand() const;
    MCAPI enum AttributeBuffType getType() const;
    MCAPI void setAmplificationAmount(int, float);
    MCAPI void setId(unsigned __int64);
    MCAPI void setOperand(int);
    MCAPI void setSource(class Actor*);
    MCAPI void setValueAmplifier(class std::shared_ptr<class Amplifier>);
    MCAPI static enum ActorDamageCause buffTypeToDamageCause(enum AttributeBuffType);

protected:

private:

};