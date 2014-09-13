//
//  SimpleTestEntry.h
//  SimpleTestExtension
//
//  Created by Wahid Tanner on 6/12/14.
//

#ifndef SimpleTestExtension_SimpleTestEntry_h
#define SimpleTestExtension_SimpleTestEntry_h

#include "../../../../Platform/ExtensionManager.h"

extern MuddledManaged::Platform::ExtensionManager * gpExtensionManager;

extern "C"
{
    int mmGetExtensionProtocolVersion ();
    char * mmGetExtensionAddress ();
    char * mmSendMessage (const char * message);
    void mmSetExtensionManager (MuddledManaged::Platform::ExtensionManager * pExtensionManager);
}

#endif // SimpleTestExtension_SimpleTestEntry_h
