// Copyright (C) 1993-2002 David R. Cheriton.  All rights reserved.
// Modified by Chris Dembia (2013).

#ifndef DISCO_FRAMEWORK_PTR_H
#define DISCO_FRAMEWORK_PTR_H

namespace framework {

template <class T>
class Ptr
{
public:
    Ptr(T* p = 0) : _ptr(p) { if (_ptr) _ptr->newRef(); }
    Ptr(const Ptr<T>& mp) : _ptr(mp._ptr) { if (_ptr) _ptr->newRef(); }
    ~Ptr() { if (_ptr) _ptr->deleteRef(); }

    Ptr<T>& operator=( const Ptr<T>& mp );
    Ptr<T>& operator=( Ptr<T>& mp );
    Ptr<T>& operator=( T* p );

    bool operator<(const Ptr<T>& mp ) const { return _ptr < mp._ptr; }

    bool operator==( const Ptr<T>& mp ) const { return _ptr == mp._ptr; }
    bool operator!=( const Ptr<T>& mp ) const { return _ptr != mp._ptr; }
    bool operator==( T* p ) const { return _ptr == p; }
    bool operator!=( T* p ) const { return _ptr != p; }

    const T * operator->() const { return _ptr; }
    T * operator->() { return _ptr; }
    T * ptr() const { return _ptr; }

    template <class OtherType>
    operator Ptr<OtherType>() const { return Ptr<OtherType>( _ptr ); }

    struct PointerConversion { int valid; };
    operator int PointerConversion::*() const {
        return _ptr ? &PointerConversion::valid : 0;
    }

protected:
    T *_ptr;
};

} // namespace framework

#endif
