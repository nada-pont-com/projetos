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
totalRam=$(cat /proc/meminfo | grep MemTotal | awk '{print $2/1048576" GB"}' | tr "," ".")

# - Qtde de Hubs USB
qtdUSB=$(lsusb | wc -l)

# - Qtde. USB Ativa


# - Modelo Placa de rede Ethernet/WiFi (a que estiver em uso)
placaNet=$(lspci | grep Ethernet | cut -f3 -d":" | tr "\n" " | ")

# - Velocidade Ethernet/WiFi (a que estiver em uso)

# - Quantidade de discos (HD/SSD)
qtdDisco=$(lsblk -o SIZE,TYPE | grep disk | wc -l)

sum=0

# - Capacidade HD/SSD (Gb)
capacidade=$(lsblk -b -io SIZE,TYPE | grep disk | awk 'BEGIN{OFS="\t"} {print $1/1073741824;}'| awk '{ sum += $1 } END { print sum" GB" }')

# capacidade=0
# tam=$(wc -l <<< $capacidades)

# for ((i=0;i<$tam;i++)); do

# done

# - Modelo Placa Vídeo
placaVideo=$(lspci | grep VGA |cut -f3 -d":" | tr "\n" " ")

# ismael_vinicius__${data}EstadoES${user}.csv

FILE=ismael_vinicius__${data}EstadoES${user}.csv

if [[ ! -e "$FILE" ]]; then 
    echo "Data (AAAAMMDD-HH:MM:SS), Usuário corrente, Nome do host, Qtde. de Processadores, Qtde de núcleos, Qtde. total RAM, Qtde de Hubs USB,  Qtde. USB Ativa, Modelo Placa de rede Ethernet/WiFi, Velocidade Ethernet/WiFi, Quantidade de discos, Capacidade HD/SSD, Modelo Placa Vídeo" >> $FILE
fi

echo "${data}, ${user}, ${userHost}, ${qtdProcessador}, ${qtdNucleos}, ${totalRam}, ${qtdUSB},, ${placaNet},, ${qtdDisco}, ${capacidade}, ${placaVideo}" >> $FILE