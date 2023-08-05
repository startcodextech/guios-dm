//
// Created by julio on 3/08/23.
//

#ifndef DM_XORGLAUNCHER_H
#define DM_XORGLAUNCHER_H
#pragma once

namespace guios {
    namespace dm {
        namespace launcher {
            class XorgLauncher {
            public:
                static bool verifyXorg(); // Método para verificar si Xorg está instalado
                static void launchXorg(); // Método para lanzar Xorg
                static bool isXorgRunning(); // Método para verificar si Xorg está corriendo
                static void waitForXorg(); // Método para esperar a que Xorg termine su inicialización
            };
        } // launcher
    } // dm
} // guios

#endif //DM_XORGLAUNCHER_H
