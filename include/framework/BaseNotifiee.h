// Copyright(c) 1993-2006, 2007, David R. Cheriton, all rights reserved.
// Modified by Chris Dembia (2013).

#ifndef FRAMEWORK_BASENOTIFIEE_H
#define FRAMEWORK_BASENOTIFIEE_H

#include "framework/PtrInterface.h"
#include "framework/Exception.h"
#include "framework/Ptr.h"

using std::string;

namespace framework {

/**
 * @brief Basic notifiee class template.
 * */
class RootNotifiee : public framework::PtrInterface<RootNotifiee> {
public:
   typedef framework::Ptr<RootNotifiee const> PtrConst;
   typedef framework::Ptr<RootNotifiee> Ptr;

   enum AttributeId {
     _nullNotification_ = 0,
     _multipleAttributes = -1,
     _initialNotification = -2,
     _this = 1,

     _notificationException = 8,
     _notificationAttribute = 9,
     _deleteRef = 10,
     _references = 11,
     _auditErrors = 12,
     // Entity-level attributes
     _name = 2,
     _version = 3,
     _clone = 4,
     _entityRef = 5,
     _attribute = 6,
     _parent = 16,
     _syncMode = 17,
     _orphan = 20,
     _entityId = 22,
     _cloneState = 23,
     // FixMe: remove - not used.
     _nextAttributeNumber,
     _tacNextAttributeId = nextAttributeNumber,
     _negativeAttr = 0x80000000, 
   };
   AttributeId notificationAttribute() const { 
      return notificationAttribute_;
    }
   static string attributeString( AttributeId );
   RootNotifiee const * lqNext()  const { return lqNext_.ptr(); }
   virtual string name() const;
   // Non-const interface =================================================

   RootNotifiee * fwkValue() { return this; }
   void notificationAttribute(AttributeId _notificationAttribute ) {
      notificationAttribute_ = _notificationAttribute;
   }
   AttributeId tacKeyForNotificationException() const {
      return tacKeyForNotificationException_;
   }
   void tacKeyForNotificationExceptionIs( AttributeId aid ){
      tacKeyForNotificationException_ = aid;
   }
   U8 tacNotificationExceptionChanges() const {
      return tacNotificationExceptionChanges_;
   }
   void tacNotificationExceptionChangesIs( U8 tnec ) {
      tacNotificationExceptionChanges_ = tnec;
   }
   RootNotifiee * lqNext()  { return lqNext_.ptr(); }
   void lqNextIs( RootNotifiee* _lqNext ) { lqNext_ = _lqNext; }
   // linkedQueue use is for deferred notification

   virtual void isNonReferencingIs( bool b );

   // Constructors ========================================================
   RootNotifiee(): notificationAttribute_(
                   AttributeId(nullNotification_)) {}
   virtual void handleNotification( Activity * );
   virtual void handleDefault( Activity *, AttributeId, bool );
   virtual void onAttribute( AttributeId );
   // Notification of update with specified attributeId for this notifiee.

   virtual void onNotificationException();
   virtual void onNotificationException( AttributeId );
   virtual void handleNotificationException( AttributeId aid );
   virtual void handleNotificationException();
   virtual void onDelete();
   virtual void onNotification();
   virtual void onCollectionNotification( string );
   virtual U32 auditErrors( U32 ) const;
protected:
   AttributeId notificationAttribute_;
   Ptr    lqNext_;
   AttributeId tacKeyForNotificationException_;
   U8 tacNotificationExceptionChanges_;
};

template<typename Notifier>
class BaseNotifiee : public RootNotifiee {

public:
    BaseNotifiee(Notifier* n = NULL) : notifier_(n) {
        if (n != NULL) {
            n->notifieeIs(static_cast<typename Notifier::Notifiee*>(this));
        }
    }

    ~BaseNotifiee() {
        if (notifier_ != NULL) {
            notifier_->notifieeIs(0);
        }
    }

    framework::Ptr<Notifier> notifier() const {
        return notifier_;
    }

    void notifierIs(framework::Ptr<Notifier> n) {
        if (notifier_ != n) {
            if (notifier_ != NULL) {
                notifier_->notifieeIs(0);
            }
            notifier_ = n;
            if (n != NULL) {
                n->notifieeIs(
                        static_cast<typename Notifier::Notifiee*>(this)
                        );
            }
        }
    }

private:
    framework::Ptr<Notifier> notifier_;

};

}

#endif
