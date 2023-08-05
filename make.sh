#!/bin/bash

bin_name="guios-dm"

# Directorio raíz
root_dir="src"

destination_dir="obj"

# Buscar todos los directorios y subdirectorios dentro de $root_dir
# y almacenarlos en la variable dirs
dirs=$(find "$root_dir" -type d)

# Crear los mismos directorios fuera de src usando mkdir -p
for dir in $dirs; do
    if [[ "$dir" == "$root_dir" ]]; then
        continue
    fi
    # Remover la parte inicial de la ruta (el directorio root_dir)
    target_dir="${destination_dir}/${dir#$root_dir/}"

    # Crear el directorio si no existe
    echo "create folder: $target_dir"
    mkdir -p "$target_dir"
done

echo "Directorios creados fuera de src con estructura."

cpps=$(find "$root_dir" -name "*.cpp" -print)

for cpp in $cpps; do
    # Remover la parte inicial de la ruta (el directorio root_dir)
    target_dir="${destination_dir}/${cpp#$root_dir/}"
    target_dir="${target_dir%.cpp}.o"

    # Crear el directorio si no existe
    echo "create file: $target_dir"
    g++ -c "$cpp" -o "$target_dir"

done

os=$(find "$destination_dir" -name "*.o" -print)

echo "Compilando..."

g++ -o "$bin_name" $os -L/usr/lib/x86_64-linux-gnu -lX11

chmod +x "$bin_name"
