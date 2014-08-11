//
//  AdvancedObserver.h
//  PlatformDesign
//
//  Created by Wahid Tanner on 7/20/14.
//

#ifndef Platform_AdvancedObserver_h
#define Platform_AdvancedObserver_h

#include <memory>

#include "../Include/Identifiable.h"
#include "../Include/Observer.h"
#include "AdvancedObservable.h"

using namespace MuddledManaged;

class AdvancedObserver : public Platform::Identifiable, public Platform::Observer<AdvancedObservable, const std::string &, const std::string &>,
    public Platform::Observer<AdvancedObservable, int, int, bool>
{
private:
    struct AdvancedObserverData
    {
        bool mNameNotified;
        bool mAgeNotified;
        bool mAdultNotified;
        bool mCombinedAgeAndAdultNotified;
        bool mPresidentialNotified;
        std::wstring mName;
        int mAge;
        int mCombinedAge;
        bool mAdult;
        bool mCombinedAdult;
        std::string mPresidentNumber;

        void reset ()
        {
            mNameNotified = false;
            mAgeNotified = false;
            mAdultNotified = false;
            mCombinedAgeAndAdultNotified = false;
            mPresidentialNotified = false;
            mName = L"";
            mAge = 0;
            mCombinedAge = 0;
            mAdult = false;
            mCombinedAdult = false;
            mPresidentNumber = "";
        }
    };

public:
    explicit AdvancedObserver (const std::string & token)
    : Platform::Identifiable(token), mData(new AdvancedObserverData())
    {
        reset();
    }

    virtual ~AdvancedObserver ()
    { }

    void swap (AdvancedObserver & other)
    {
        Identifiable::swap(other);

        std::unique_ptr<AdvancedObserverData> thisData(mData.release());
        std::unique_ptr<AdvancedObserverData> otherData(other.mData.release());

        mData.reset(otherData.release());
        other.mData.reset(thisData.release());
    }

    virtual void notify (const std::string & event, AdvancedObservable * pSender, const std::string & property)
    {
        if (event == AdvancedObservable::propertyChangedEventId)
        {
            if (property == AdvancedObservable::nameProperty)
            {
                mData->mNameNotified = true;
                if (pSender != nullptr)
                {
                    mData->mName = pSender->name();
                }
            }
            else if (property == AdvancedObservable::ageProperty)
            {
                mData->mAgeNotified = true;
                if (pSender != nullptr)
                {
                    mData->mAge = pSender->age();
                }
            }
            else if (property == AdvancedObservable::adultProperty)
            {
                mData->mAdultNotified = true;
                if (pSender != nullptr)
                {
                    mData->mAdult = pSender->adult();
                }
            }
        }
        else if (event == AdvancedObservable::presidentialEventId)
        {
            mData->mPresidentialNotified = true;
            mData->mPresidentNumber = property;
        }
    }

    virtual void notify (int event, AdvancedObservable * pSender, int age, bool adult)
    {
        if (event == AdvancedObservable::ageAndAdultEventId)
        {
            mData->mCombinedAgeAndAdultNotified = true;
            mData->mCombinedAge = age;
            mData->mCombinedAdult = adult;
        }
    }

    void reset ()
    {
        mData->reset();
    }

    bool nameNotified ()
    {
        return mData->mNameNotified;
    }

    bool ageNotified ()
    {
        return mData->mAgeNotified;
    }

    bool adultNotified ()
    {
        return mData->mAdultNotified;
    }

    bool combinedAgeAndAdultNotified ()
    {
        return mData->mCombinedAgeAndAdultNotified;
    }

    bool presidentialNotified ()
    {
        return mData->mPresidentialNotified;
    }

    std::wstring name ()
    {
        return mData->mName;
    }

    int age ()
    {
        return mData->mAge;
    }

    int combinedAge ()
    {
        return mData->mCombinedAge;
    }

    bool adult ()
    {
        return mData->mAdult;
    }

    bool combinedAdult ()
    {
        return mData->mCombinedAdult;
    }

    std::string presidentialNumber ()
    {
        return mData->mPresidentNumber;
    }

private:
    std::unique_ptr<AdvancedObserverData> mData;
};

#endif // Platform_AdvancedObserver_h
