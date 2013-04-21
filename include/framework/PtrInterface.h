// Copyright (c) 1993-2007 David R. Cheriton, all rights reserved.
// Modified by Chris Dembia.

#ifndef FRAMEWORK_PTRINTERFACE_H
#define FRAMEWORK_PTRINTERFACE_H

#include <iostream>

namespace framework {

template <class T>
class PtrInterface {
public:
    PtrInterface() : ref_(0) {}
    unsigned long references() const { return ref_; }
    // DRC - support for templates
    inline const PtrInterface * newRef() const { ++ref_; return this; }
    inline void deleteRef() const { if( --ref_ == 0 ) onZeroReferences(); }
protected:
    virtual ~PtrInterface() {}
    virtual void onZeroReferences() const
    {
        //std::cout << "Hello there" << std::endl;
        delete this;
    }
private:
    mutable long unsigned ref_;
};

}

#endif
