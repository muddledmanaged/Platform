//
//  ObserverScenarios.cpp
//  PlatformDesign
//
//  Created by Wahid Tanner on 6/25/13.
//

#include <string>

#include "../Submodules/Designer/Include/Designer.h"

#include "SimpleObserver.h"
#include "AdvancedObserver.h"

using namespace MuddledManaged;

DESIGNER_SCENARIO( Observer, "Construction/Normal", "Observer derived classes can be constructed." )
{
    std::string token = "test";
    SimpleObserver observer1(token);
    AdvancedObserver observer2(token);

    verifyEqual(token, observer1.idToken().token());
    verifyEqual(token, observer2.idToken().token());
}

DESIGNER_SCENARIO( Observer, "Operation/Direct", "SimpleObserver can be notified directly." )
{
    std::string token = "test";
    SimpleObserver observer(token);
    
    // This is not the normal usage. This class is designed to be notified through an
    // Observable signal.
    std::string event = "PropertyChanged";
    SimpleObservable * pSender = nullptr;
    std::string parameter = "Name";
    observer.notify(event, pSender, parameter);
    
    verifyTrue(observer.notified());
    verifyEqual(event, observer.event());
    verifyEqual(parameter, observer.property());
    verifySame(pSender, observer.sender());
}

DESIGNER_SCENARIO( Observer, "Operation/Direct", "AdvancedObserver can be notified directly." )
{
    std::string token = "test";
    AdvancedObserver observer(token);
    AdvancedObservable observableChild(L"testName", 10);
    AdvancedObservable observableAdult(L"testName", 30);

    observer.reset();
    verifyFalse(observer.nameNotified());
    verifyFalse(observer.ageNotified());
    verifyFalse(observer.adultNotified());
    verifyFalse(observer.combinedAgeAndAdultNotified());
    verifyFalse(observer.presidentialNotified());
    verifyEqual(L"", observer.name());
    verifyEqual(0, observer.age());
    verifyEqual(0, observer.combinedAge());
    verifyEqual(false, observer.adult());
    verifyEqual(false, observer.combinedAdult());
    verifyEqual("", observer.presidentialNumber());

    // This is not the normal usage. This class is designed to be notified through an
    // Observable signal.
    observer.notify(AdvancedObservable::propertyChangedEventId, &observableChild, AdvancedObservable::nameProperty);
    verifyTrue(observer.nameNotified());
    verifyFalse(observer.ageNotified());
    verifyFalse(observer.adultNotified());
    verifyFalse(observer.combinedAgeAndAdultNotified());
    verifyFalse(observer.presidentialNotified());
    verifyEqual(observableChild.name(), observer.name());
    observer.reset();

    observer.notify(AdvancedObservable::propertyChangedEventId, &observableChild, AdvancedObservable::ageProperty);
    verifyFalse(observer.nameNotified());
    verifyTrue(observer.ageNotified());
    verifyFalse(observer.adultNotified());
    verifyFalse(observer.combinedAgeAndAdultNotified());
    verifyFalse(observer.presidentialNotified());
    verifyEqual(observableChild.age(), observer.age());
    observer.reset();

    observer.notify(AdvancedObservable::propertyChangedEventId, &observableChild, AdvancedObservable::adultProperty);
    verifyFalse(observer.nameNotified());
    verifyFalse(observer.ageNotified());
    verifyTrue(observer.adultNotified());
    verifyFalse(observer.combinedAgeAndAdultNotified());
    verifyFalse(observer.presidentialNotified());
    verifyEqual(observableChild.adult(), observer.adult());
    observer.reset();

    observer.notify(AdvancedObservable::propertyChangedEventId, &observableAdult, AdvancedObservable::adultProperty);
    verifyFalse(observer.nameNotified());
    verifyFalse(observer.ageNotified());
    verifyTrue(observer.adultNotified());
    verifyFalse(observer.combinedAgeAndAdultNotified());
    verifyFalse(observer.presidentialNotified());
    verifyEqual(observableAdult.adult(), observer.adult());
    observer.reset();

    observer.notify(AdvancedObservable::ageAndAdultEventId, &observableChild, 50, true);
    verifyFalse(observer.nameNotified());
    verifyFalse(observer.ageNotified());
    verifyFalse(observer.adultNotified());
    verifyTrue(observer.combinedAgeAndAdultNotified());
    verifyFalse(observer.presidentialNotified());
    verifyEqual(50, observer.combinedAge());
    verifyEqual(true, observer.combinedAdult());
    observer.reset();

    observer.notify(AdvancedObservable::ageAndAdultEventId, &observableChild, 60, false);
    verifyFalse(observer.nameNotified());
    verifyFalse(observer.ageNotified());
    verifyFalse(observer.adultNotified());
    verifyTrue(observer.combinedAgeAndAdultNotified());
    verifyFalse(observer.presidentialNotified());
    verifyEqual(60, observer.combinedAge());
    verifyEqual(false, observer.combinedAdult());
    observer.reset();

    observer.notify(AdvancedObservable::presidentialEventId, &observableAdult, "16th");
    verifyFalse(observer.nameNotified());
    verifyFalse(observer.ageNotified());
    verifyFalse(observer.adultNotified());
    verifyFalse(observer.combinedAgeAndAdultNotified());
    verifyTrue(observer.presidentialNotified());
    verifyEqual("16th", observer.presidentialNumber());
    observer.reset();
}
