// Copyright (c) 2005-2006_2007 David R. Cheriton.  All rights reserved.
// Modified by Chris Dembia (2013).

#include "Exception.h"

#include <assert.h>
#include <iostream>
#include <signal.h>

namespace framework
{

Exception::Id Exception::IdInstance( uint32_t v ) {
   switch( v ) {
    case _noException : return _noException;
    case _unknownException : return _unknownException;
    case _unknownTypeException : return _unknownTypeException;
    case _unknownAttrException : return _unknownAttrException;
    case _unknownDelimiterException : return _unknownDelimiterException;
    case _unknownArgException : return _unknownArgException;
    case _internalException : return _internalException;
    case _rangeException : return _rangeException;
    case _memoryException : return _memoryException;
    case _storageException : return _storageException;
    case _timeoutException : return _timeoutException;
    case _nameInUseException : return _nameInUseException;
    case _illegalNameException : return _illegalNameException;
    case _permissionException : return _permissionException;
    case _noImplementationException : return _noImplementationException;
    case _rpcException : return _rpcException;
    case _rpcConnectionException : return _rpcConnectionException;
    case _entityNotFoundException : return _entityNotFoundException;
    case _entityNotDirException : return _entityNotDirException;
    case _auditException : return _auditException;
    case _unknownEntityIdException : return _unknownEntityIdException;
    case _entityIdInUseException : return _entityIdInUseException;
    case _entityLogMsgLenException : return _entityLogMsgLenException;
    case _entityLogWriteToConstException : return _entityLogWriteToConstException;
    case _errnoException : return _errnoException;
    case _memoryLimitExceededException : return _memoryLimitExceededException;
    case _noParentException : return _noParentException;
    default : throw RangeException( "Exception::Id" );
   }
}

Exception::~Exception() {
}


Exception::Id
Exception::id() {
   return _unknownException;
}

Exception::Id
UnknownTypeException::id() {
   return _unknownTypeException;
}

Exception::Id
UnknownAttrException::id() {
   return _unknownAttrException;
}

Exception::Id
UnknownDelimiterException::id() {
   return _unknownDelimiterException;
}

Exception::Id
UnknownArgException::id() {
   return _unknownArgException;
}

Exception::Id
InternalException::id() {
   return _internalException;
}

Exception::Id
RangeException::id() {
   return _rangeException;
}

Exception::Id
MemoryException::id() {
   return _memoryException;
}

Exception::Id
StorageException::id() {
   return _storageException;
}

Exception::Id
TimeoutException::id() {
   return _timeoutException;
}

Exception::Id
NameInUseException::id() {
   return _nameInUseException;
}

Exception::Id
IllegalNameException::id() {
   return _illegalNameException;
}

Exception::Id
PermissionException::id() {
   return _permissionException;
}

Exception::Id
NoImplementationException::id() {
   return _noImplementationException;
}

Exception::Id
RpcException::id() {
   return _rpcException;
}

Exception::Id
RpcConnectionException::id() {
   return _rpcConnectionException;
}

Exception::Id
EntityNotFoundException::id() {
   return _entityNotFoundException;
}

Exception::Id
EntityNotDirException::id() {
   return _entityNotDirException;
}

Exception::Id
AuditException::id() {
   return _auditException;
}

Exception::Id
UnknownEntityIdException::id() {
   return _unknownEntityIdException;
}

Exception::Id
EntityIdInUseException::id() {
   return _entityIdInUseException;
}

Exception::Id
EntityLogMsgLenException::id() {
   return _entityLogMsgLenException;
}

Exception::Id
EntityLogWriteToConstException::id() {
   return _entityLogWriteToConstException;
}

Exception::Id
ErrnoException::id() {
   return _errnoException;
}

Exception::Id
ListException::id() {
   return _listException;
}

Exception::Id
MemoryLimitExceededException::id() {
   return _memoryLimitExceededException;
}

} // namespace framework
