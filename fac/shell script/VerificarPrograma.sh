#!/bin/bash
busca=$1

process=$(ps u -C $busca)

valida=$( wc -l <<< $process)

if [ $valida -gt 1 ]; then
    process=$( grep "$busca"  <<< $process)
    
    pid=$( tr " " "\n" <<< $process | egrep '[1-9]')
    
    status=$( tr " " "\n" <<< $process | egrep '[R D S T Z]')
	
    case $status in
	R) status="Execurando";;
	D) status="Em espera";;
	S) status="Suspenso";;
	T) status="interrompido";;
	Z) status="Zumbi";;
	esac

    tam=${#pid}
    for ((i=0;i<$tam;i++)); do
	  	if [ -z ${pid:i:1} ]; then
		    pid=${pid:0:i}
	    break
    	fi
    done
  	printf "Processo:%s PID:%d Status:%s\n" $busca $pid $status;
  else
    printf "Processo não emcontrado\n"
fi