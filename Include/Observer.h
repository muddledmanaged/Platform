//
//  Observer.h
//  Platform
//
//  Created by Wahid Tanner on 3/25/13.
//

#ifndef Platform_Observer_h
#define Platform_Observer_h

#include <string>

namespace MuddledManaged
{
    namespace Platform
    {
        template <typename Sender, typename Event, typename... Args>
        class Observer
        {
        public:
            virtual ~Observer ()
            { }
            
            virtual void notify (Event event,
                                 Sender * pSender,
                                 Args... args) = 0;
        };
        
    } // namespace Platform
    
} // namespace MuddledManaged

#endif // Platform_Observer_h




