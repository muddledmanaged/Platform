//
//  SimpleTestEntry.h
//  SimpleTestExtension
//
//  Created by Wahid Tanner on 6/12/14.
//

#ifndef SimpleTestExtension_SimpleTestEntry_h
#define SimpleTestExtension_SimpleTestEntry_h

extern "C"
{
    const int mmGetExtensionProtocolVersion ();
    const char * mmGetExtensionAddress ();
    const char * mmSendMessage (const char * message);
}

#endif // SimpleTestExtension_SimpleTestEntry_h
