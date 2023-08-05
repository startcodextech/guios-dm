#include <iostream>
#include "launcher/XorgLauncher.h"
#include "window/Displayer.h"
#include <syslog.h>

namespace guios {
    namespace dm {
        int main_impl() {
            try {
                openlog("GUIOS-DM", LOG_PID | LOG_CONS, LOG_USER);

                syslog(LOG_INFO, "Iniciando el gestor de pantalla GUIOS-DM.");

                if (!launcher::XorgLauncher::verifyXorg()) {
                    return 1;
                }
                launcher::XorgLauncher::launchXorg();

                // Crear una instancia de la clase Displayer
                // mostrar una vista de sesion

                syslog(LOG_INFO, "Ejecutando Displayer");

                window::Displayer displayer = window::Displayer();
                displayer.run();
            } catch (const std::string &ex) {
                std::string message = "Excepción capturada en main_impl: " + ex;
                syslog(LOG_ERR, "%s", message.c_str());
                return 1;
            }

            return 0;
        }
    } // guios
} // dm

// Función main en el ámbito global, que simplemente
//
// llama a la función main_impl
int main() {
    return guios::dm::main_impl();
}
