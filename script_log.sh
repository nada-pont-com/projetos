#!/bin/bash

# - Qtde. total RAM
totalRam=$(cat /proc/meminfo | grep MemTotal | awk '{print $2/1048576" GB"}' | tr "," ".")
MemTotal=$(cat /proc/meminfo | grep MemTotal | awk '{print $2}')
while :
do
    sleep 5
    

    # - Qtde. total de RAM livre.
    ramLivre=$(cat /proc/meminfo | grep MemFree | awk '{print $2/1048576" GB"}' | tr "," "." )

    # - Qtde. total de RAM usada. -> total - free - buffers - cache
    
    MemFree=$(cat /proc/meminfo | grep MemFree | awk '{print $2}')
    Buffers=$(cat /proc/meminfo | grep Buffers | awk '{print $2}')
    Cached=$(cat /proc/meminfo | grep ^Cached | awk '{print $2}')
    ramUsada=$((MemTotal - MemFree - Buffers - Cached))
    
    ramUsada=$(awk '{print $0/1048576" GB"}' <<< $ramUsada | tr "," "."  )

    # - Qtde. total do processador em uso (%)
    cpuUso=$(ps --no-heading ax -o %cpu | { head -n -4; } | awk '{ sum += $1 } END { print sum }')

    if [[ ! -e "log_uso_cpu_mem.csv" ]]; then 
        echo "CPU%,RAM_USADA,RAM_LIVRE,RAM_TOTAL"  >> "log_uso_cpu_mem.csv"
    fi

    echo "${cpuUso}%,${ramUsada},${ramLivre},${totalRam}" >> "log_uso_cpu_mem.csv"
done