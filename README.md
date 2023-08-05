# GUIOS-DM

## Introduction

es un gestor de pantanllas para el sistema operativo linux, que permite gestionar sesiones de usuario, y la ejecucion de aplicaciones en modo grafico utilizando el servidor grafico X11.

## Configurar X11

1. Instalar el servidor grafico X11
```bash
sudo apt install xserver-xorg-core
```
2. Copiar los archivos de la carpeta `config/etc/X11/` a la carpeta `/etc/X11/`
3. Copiar el servicio `config/guios-dm.service` a la carpeta `/etc/systemd/system/`
4. Habilitar el servicio
```bash
sudo systemctl enable guios-dm.service
```

## Configurar GUIOS-DM
1. Compilar el proyecto
```bash
make all
```
2. Copiar el archivo `guios-dm` a la carpeta `/usr/bin/`