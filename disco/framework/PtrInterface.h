// Copyright (c) 1993-2007 David R. Cheriton, all rights reserved.
// Modified by Chris Dembia (2013).

#ifndef FRAMEWORK_PTRINTERFACE_H
#define FRAMEWORK_PTRINTERFACE_H

namespace framework {

template <class T>
class PtrInterface {
public:
    PtrInterface() : _ref(0) {}
    unsigned long references() const { return _ref; }
    // DRC - support for templates
    inline const PtrInterface * newRef() const { ++_ref; return this; }
    inline void deleteRef() const { if( --_ref == 0 ) onZeroReferences(); }
protected:
    virtual ~PtrInterface() {}
    virtual void onZeroReferences() const { delete this; }
private:
    mutable long unsigned _ref;
};

} // namespace framework

#endif
