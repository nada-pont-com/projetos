#!/bin/bash
# Integrantes:
# Vinicius Dall Olivo Gonçalves
# Ismael de Toledo Medeiros

#data
data=$(date +%Y%m%d)

# user
 user=$USER

# - Nome do host
userHost=$(hostname)

# - Qtde. de Processadores
qtdProcessador=$(lscpu -pCPU,Core,Socket | egrep -v '^#' | sort -u -t, -k 3 | wc -l)

# - Qtde de núcleos
qtdNucleos=$(lscpu -pCPU,Core,Socket | egrep -v '^#' | sort -u -t, -k 2,3 | wc -l)

# - Qtde. total do processador em uso (%)
cpuUso=$(ps --no-heading ax -o %cpu | { head -n -4; } | awk '{ sum += $1 } END { print sum }')

# - Qtde. total RAM
totalRam=$(cat /proc/meminfo | grep MemTotal | awk '{print $2/1048576" GB"}' | tr "," ".")

# - Qtde. total de RAM livre.
ramLivre=$(cat /proc/meminfo | grep MemTotal | awk '{print $2/1048576" GB"}' | tr "," "." )

# - Qtde de Hubs USB
qtdUSB=$(lsusb | wc -l)

# - Qtde. USB Ativa
usb=$(lsusb | wc -l)

# - Modelo Placa de rede Ethernet/WiFi (a que estiver em uso)
placaNet=$(lspci | grep Ethernet | cut -f3 -d":" | tr "\n" " | ")

# - Velocidade Ethernet/WiFi (a que estiver em uso)

# - Quantidade de discos (HD/SSD)
qtdDisco=$(lsblk -o SIZE,TYPE | grep disk | wc -l)

sum=0

# - Capacidade HD/SSD (Gb) principal
capacidade=$(lsblk -b -io SIZE,TYPE | grep disk | awk 'BEGIN{OFS="\t"} {print $1/1073741824;}'| awk '{ sum += $1 } END { print sum" GB" }')

# - Modelo Placa Vídeo
placaVideo=$(lspci | grep VGA |cut -f3 -d":" | tr "\n" " ")

# ismael_vinicius__${data}EstadoES${user}.csv

FILE=ismael_vinicius__${data}EstadoES${user}.csv

if [[ ! -e "$FILE" ]]; then 
    echo "Data (AAAAMMDD-HH:MM:SS), Usuário corrente, Nome do host, Qtde. de Processadores, Qtde de núcleos, Qtde. total do processador em uso (%), Qtde. total RAM, Qtde. total de RAM livre, Qtde de Hubs USB,  Qtde. USB Ativa, Modelo Placa de rede Ethernet/WiFi, Velocidade Ethernet/WiFi, Quantidade de discos, Capacidade HD/SSD, Modelo Placa Vídeo" >> $FILE
fi

echo "${data}, ${user}, ${userHost}, ${qtdProcessador}, ${qtdNucleos}, ${cpuUso}, ${totalRam},${ramLivre}, ${qtdUSB},, ${placaNet},, ${qtdDisco}, ${capacidade}, ${placaVideo}" >> $FILE