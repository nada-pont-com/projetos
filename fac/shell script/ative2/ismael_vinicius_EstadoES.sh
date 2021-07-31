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

# - Qtde. total RAM
totalRam=$(cat /proc/meminfo | grep MemTotal | awk '{print $2}')

# - Qtde de Hubs USB
qtdUSB=$(lsusb | wc -l)

# - Qtde. USB Ativa


# - Modelo Placa de rede Ethernet/WiFi (a que estiver em uso)
placaNet=$(lspci | grep Ethernet | cut -f3 -d":")

# - Velocidade Ethernet/WiFi (a que estiver em uso)

# - Quantidade de discos (HD/SSD)
qtdDisco=$(lsblk -o SIZE,TYPE | grep disk | wc -l)

# - Capacidade HD/SSD (Gb)
capacidade=$(lsblk -o SIZE,TYPE | grep disk | cut -f3 -d" ")

# - Modelo Placa Vídeo
placaVideo=$(lspci | grep VGA |cut -f3 -d":")

# ismael_vinicius__${data}EstadoES${user}.csv

FILE=ismael_vinicius__${data}EstadoES${user}.csv

if [[ ! -e "$FILE" ]]; then 
    echo "$FILE not exist" 
    echo "Data (AAAAMMDD-HH:MM:SS), Usuário corrente, Nome do host, Qtde. de Processadores, Qtde de núcleos, Qtde. total RAM, Qtde de Hubs USB,  Qtde. USB Ativa, Modelo Placa de rede Ethernet/WiFi, Velocidade Ethernet/WiFi, Quantidade de discos, Capacidade HD/SSD, Modelo Placa Vídeo" >> $FILE
fi

echo "${data}, ${user}, ${userHost}, ${qtdProcessador}, ${qtdNucleos}, ${totalRam}, ${qtdUSB},, ${placaNet},, ${qtdDisco}, ${capacidade}, ${placaVideo}" >> $FILE