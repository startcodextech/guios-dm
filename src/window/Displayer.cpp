//
// Created by julio on 3/08/23.
//
#include "Displayer.h"
#include <iostream>
#include <unistd.h>
#include <X11/Xlib.h>
#include <sys/syslog.h>
#include "Colors.h"
#include "Manager.h"

namespace guios {
    namespace dm {
        namespace window {
            Displayer::Displayer() {
                // Inicializar el Display
                display_ = XOpenDisplay(":0");
                if (display_ == NULL) {
                    std::string message = "No se pudo abrir la conexión con el servidor Xorg";
                    syslog(LOG_ERR, "%s", message.c_str());
                    throw message;
                    // Aquí puedes lanzar una excepción, mostrar un mensaje de error, o tomar alguna otra acción
                }
            }

            Displayer::~Displayer() {
                // Cerrar la conexión con el Display al destruir el objeto
                if (display_) {
                    XCloseDisplay(display_);
                }
            }

            void Displayer::setRootWindowBackground() {
                try {
                    if (!this->display_) { // Usa "this->display_" para acceder al miembro de la clase
                        std::string message = "El Display no está inicializado.";
                        syslog(LOG_ERR, "%s", message.c_str());
                        throw message;
                    }

                    Window root_window = DefaultRootWindow(this->display_);

                    XColor color = Colors::hexToXColor("87CEEB", this->display_);
                    XSetWindowAttributes attributes;
                    attributes.background_pixel = color.pixel;

                    XChangeWindowAttributes(this->display_, root_window, CWBackPixel, &attributes);
                    XClearWindow(this->display_, root_window);
                    XFlush(this->display_);

                    syslog(LOG_INFO, "El color de fondo de la ventana raíz se ha establecido correctamente.");
                } catch (const std::string& ex) {
                    // Manejo de la excepción
                    std::string message = "Excepción capturada en setRootWindowBackground: " + ex;
                    syslog(LOG_ERR, "%s", message.c_str());
                    throw message;
                }
            }

            void Displayer::run() {

                setRootWindowBackground();

                Manager manager = Manager(this->display_);
                manager.createWindow();

                while (true) {

                }
                close();
            }

            void Displayer::close() {
                if (this->display_) {
                    XCloseDisplay(this->display_);
                }
            }

        } // window
    } // guid
} // dm