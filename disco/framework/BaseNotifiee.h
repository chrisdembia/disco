// Copyright(c) 1993-2006, 2007, David R. Cheriton, all rights reserved.
// Modified by Chris Dembia (2013).

#ifndef FRAMEWORK_BASENOTIFIEE_H
#define FRAMEWORK_BASENOTIFIEE_H

#include "PtrInterface.h"
#include "Exception.h"
#include "Ptr.h"

using std::string;

namespace framework
{

/**
 * @brief Basic notifiee class template.
 * */
class RootNotifiee : public framework::PtrInterface<RootNotifiee>
{
public:
   typedef framework::Ptr<RootNotifiee const> PtrConst;
   typedef framework::Ptr<RootNotifiee> Ptr;

   enum AttributeId {
     _nullNotification = 0,
     _multipleAttributes = -1,
     _initialNotification = -2,
     _this = 1,

     // TODO _notificationException = 8,
     // TODO _notificationAttribute = 9,
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
     _tacNextAttributeId = _nextAttributeNumber,
     _negativeAttr = 0x80000000, 
   };
   AttributeId notificationAttribute() const
   {
      return _notificationAttribute;
    }
   static string attributeString( AttributeId );
   RootNotifiee const * lqNext()  const { return _lqNext.ptr(); }
   virtual string name() const;
   // Non-const interface =================================================

   RootNotifiee * fwkValue() { return this; }
   void notificationAttribute(AttributeId notificationAttribute )
   {
      _notificationAttribute = notificationAttribute;
   }

   AttributeId tacKeyForNotificationException() const
   {
      return _tacKeyForNotificationException;
   }

   void tacKeyForNotificationExceptionIs( AttributeId aid )
   {
      _tacKeyForNotificationException = aid;
   }

   uint8_t tacNotificationExceptionChanges() const
   {
      return _tacNotificationExceptionChanges;
   }

   void tacNotificationExceptionChangesIs( uint8_t tnec )
   {
      _tacNotificationExceptionChanges = tnec;
   }

   RootNotifiee * lqNext()  { return _lqNext.ptr(); }
   void lqNextIs( RootNotifiee * lqNext ) { _lqNext = lqNext; }
   // linkedQueue use is for deferred notification

   virtual void isNonReferencingIs( bool b );

   // Constructors ========================================================
   RootNotifiee(): _notificationAttribute(
                   AttributeId(_nullNotification)) {}
   // virtual void handleNotification( Activity * );
   // virtual void handleDefault( Activity *, AttributeId, bool );
   virtual void onAttribute( AttributeId );
   // Notification of update with specified attributeId for this notifiee.

   virtual void onNotificationException();
   virtual void onNotificationException( AttributeId );
   virtual void handleNotificationException( AttributeId aid );
   virtual void handleNotificationException();
   virtual void onDelete();
   virtual void onNotification();
   virtual void onCollectionNotification( string );
   virtual uint32_t auditErrors( uint32_t ) const;
protected:
   AttributeId _notificationAttribute;
   Ptr    _lqNext;
   AttributeId _tacKeyForNotificationException;
   uint8_t _tacNotificationExceptionChanges;
};

template<typename Notifier>
class BaseNotifiee : public RootNotifiee
{
public:
    BaseNotifiee(Notifier* n = NULL) : _notifier(n)
    {
        if (n != NULL)
        {
            n->notifieeIs(static_cast<typename Notifier::Notifiee*>(this));
        }
    }

    ~BaseNotifiee()
    {
        if (_notifier != NULL)
        {
            _notifier->notifieeIs(0);
        }
    }

    framework::Ptr<Notifier> notifier() const
    {
        return _notifier;
    }

    void notifierIs(framework::Ptr<Notifier> n)
    {
        if (_notifier != n)
        {
            if (_notifier != NULL)
            {
                _notifier->notifieeIs(0);
            }
            _notifier = n;
            if (n != NULL)
            {
                n->notifieeIs(
                        static_cast<typename Notifier::Notifiee*>(this)
                        );
            }
        }
    }

private:
    framework::Ptr<Notifier> _notifier;

};

} // namespace framework

#endif
