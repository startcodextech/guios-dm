//
// Created by julio on 4/08/23.
//

#include "Colors.h"
#include <X11/Xlib.h>
#include <sstream>

namespace guios {
    namespace dm {
        namespace window {
            XColor Colors::hexToXColor(const std::string& hexString, Display* display) {
                XColor color;
                color.flags = DoRed | DoGreen | DoBlue;

                if (hexString.length() != 6) {
                    color.red = color.green = color.blue = 0;
                    return color; // El string debe tener 6 caracteres (sin contar el signo '#')
                }

                std::stringstream ss;
                ss << std::hex << hexString;
                unsigned int value;
                ss >> value;

                color.red = (value >> 16) & 0xFF;
                color.green = (value >> 8) & 0xFF;
                color.blue = value & 0xFF;

                // Escala los valores del rango 0-255 al rango 0-65535
                color.red = color.red * 257;
                color.green = color.green * 257;
                color.blue = color.blue * 257;

                if (!XAllocColor(display, DefaultColormap(display, DefaultScreen(display)), &color)) {
                    fprintf(stderr, "Error al asignar el color.\n");
                    color.red = color.green = color.blue = 0;
                }

                return color;
            }
        } // guios
    } // dm
} // window