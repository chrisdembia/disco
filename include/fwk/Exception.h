// Framework Exception types
// Copyright(c) 1993-2006_2007, David R. Cheriton, all rights reserved.
// Modified by Chris Dembia.

#ifndef FWK_EXCEPTION_H
#define FWK_EXCEPTION_H

#include <cstring>
#include <string>
#include <iostream>
#include "Ptr.h"
#include "PtrInterface.h"

#ifdef _MSC_VER // Don't want to see strerror warnings, assume we won't get buffer overflowed
  #pragma warning(disable: 4996)
#endif

using std::string;
using std::ostream;

namespace fwk {

class Exception {
public:

   enum Id { // Enum for remote designation
      noException_ = 0,
      unknownException_ = 1,
      unknownTypeException_ = 2,
      unknownAttrException_ = 3,
      unknownDelimiterException_ = 4,
      unknownArgException_ = 5,
      internalException_ = 6,
      rangeException_ = 7,
      memoryException_ = 8,
      storageException_ = 9,
      timeoutException_ = 10,
      nameInUseException_ = 11,
      illegalNameException_ = 12,
      permissionException_ = 13,
      noImplementationException_ = 14,
      rpcException_ = 15,
      rpcConnectionException_ = 16,
      entityNotFoundException_ = 17,
      entityNotDirException_ = 18,
      auditException_ = 19,
      unknownEntityIdException_ = 20,
      entityIdInUseException_ = 21,
      entityLogMsgLenException_ = 22,
      entityLogWriteToConstException_ = 23,
      errnoException_ = 24,
      listException_ = 25,
      memoryLimitExceededException_ = 26,
      noParentException_ = 27,
   };

   static Id IdInstance( unsigned long v );

   string what() const { return what_; }
   virtual ~Exception();
   // Providing a virtual destructor enables us to catch an Exception, and
   // then dynamic_cast it to a derived exception type or fetch its typeid, etc.
   virtual Id id();
protected:
   Exception( char const * str ) : what_(str) {}
   Exception( string str ) : what_(str) {}
private:
   string what_;
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
         : Exception( strerror( error ) ), errno_( error ), filename_( filename ) {}
   int error() const { return errno_; }
   // Can't use errno() because it is a #defined macro in bits/errno.h
   string filename() const { return filename_; }
   virtual Id id();
 private:
   int errno_;
   string filename_;
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

}

#endif /* EXCEPTION_H */
