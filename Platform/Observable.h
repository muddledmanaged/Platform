//
//  Observable.h
//  Platform
//
//  Created by Wahid Tanner on 2/28/13.
//

#ifndef Platform_Observable_h
#define Platform_Observable_h

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "IdentifiableToken.h"
#include "Observer.h"

namespace MuddledManaged
{
    namespace Platform
    {
        template <typename Sender, typename Event, typename... Args>
        class Observable
        {
        public:
            typedef Observable<Sender, Event, Args...> ObservableType;
            typedef Observer<Sender, Event, Args...> ObserverType;
            typedef std::weak_ptr<ObserverType> WeakObserverType;
            typedef std::shared_ptr<ObserverType> SharedObserverType;

        private:
            typedef std::map<IdentifiableToken, WeakObserverType> MapIdentifiableWeakObserverType;

            template <typename EventType>
            struct ObservableData
            {
                typename std::remove_const<typename std::remove_reference<EventType>::type>::type mEventId;
                std::unique_ptr<MapIdentifiableWeakObserverType> mObservers;
            };

        public:
            explicit Observable (Event eventId)
            : mData(new ObservableData<Event>())
            {
                mData->mEventId = eventId;
                mData->mObservers.reset(new MapIdentifiableWeakObserverType());
            }
            
            Observable (ObservableType && src)
            : mData(src.mData.release())
            { }
            
            virtual ~Observable ()
            { }

            void swap (ObservableType & other)
            {
                std::unique_ptr<ObservableData<Event>> thisData(mData.release());
                std::unique_ptr<ObservableData<Event>> otherData(other.mData.release());

                mData.reset(otherData.release());
                other.mData.reset(thisData.release());
            }

            ObservableType & operator = (ObservableType && rhs)
            {
                if (this == &rhs)
                {
                    return *this;
                }
                
                mData.reset(rhs.mData.release());
                
                return *this;
            }

            void signal (const std::string * pToken, Sender * pSender, Args... args) const
            {
                std::vector<IdentifiableToken> badConnections;

                for (auto & identifiableObserverPair : *mData->mObservers.get())
                {
                    if (pToken == nullptr || *pToken == identifiableObserverPair.first.token())
                    {
                        try
                        {
                            SharedObserverType sharedObserver(identifiableObserverPair.second);

                            sharedObserver->notify(mData->mEventId, pSender, args...);
                        }
                        catch (const std::bad_weak_ptr &)
                        {
                            badConnections.push_back(identifiableObserverPair.first);
                        }
                    }
                }
                for (auto & badIdToken : badConnections)
                {
                    mData->mObservers->erase(badIdToken);
                }
            }

            void connect (const IdentifiableToken & idToken, const SharedObserverType & observer)
            {
                WeakObserverType weakObserver = observer;

                auto identifiablePos = mData->mObservers->find(idToken);
                if (identifiablePos != mData->mObservers->end())
                {
                    identifiablePos->second = weakObserver;
                }
                else
                {
                    mData->mObservers->insert({idToken, weakObserver});
                }
            }

            void disconnect (const IdentifiableToken & idToken)
            {
                mData->mObservers->erase(idToken);
            }

        private:
            Observable (const ObservableType & src) = delete;
            ObservableType & operator = (const ObservableType & rhs) = delete;
            
            std::unique_ptr<ObservableData<Event>> mData;
        };
        
    } // namespace Platform
    
} // namespace MuddledManaged

#endif // Platform_Observable_h




