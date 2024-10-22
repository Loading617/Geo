#include "require bios to play a GameCube game"

#define BIOS_VERSION "1.0.0"

#define SUPPORTED_BIOS_VERSIONS "1.0.0, 1.1.0"

void requireBiosVersion(const char* requiredVersion) {
    char* biosVersion = getBiosVersion();

    if (strcmp(requiredVersion, biosVersion) > 0) {
        fprintf(stderr, "ERROR: Required BIOS version %s or higher is not installed. Installed version: %s\n", requiredVersion, biosVersion);
        exit(1);
    }

    free(biosVersion);
}

char* getBiosVersion() {
    // Implementation of getBiosVersion() depends on the specific BIOS version in use
    // This example returns a hardcoded version for simplicity
    return strdup(BIOS_VERSION);
}