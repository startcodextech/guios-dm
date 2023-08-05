//
// Created by julio on 4/08/23.
//

#ifndef DM_COLOR_H
#define DM_COLOR_H

#include <string>
#include <X11/Xlib.h>

namespace guios {
    namespace dm {
        namespace window {

            class Colors {
            public:
                static XColor hexToXColor(const std::string &hexColor, Display *display);
            };

        } // guios
    } // dm
} // window

#endif //DM_COLOR_H
