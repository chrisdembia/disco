// Copyright 2013 Christopher Dembia

#include "Seconds.h"
#include "Minutes.h"

namespace framework
{

Seconds::operator Minutes() { return Minutes(this->value() / 60.0); }

} // namespace framework
