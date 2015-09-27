//
//  Scribe.h
//  Platform
//
//  Created by Wahid Tanner on 1/19/15.
//

#ifndef Platform_Scribe_h
#define Platform_Scribe_h


namespace MuddledManaged
{
    namespace Platform
    {
        class Scribe
        {
        public:
            explicit Scribe ()
            { }

            ~Scribe ()
            { }

            Scribe (const Scribe & src);

            Scribe & operator = (const Scribe & rhs);
        };

        const Scribe & operator << (const Scribe & output, const std::string & info)
        {
            return output;
        }

        const Scribe & operator << (const Scribe & output, const Scribe & (*func)(const Scribe &))
        {
            return func(output);
        }

        inline const Scribe&
        endl(const Scribe & output)
        {
            return output;
        }

    } // namespace Platform

} // namespace MuddledManaged

#endif // Platform_Observer_h
