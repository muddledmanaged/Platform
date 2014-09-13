//
//  ObservableScenarios.h
//  PlatformDesign
//
//  Created by Wahid Tanner on 6/26/13.
//

#ifndef Platform_SimpleObservable_h
#define Platform_SimpleObservable_h

#include "../Platform/Observable.h"

using namespace MuddledManaged;

class SimpleObservable
{
public:
    typedef Platform::Observable<SimpleObservable, const std::string &, const std::string &> PropertyChangedEvent;

    SimpleObservable ()
    : mPropertyChanged(new PropertyChangedEvent("PropertyChanged"))
    { }
    
    virtual ~SimpleObservable ()
    { }

    PropertyChangedEvent * propertyChanged ()
    {
        return mPropertyChanged.get();
    }

private:
    std::unique_ptr<PropertyChangedEvent> mPropertyChanged;
};

#endif // Platform_SimpleObservable_h
