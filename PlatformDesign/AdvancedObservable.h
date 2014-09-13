//
//  AdvancedObservable.h
//  PlatformDesign
//
//  Created by Wahid Tanner on 7/19/14.
//

#ifndef Platform_AdvancedObservable_h
#define Platform_AdvancedObservable_h

#include "../Platform/Observable.h"

using namespace MuddledManaged;

class AdvancedObservable
{
private:
    const int minimumAdultAge = 20;

public:
    typedef Platform::Observable<AdvancedObservable, const std::string &, const std::string &> PropertyChangedEvent;
    typedef Platform::Observable<AdvancedObservable, const std::string &, const std::string &> PresidentialEvent;
    typedef Platform::Observable<AdvancedObservable, int, int, bool> AgeAndAdultEvent;

    static const std::string propertyChangedEventId;
    static const int ageAndAdultEventId = 5;
    static const std::string presidentialEventId;
    static const std::string nameProperty;
    static const std::string ageProperty;
    static const std::string adultProperty;

    AdvancedObservable (const std::wstring & name, int age)
    : mName(name), mAge(age), mPropertyChanged(new PropertyChangedEvent(propertyChangedEventId)),
    mPresidential(new PresidentialEvent(presidentialEventId)),
    mAgeAndAdult(new AgeAndAdultEvent(ageAndAdultEventId))
    {
        if (mAge < minimumAdultAge)
        {
            mAdult = false;
        }
        else
        {
            mAdult = true;
        }
    }

    virtual ~AdvancedObservable ()
    { }

    PropertyChangedEvent * propertyChanged ()
    {
        return mPropertyChanged.get();
    }

    PresidentialEvent * presidential ()
    {
        return mPresidential.get();
    }

    AgeAndAdultEvent * ageAndAdult ()
    {
        return mAgeAndAdult.get();
    }

    std::wstring name ()
    {
        return mName;
    }

    int age ()
    {
        return mAge;
    }

    bool adult ()
    {
        return mAdult;
    }

    void setName (const std::wstring & name)
    {
        if (mName != name)
        {
            mName = name;
            propertyChanged()->signal(nullptr, this, nameProperty);

            if (mName == L"Washington")
            {
                presidential()->signal(nullptr, this, "1st");
            }
        }
    }

    void setAge (int age)
    {
        if (mAge != age)
        {
            mAge = age;
            propertyChanged()->signal(nullptr, this, ageProperty);

            if (mAge < minimumAdultAge)
            {
                if (mAdult)
                {
                    mAdult = false;
                    propertyChanged()->signal(nullptr, this, adultProperty);
                }
            }
            else
            {
                if (!mAdult)
                {
                    mAdult = true;
                    propertyChanged()->signal(nullptr, this, adultProperty);
                }
            }
        }
        ageAndAdult()->signal(nullptr, this, mAge, mAdult);
    }

private:
    std::wstring mName;
    int mAge;
    bool mAdult;
    std::unique_ptr<PropertyChangedEvent> mPropertyChanged;
    std::unique_ptr<PresidentialEvent> mPresidential;
    std::unique_ptr<AgeAndAdultEvent> mAgeAndAdult;
};

#endif // Platform_AdvancedObservable_h
