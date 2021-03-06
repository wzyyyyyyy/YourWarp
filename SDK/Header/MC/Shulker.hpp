// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Mob.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Shulker : public Mob {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SHULKER
public:
    class Shulker& operator=(class Shulker const&) = delete;
    Shulker(class Shulker const&) = delete;
    Shulker() = delete;
#endif

public:
    /*0*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const&);
    /*1*/ virtual ~Shulker();
    /*2*/ virtual void setPos(class Vec3 const&);
    /*3*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*4*/ virtual void __unk_vfn_0();
    /*5*/ virtual class Vec3 getInterpolatedRidingOffset(float) const;
    /*6*/ virtual void __unk_vfn_1();
    /*7*/ virtual void normalTick();
    /*8*/ virtual float getRidingHeight();
    /*9*/ virtual bool isInWall() const;
    /*10*/ virtual void __unk_vfn_2();
    /*11*/ virtual void __unk_vfn_3();
    /*12*/ virtual float getCameraOffset() const;
    /*13*/ virtual float getShadowRadius() const;
    /*14*/ virtual void __unk_vfn_4();
    /*15*/ virtual void __unk_vfn_5();
    /*16*/ virtual void playerTouch(class Player&);
    /*17*/ virtual void __unk_vfn_6();
    /*18*/ virtual void __unk_vfn_7();
    /*19*/ virtual bool isDamageBlocked(class ActorDamageSource const&) const;
    /*20*/ virtual void __unk_vfn_8();
    /*21*/ virtual void __unk_vfn_9();
    /*22*/ virtual void __unk_vfn_10();
    /*23*/ virtual void __unk_vfn_11();
    /*24*/ virtual bool canAttack(class Actor*, bool) const;
    /*25*/ virtual class Actor* findAttackTarget();
    /*26*/ virtual bool isValidTarget(class Actor*) const;
    /*27*/ virtual void adjustDamageAmount(int&) const;
    /*28*/ virtual void onTame();
    /*29*/ virtual void onFailedTame();
    /*30*/ virtual void vehicleLanded(class Vec3 const&, class Vec3 const&);
    /*31*/ virtual bool shouldRender() const;
    /*32*/ virtual bool isInvulnerableTo(class ActorDamageSource const&) const;
    /*33*/ virtual void onBounceStarted(class BlockPos const&, class Block const&);
    /*34*/ virtual float getPickRadius();
    /*35*/ virtual void awardKillScore(class Actor&, int);
    /*36*/ virtual class HashedString const& queryEntityRenderer() const;
    /*37*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*38*/ virtual int getPortalWaitTime() const;
    /*39*/ virtual bool canChangeDimensions() const;
    /*40*/ virtual void __unk_vfn_12();
    /*41*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*42*/ virtual bool canPickupItem(class ItemStack const&) const;
    /*43*/ virtual bool canBePulledIntoVehicle() const;
    /*44*/ virtual void __unk_vfn_13();
    /*45*/ virtual bool canSynchronizeNewEntity() const;
    /*46*/ virtual void __unk_vfn_14();
    /*47*/ virtual void __unk_vfn_15();
    /*48*/ virtual bool isWorldBuilder() const;
    /*49*/ virtual void __unk_vfn_16();
    /*50*/ virtual bool isAdventure() const;
    /*51*/ virtual bool canDestroyBlock(class Block const&) const;
    /*52*/ virtual void setAuxValue(int);
    /*53*/ virtual void stopSpinAttack();
    /*54*/ virtual void __unk_vfn_17();
    /*55*/ virtual void __unk_vfn_18();
    /*56*/ virtual void updateEntitySpecificMolangVariables(class RenderParams&);
    /*57*/ virtual void __unk_vfn_19();
    /*58*/ virtual bool _hurt(class ActorDamageSource const&, int, bool, bool);
    /*59*/ virtual void readAdditionalSaveData(class CompoundTag const&, class DataLoadHelper&);
    /*60*/ virtual void addAdditionalSaveData(class CompoundTag&);
    /*61*/ virtual void __unk_vfn_20();
    /*62*/ virtual void _onSizeUpdated();
    /*63*/ virtual void __unk_vfn_21();
    /*64*/ virtual void spawnAnim();
    /*65*/ virtual void travel(float, float, float);
    /*66*/ virtual void aiStep();
    /*67*/ virtual bool checkSpawnRules(bool);
    /*68*/ virtual int getItemUseDuration() const;
    /*69*/ virtual float getItemUseStartupProgress() const;
    /*70*/ virtual float getItemUseIntervalProgress() const;
    /*71*/ virtual void __unk_vfn_22();
    /*72*/ virtual float getMaxHeadXRot();
    /*73*/ virtual bool isAlliedTo(class Mob*);
    /*74*/ virtual void __unk_vfn_23();
    /*75*/ virtual int getArmorValue();
    /*76*/ virtual void sendArmorDamage(class std::bitset<4> const&);
    /*77*/ virtual void onBorn(class Actor&, class Actor&);
    /*78*/ virtual int getAttackTime();
    /*79*/ virtual float _getWalkTargetValue(class BlockPos const&);
    /*80*/ virtual void __unk_vfn_24();
    /*81*/ virtual std::unique_ptr<class BodyControl> initBodyControl();
    /*82*/ virtual void _serverAiMobStep();
    /*83*/ virtual void __unk_vfn_25();
    /*
    inline bool isLeashableType(){
        bool (Shulker::*rv)();
        *((void**)&rv) = dlsym("?isLeashableType@Shulker@@UEAA_NXZ");
        return (this->*rv)();
    }
    inline bool useNewAi() const{
        bool (Shulker::*rv)() const;
        *((void**)&rv) = dlsym("?useNewAi@Shulker@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline std::unique_ptr<class BodyControl> initBodyControl(){
        std::unique_ptr<class BodyControl> (Shulker::*rv)();
        *((void**)&rv) = dlsym("?initBodyControl@Shulker@@UEAA?AV?$unique_ptr@VBodyControl@@U?$default_delete@VBodyControl@@@std@@@std@@XZ");
        return (this->*rv)();
    }
    */
    MCAPI Shulker(class ActorDefinitionGroup*, struct ActorDefinitionIdentifier const&, class OwnerPtrT<struct EntityRefTraits> const&);
    MCAPI void calculateBB();
    MCAPI bool isValidAttach(class BlockPos, unsigned char);
    MCAPI void setAttachFace(unsigned char);
    MCAPI void setPeekAmount(int);
    MCAPI void setShulkerAttachPos(class BlockPos);
    MCAPI static class std::shared_ptr<class AttributeModifier> COVERED_ARMOR_MODIFIER;
    MCAPI static class mce::UUID const COVERED_ARMOR_MODIFIER_UUID;

protected:
    MCAPI bool tryFindNewAttachPosition();
    MCAPI bool trySetNewAttachPosition(class BlockPos const&);

private:

};