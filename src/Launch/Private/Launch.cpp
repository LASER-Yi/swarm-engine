#include "CoreMinimal.h"

#include <cstdlib>

#include "Kuma/KumaEngine.h"

static KEngine* GEngine = nullptr;

int GuardedMain(const char* CmdLine)
{
    UNUSED_VAR(CmdLine);

    GEngine = new KKumaEngine();

    // Initialize the engine
    {
        GEngine->Initialize();
    }

    while (GEngine->IsEngineExitRequired() == false)
    {
        GEngine->EngineTick(0.0f);
    }

    // Shutdown the engine
    {
        GEngine->Shutdown();
        delete GEngine;
        GEngine = nullptr;
    }

    return EXIT_SUCCESS;
}
