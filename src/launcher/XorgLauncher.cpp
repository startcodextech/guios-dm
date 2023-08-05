//
// Created by julio on 3/08/23.
//
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "XorgLauncher.h"
#include <syslog.h>
#include <sstream>
#include <cstring>
#include <chrono>
#include <thread>

namespace guios {
    namespace dm {
        namespace launcher {

            void XorgLauncher::launchXorg() {
                if (!isXorgRunning()){
                    syslog(LOG_INFO, "Iniciando Xorg...");

                    // Lanzar Xorg en segundo plano
                    pid_t pid = fork();
                    if (pid == 0) {
                        // Proceso hijo (Xorg)
                        if (execlp("Xorg", "Xorg", ":0", "-nolisten", "tcp", "-logfile", "/var/log/Xorg.0.log", nullptr) == -1) {
                            syslog(LOG_ERR, "No se pudo lanzar Xorg: %s", strerror(errno));
                            std::exit(1);
                        }
                    } else if (pid < 0) {
                        // Error al crear el proceso hijo
                        syslog(LOG_ERR, "Error al crear el proceso de Xorg: %s", strerror(errno));
                        std::exit(1);
                    }

                    std::ostringstream ss;
                    ss << pid;
                    std::string pidStr = ss.str();
                    // Proceso padre
                    std::string message = "Xorg ha sido lanzado en segundo plano con PID: " + pidStr;
                    syslog(LOG_INFO, "%s", message.c_str());

                    // Esperar a que Xorg termine su inicialización
                    waitForXorg();
                } else {
                    syslog(LOG_INFO, "Xorg ya está corriendo");
                }
            }

            bool XorgLauncher::verifyXorg() {
                // Verificar si Xorg está instalado
                if (system("command -v Xorg >/dev/null 2>&1") != 0) {
                    syslog(LOG_ERR, "Xorg no está instalado en este sistema");
                    return false;
                }

                syslog(LOG_INFO, "Xorg está instalado");
                return true;
            }

            bool XorgLauncher::isXorgRunning() {
                FILE* fp = popen("ps -C Xorg", "r");
                if (!fp) {
                    syslog(LOG_ERR, "Error al ejecutar el comando ps");
                    return false;
                }

                char buffer[128];
                bool xorgRunning = false;
                while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
                    if (strstr(buffer, "ServerLayout") != nullptr) {
                        xorgRunning = true;
                        break;
                    }
                }

                pclose(fp);
                return xorgRunning;
            }

            void XorgLauncher::waitForXorg() {
                while (!isXorgRunning()) {
                    // Puedes agregar un mensaje para indicar que se está esperando
                    syslog(LOG_INFO, "Comprobando Xorg inicie...");

                    // Puedes ajustar la duración del tiempo de espera según tus necesidades
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }

                syslog(LOG_INFO, "Xorg se ha iniciado.");
            }
        } // launcher
    } // guios
} // dm