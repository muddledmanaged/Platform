//
//  ObserverScenarios.h
//  PlatformDesign
//
//  Created by Wahid Tanner on 6/25/13.
//

#ifndef Platform_SimpleObserver_h
#define Platform_SimpleObserver_h

#include "../Include/Identifiable.h"
#include "../Include/Observer.h"
#include "SimpleObservable.h"

using namespace MuddledManaged;

class SimpleObserver : public Platform::Identifiable, public Platform::Observer<SimpleObservable, const std::string &, const std::string &>
{
public:
    explicit SimpleObserver (const std::string & token)
    : Platform::Identifiable(token)
    { }
    
    virtual ~SimpleObserver ()
    { }
    
    virtual void notify (const std::string & event, SimpleObservable * pSender, const std::string & stringArg)
    {
        mNotified = true;
        mEvent = event;
        mpSender = pSender;
        mProperty = stringArg;
    }
    
    bool notified ()
    {
        return mNotified;
    }
    
    std::string event ()
    {
        return mEvent;
    }
    
    std::string property ()
    {
        return mProperty;
    }
    
    SimpleObservable * sender ()
    {
        return mpSender;
    }
    
private:
    bool mNotified;
    std::string mEvent;
    std::string mProperty;
    SimpleObservable * mpSender;
};

#endif // Platform_SimpleObserver_h
