// Copyright (c) 1993-2007 David R. Cheriton, all rights reserved.
// Modified by Chris Dembia (2013).

#include "Ptr.h"

namespace framework {

template<class T> Ptr<T>&
Ptr<T>::operator=( const Ptr<T>& mp ) {
    const T * save = _ptr;
    _ptr = mp._ptr; 
    if( _ptr ) _ptr->newRef();
    if( save ) save->deleteRef();
    return *this;
}

template<class T> Ptr<T>&
Ptr<T>::operator=( Ptr<T>& mp ) {
    T * save = _ptr;
    _ptr = mp._ptr; 
    if( _ptr ) _ptr->newRef();
    if( save ) save->deleteRef();
    return *this;
}

template<class T> Ptr<T>&
Ptr<T>::operator=( T* p ) {
    T * save = _ptr;
    _ptr = p;
    if( _ptr ) _ptr->newRef();
    if( save ) save->deleteRef();
    return *this;
}

template <class T, class U>
Ptr<T> _ptrcast(Ptr<U> mp) {
    return dynamic_cast<T*>(mp.ptr());
}

} // namespace framework
