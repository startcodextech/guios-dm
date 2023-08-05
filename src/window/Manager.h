//
// Created by julio on 4/08/23.
//

#ifndef DM_MANAGER_H
#define DM_MANAGER_H

#include <X11/Xlib.h>

namespace guios {
    namespace dm {
        namespace window {

            class Manager {
            private:
                Display *display_; // Variable miembro para almacenar el puntero al Display

            public:
                Manager(Display* display) : display_(display) {} // Constructor
                void createWindow(); // Método para crear una ventana
            };
        } // guios
    } // dm
} // window

#endif //DM_MANAGER_H
