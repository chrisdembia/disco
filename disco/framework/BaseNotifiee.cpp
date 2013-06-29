// Copyright (c) 2005-2006_2007 David R. Cheriton.  All rights reserved.

#include "framework/BaseNotifiee.h"

#include <iostream>

using std::string;

namespace framework {

class Activity;
string RootNotifiee::name() const { return "unknown"; }
void RootNotifiee::isNonReferencingIs( bool b ) { assert( false ); }
void RootNotifiee::handleNotification( Activity * ) {}
void RootNotifiee::handleDefault( Activity *, AttributeId, bool ) {}
void RootNotifiee::onAttribute( AttributeId ) {}
void RootNotifiee::onNotificationException() {}

void RootNotifiee::onNotificationException( AttributeId ) { 
   onNotificationException();
}

void
RootNotifiee::handleNotificationException( AttributeId aid ) {
   onNotificationException(aid);
}
void
RootNotifiee::handleNotificationException() {
   onNotificationException();
}
void RootNotifiee::onDelete( ) {}
U32 RootNotifiee::auditErrors( U32 ) const { return 0; }

// support for generic TacNotifieeAdapter
void RootNotifiee::onNotification() {}
void RootNotifiee::onCollectionNotification( string ) {}

string RootNotifiee::attributeString( RootNotifiee::AttributeId a )
{
   string str = "unknown";
   switch (a) {
     case _nullNotification_: str = "_nullNotification_"; break;
     case _multipleAttributes: str = "_multipleAttributes"; break;
     case _initialNotification: str = "_initialNotification"; break;
     case _this: str = "_this"; break;
     case _notificationException: str = "_notificationException"; break;
     case _notificationAttribute: str = "_notificationAttribute"; break;
     case _deleteRef: str = "_deleteRef"; break;
     case _references: str = "_references"; break;
     case _auditErrors: str = "_auditErrors"; break;
     case _name: str = "_name"; break;
     case _version: str = "_version"; break;
     case _clone: str = "_clone"; break;
     case _entityRef: str = "_entityRef"; break;
     case _attribute: str = "_attribute"; break;
     case _parent: str = "_parent"; break;
     case _syncMode: str = "_syncMode"; break;
     case _orphan: str = "_orphan"; break;
     case _entityId: str = "_entityId"; break;
     case _cloneState: str = "_cloneState"; break;
     default: /* nothing */;
   }
   return str;
}

} // namespace framework
