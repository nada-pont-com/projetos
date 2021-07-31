#!/bin/bash
# Integrantes:
# Vinicius Dall Olivo Gonçalves
# Ismael de Toledo Medeiros


# user
echo user=$USER

# - Nome do host
echo hostname

# - Qtde. de Processadores
# http://www.bosontreinamentos.com.br/linux/certificacao-lpic-1/descobrindo-informacoes-sobre-o-processador-de-seu-computador-com-lscpu/

# - Qtde de núcleos
echo cat /proc/cpuinfo | grep processor | wc -l
echo grep "model name" /proc/cpuinfo | wc -l

# - Qtde. total RAM
echo free -g

# - Qtde de Hubs USB
echo lsusb

# - Qtde. USB Ativa
echo dmesg | grep usb -i

# - Modelo Placa de rede Ethernet/WiFi (a que estiver em uso)
echo lspci | grep Ethernet

# - Velocidade Ethernet/WiFi (a que estiver em uso)

# - Quantidade de discos (HD/SSD)
echo lsblk | grep disk

# - Capacidade HD/SSD (Gb)
echo cat /proc/meminfo | grep MemTotal | awk '{print $2}'
echo free -g

# - Modelo Placa Vídeo
echo lspci | grep VGA

