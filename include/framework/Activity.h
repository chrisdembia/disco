#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

#include <string>

#include "PtrInterface.h"
#include "Nominal.h"
#include "BaseNotifiee.h"

using std::string;

class Activity : public Fwk::PtrInterface<Activity> {
public:

    typedef Fwk::Ptr<Activity> Ptr;

    /* Notifiee class for Activities */
    class Notifiee : public Fwk::BaseNotifiee<Activity> {
    public:
        typedef Fwk::Ptr<Notifiee> Ptr;
        Notifiee(Activity * act) : Fwk::BaseNotifiee<Activity>(act) { }
        virtual void onNextExecutionTimeIs() { }
        virtual void onStatusIs() { } 
    };

    class Manager;

    enum Status {
        free__,
        waiting__,
        ready__,
        executing__,
        scheduled__,
        deleted__
    };
    static inline Status free() { return free__; }
    static inline Status waiting() { return waiting__; }
    static inline Status ready() { return ready__; }
    static inline Status executing() { return executing__; }
    static inline Status scheduled() { return scheduled__; }
    static inline Status deleted() { return deleted__; }

    virtual Status status() const = 0;
    virtual void statusIs(Status s)  = 0;

    virtual Duration nextExecutionTime() const = 0;
    virtual void nextExecutionTimeIs(Duration time) = 0;
    virtual void nextExecutionTimeInc(Duration time) = 0;

    virtual Fwk::Ptr<Notifiee> notifiee() const = 0;

    virtual void notifieeIs(Notifiee* n) = 0;

    virtual string name() const { return name_; }

protected:

    Activity(const string& name) : name_(name) { }

private:

    string name_;

};

class Activity::Manager : public Fwk::PtrInterface<Activity::Manager> {
public:

    typedef Fwk::Ptr<Activity::Manager> Ptr;

    virtual Fwk::Ptr<Activity> activityNew(const string &name) = 0;
    virtual Fwk::Ptr<Activity> activity(const string &name) const = 0;
    virtual Activity::Ptr activityDel(const string &name) = 0;

    virtual Duration timePassed() const = 0;
    virtual void timePassedIs(Duration time) = 0;
    virtual void timePassedInc(Duration time) = 0;

    virtual void activityAtBackIs(Activity::Ptr) = 0;

    virtual void activityFlush() = 0;

private:

    /* Up to you */

};

#endif
