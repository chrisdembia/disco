// Copyright(c) 1993-2006_2007, David R. Cheriton, all rights reserved.
// Modified by Chris Dembia (2013).

#ifndef DISCO_FRAMEWORK_EXCEPTION_H
#define DISCO_FRAMEWORK_EXCEPTION_H

#include <cstring>
#include <iostream>
#include <stdint.h>

#include "Ptr.h"
#include "PtrInterface.h"

// Don't want to see strerror warnings; assume we won't get buffer overflowed.
#ifdef _MSC_VER
  #pragma warning(disable: 4996)
#endif

using std::ostream;
using std::string;

namespace framework {

class Exception {
public:

   enum Id { // Enum for remote designation
      _noException = 0,
      _unknownException = 1,
      _unknownTypeException = 2,
      _unknownAttrException = 3,
      _unknownDelimiterException = 4,
      _unknownArgException = 5,
      _internalException = 6,
      _rangeException = 7,
      _memoryException = 8,
      _storageException = 9,
      _timeoutException = 10,
      _nameInUseException = 11,
      _illegalNameException = 12,
      _permissionException = 13,
      _noImplementationException = 14,
      _rpcException = 15,
      _rpcConnectionException = 16,
      _entityNotFoundException = 17,
      _entityNotDirException = 18,
      _auditException = 19,
      _unknownEntityIdException = 20,
      _entityIdInUseException = 21,
      _entityLogMsgLenException = 22,
      _entityLogWriteToConstException = 23,
      _errnoException = 24,
      _listException = 25,
      _memoryLimitExceededException = 26,
      _noParentException = 27,
   };

   static Id IdInstance( uint32_t v );

   string what() const { return _what; }
   virtual ~Exception();
   // Providing a virtual destructor enables us to catch an Exception, and
   // then dynamic_cast it to a derived exception type or fetch its typeid, etc.
   virtual Id id();
protected:
   Exception( char const * str ) : _what(str) {}
   Exception( string str ) : _what(str) {}
private:
   string _what;
};

ostream & operator<<( ostream &, Exception const & );

class UnknownTypeException : public Exception {
public:
   UnknownTypeException( string what )  : Exception(what) {}
   virtual Id id();
};

class UnknownAttrException : public Exception {
public:
   UnknownAttrException( string what )  : Exception(what) {}
   virtual Id id();
};

class UnknownDelimiterException : public Exception {
public:
   UnknownDelimiterException( string what )  : Exception(what) {}
   virtual Id id();
};

class UnknownArgException : public Exception {
public:
   UnknownArgException( string what )  : Exception(what) {}
   virtual Id id();
};

class InternalException : public Exception {
public:
   InternalException( string what ) : Exception(what) {}
   virtual Id id();
};

class RangeException : public Exception {
public:
   RangeException( string what ) : Exception(what) {}
   virtual Id id();
};

class MemoryException : public Exception {
 public:
   MemoryException( string what ) : Exception(what) {}
   virtual Id id();
};

class StorageException : public Exception {
 public:
   StorageException( string what ) : Exception(what) {}
   virtual Id id();
};

class TimeoutException : public Exception {
 public:
   TimeoutException( string what ) : Exception(what) {}
   virtual Id id();
};

class NameInUseException : public Exception {
public:
   NameInUseException( string what ) : Exception( what ) {}
   virtual Id id();
};

class IllegalNameException: public Exception {
 public:
   IllegalNameException( string what ): Exception( what ) {}
   virtual Id id();
};

class PermissionException : public Exception {
public:
   PermissionException( string what ) : Exception( what ) {}
   virtual Id id();
};

class NoImplementationException : public Exception {
public:
   NoImplementationException( string what /*, bool debug=true */ ) : Exception( what /*, debug */ ) {}
   virtual Id id();
};

class AttributeNotSupportedException : public NoImplementationException {
public:
   AttributeNotSupportedException( string what )
         : NoImplementationException( what /*, false*/ ) {}
   // Sets debug to false so we don't drop into the debugger when
   // python attempts to access unimplemented attributes.
};

class RpcException : public Exception {
public:
   RpcException( string what ) : Exception( what ) {}
   virtual Id id();
};

class RpcConnectionException : public RpcException {
public:
   RpcConnectionException( string what ) : RpcException( what ) {}
   virtual Id id();
};

class EntityNotFoundException : public Exception {
public:
   EntityNotFoundException( string what ) : Exception( what ) {}
   virtual Id id();
};

class EntityNotDirException : public Exception {
public:
   EntityNotDirException( string what ) : Exception( what ) {}
   virtual Id id();
};

class EntityLogRecordException : public Exception {
public:
   EntityLogRecordException( string what ) : Exception( what ) {}
   // Throw if ptr to eid resolution during entitylog marshaling
};

class EntityLogEntityException : public Exception {
public:
   EntityLogEntityException( string what ) : Exception( what ) {}
};

class MountException : public Exception {
public:
   MountException( string what ) : Exception( what ) {}
};

class AuditException : public InternalException {
public:
   AuditException( string what ) : InternalException(what) {}
   virtual Id id();
};

class UnknownEntityIdException : public InternalException {
public:
   UnknownEntityIdException( string what ) : InternalException(what) {}
   virtual Id id();
};

class EntityIdInUseException : public InternalException {
public:
   EntityIdInUseException( string what ) : InternalException(what) {}
   virtual Id id();
};

class EntityLogMsgLenException : public InternalException {
public:
   EntityLogMsgLenException( string what ) : InternalException(what) {}
   virtual Id id();
};

class EntityLogWriteToConstException : public InternalException {
public:
   EntityLogWriteToConstException( string what ) : InternalException(what) {}
   virtual Id id();
};

class ErrnoException : public Exception {
 public:
   ErrnoException( int error, string filename = "" )
         : Exception( strerror( error ) ), _errno( error ), _filename( filename ) {}
   int error() const { return _errno; }
   // Can't use errno() because it is a #defined macro in bits/errno.h
   string filename() const { return _filename; }
   virtual Id id();
 private:
   int _errno;
   string _filename;
};

class ListException : public RangeException {
 public:
   ListException( string what ) : RangeException(what) {}
   virtual Id id();
};

class MemoryLimitExceededException : public MemoryException {
public:
   MemoryLimitExceededException(string what) : MemoryException(what) {}
   virtual Id id();
};

class NoParentException : public Exception {
public:
   NoParentException( string what ) : Exception( what ) {}
};

} // namespace framework

#endif
