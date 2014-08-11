//
//  ObservableScenarios.cpp
//  PlatformDesign
//
//  Created by Wahid Tanner on 6/26/13.
//

#include <string>

#include "../Submodules/Designer/Include/Designer.h"

#include "SimpleObservable.h"
#include "SimpleObserver.h"
#include "AdvancedObservable.h"
#include "AdvancedObserver.h"

using namespace MuddledManaged;

DESIGNER_SCENARIO( Observable, "Construction/Normal", "Observable derived classes can be constructed." )
{
    SimpleObservable simple;
    AdvancedObservable advanced(L"testName", 10);
}

DESIGNER_SCENARIO( Observable, "Operation/Normal", "SimpleObservable can notify observer." )
{
    SimpleObservable observable;
    
    std::string token = "test";
    std::shared_ptr<SimpleObserver> observer(new SimpleObserver(token));
    
    observable.propertyChanged()->connect(observer->idToken(), observer);
    
    std::string parameter = "Name";
    observable.propertyChanged()->signal(nullptr, &observable, parameter);
    
    verifyTrue(observer->notified());
    verifyEqual("PropertyChanged", observer->event());
    verifyEqual(parameter, observer->property());
    verifySame(&observable, observer->sender());
}

DESIGNER_SCENARIO( Observable, "Operation/Normal", "AdvancedObservable can notify observer." )
{
    AdvancedObservable observable(L"testName", 10);

    std::string token = "test";
    std::shared_ptr<AdvancedObserver> observer(new AdvancedObserver(token));

    observable.propertyChanged()->connect(observer->idToken(), observer);

    observable.setName(L"NewName");
    verifyTrue(observer->nameNotified());
    verifyFalse(observer->ageNotified());
    verifyFalse(observer->adultNotified());
    verifyFalse(observer->combinedAgeAndAdultNotified());
    verifyFalse(observer->presidentialNotified());
    verifyEqual(observable.name(), observer->name());
    observer.reset();
}
