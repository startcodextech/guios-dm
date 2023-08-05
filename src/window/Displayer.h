//
// Created by julio on 3/08/23.
//

#ifndef DM_DISPLAYER_H
#define DM_DISPLAYER_H
#include <X11/Xlib.h>

namespace guios {
    namespace dm {
        namespace window{
            class Displayer {
            private:
                Display* display_; // Variable miembro para almacenar el puntero al Display

                public:
                    Displayer(); // Constructor
                    ~Displayer(); // Destructor
                    void run(); // Método para ejecutar el administrador de ventanas
                    void setRootWindowBackground(); // Método para establecer el fondo de la ventana raíz
                    void close(); // Método para cerrar la conexión con el servidor Xorg
                    Display* getDisplay() const { return display_; } // Método para obtener el puntero al Display
            };
        } // window
    } // guid
} // dm

#endif //DM_DISPLAYER_H
