//
// Created by julio on 4/08/23.
//

#include "Manager.h"

namespace guios {
    namespace dm {
        namespace window {

            void Manager::createWindow() {
                Window window;
                int screen;

                screen = DefaultScreen(this->display_);

                // 2. Configurar los atributos de la ventana
                int x = 10;  // posición x
                int y = 10;  // posición y
                int width = 400;  // ancho
                int height = 300;  // alto
                int border_width = 1;  // ancho del borde

                // 3. Crear la ventana
                window = XCreateSimpleWindow(this->display_, RootWindow(this->display_, screen),
                                             x, y, width, height, border_width,
                                             BlackPixel(this->display_, screen), WhitePixel(this->display_, screen));

                XMapWindow(this->display_, window);
            }
        } // guios
    } // dm
} // window