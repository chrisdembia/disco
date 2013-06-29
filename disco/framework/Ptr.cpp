#include "framework/Ptr.h"

namespace framework {

template<class T> Ptr<T>&
Ptr<T>::operator=( const Ptr<T>& mp ) {
    const T * save = ptr_;
    ptr_ = mp.ptr_; 
    if( ptr_ ) ptr_->newRef();
    if( save ) save->deleteRef();
    return *this;
}

template<class T> Ptr<T>&
Ptr<T>::operator=( Ptr<T>& mp ) {
    T * save = ptr_;
    ptr_ = mp.ptr_; 
    if( ptr_ ) ptr_->newRef();
    if( save ) save->deleteRef();
    return *this;
}

template<class T> Ptr<T>&
Ptr<T>::operator=( T* p ) {
    T * save = ptr_;
    ptr_ = p;
    if( ptr_ ) ptr_->newRef();
    if( save ) save->deleteRef();
    return *this;
}

template <class T, class U>
Ptr<T> ptr_cast(Ptr<U> mp) {
    return dynamic_cast<T*>(mp.ptr());
}

} // namespace framework
