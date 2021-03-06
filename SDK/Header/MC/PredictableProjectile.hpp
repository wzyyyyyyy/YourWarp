// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PredictableProjectile : public Actor {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PREDICTABLEPROJECTILE
public:
    class PredictableProjectile& operator=(class PredictableProjectile const&) = delete;
    PredictableProjectile(class PredictableProjectile const&) = delete;
    PredictableProjectile() = delete;
#endif

public:
    /*0*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const&);
    /*1*/ virtual void _doInitialMove();
    /*2*/ virtual ~PredictableProjectile();
    /*3*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*4*/ virtual void __unk_vfn_0();
    /*5*/ virtual float getInterpolatedHeadRot(float) const;
    /*6*/ virtual float getInterpolatedBodyYaw(float) const;
    /*7*/ virtual class Vec3 getInterpolatedRidingOffset(float) const;
    /*8*/ virtual void __unk_vfn_1();
    /*9*/ virtual float getRidingHeight();
    /*10*/ virtual void __unk_vfn_2();
    /*11*/ virtual void __unk_vfn_3();
    /*12*/ virtual float getCameraOffset() const;
    /*13*/ virtual void __unk_vfn_4();
    /*14*/ virtual void __unk_vfn_5();
    /*15*/ virtual void playerTouch(class Player&);
    /*16*/ virtual bool isPickable();
    /*17*/ virtual void __unk_vfn_6();
    /*18*/ virtual bool isSleeping() const;
    /*19*/ virtual void setSleeping(bool);
    /*20*/ virtual void __unk_vfn_7();
    /*21*/ virtual bool isBlocking() const;
    /*22*/ virtual bool isDamageBlocked(class ActorDamageSource const&) const;
    /*23*/ virtual void __unk_vfn_8();
    /*24*/ virtual bool isSurfaceMob() const;
    /*25*/ virtual void __unk_vfn_9();
    /*26*/ virtual void __unk_vfn_10();
    /*27*/ virtual void __unk_vfn_11();
    /*28*/ virtual class Actor* findAttackTarget();
    /*29*/ virtual bool isValidTarget(class Actor*) const;
    /*30*/ virtual void adjustDamageAmount(int&) const;
    /*31*/ virtual void onTame();
    /*32*/ virtual void onFailedTame();
    /*33*/ virtual bool isJumping() const;
    /*34*/ virtual void vehicleLanded(class Vec3 const&, class Vec3 const&);
    /*35*/ virtual void animateHurt();
    /*36*/ virtual void onBounceStarted(class BlockPos const&, class Block const&);
    /*37*/ virtual float getPickRadius();
    /*38*/ virtual void awardKillScore(class Actor&, int);
    /*39*/ virtual enum ArmorMaterialType getArmorMaterialTypeInSlot(enum ArmorSlot) const;
    /*40*/ virtual enum ArmorTextureType getArmorMaterialTextureTypeInSlot(enum ArmorSlot) const;
    /*41*/ virtual float getArmorColorInSlot(enum ArmorSlot, int) const;
    /*42*/ virtual void setEquippedSlot(enum EquipmentSlot, class ItemStack const&);
    /*43*/ virtual class HashedString const& queryEntityRenderer() const;
    /*44*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*45*/ virtual bool canFreeze() const;
    /*46*/ virtual int getPortalWaitTime() const;
    /*47*/ virtual bool canChangeDimensions() const;
    /*48*/ virtual void __unk_vfn_12();
    /*49*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*50*/ virtual bool canPickupItem(class ItemStack const&) const;
    /*51*/ virtual bool canBePulledIntoVehicle() const;
    /*52*/ virtual bool inCaravan() const;
    /*53*/ virtual void __unk_vfn_13();
    /*54*/ virtual bool canSynchronizeNewEntity() const;
    /*55*/ virtual void buildDebugInfo(std::string&) const;
    /*56*/ virtual int getDeathTime() const;
    /*57*/ virtual void swing();
    /*58*/ virtual void __unk_vfn_14();
    /*59*/ virtual void __unk_vfn_15();
    /*60*/ virtual float getYHeadRot() const;
    /*61*/ virtual bool isWorldBuilder() const;
    /*62*/ virtual void __unk_vfn_16();
    /*63*/ virtual bool isAdventure() const;
    /*64*/ virtual bool canDestroyBlock(class Block const&) const;
    /*65*/ virtual void setAuxValue(int);
    /*66*/ virtual void stopSpinAttack();
    /*67*/ virtual void __unk_vfn_17();
    /*68*/ virtual void __unk_vfn_18();
    /*69*/ virtual void updateEntitySpecificMolangVariables(class RenderParams&);
    /*70*/ virtual void __unk_vfn_19();
    /*71*/ virtual void __unk_vfn_20();
    /*72*/ virtual void _onSizeUpdated();
    /*
    inline  ~PredictableProjectile(){
         (PredictableProjectile::*rv)();
        *((void**)&rv) = dlsym("??1PredictableProjectile@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI PredictableProjectile(class ActorDefinitionGroup*, struct ActorDefinitionIdentifier const&, class OwnerPtrT<struct EntityRefTraits> const&);

protected:

private:

};