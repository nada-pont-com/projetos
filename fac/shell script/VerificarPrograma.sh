#!/bin/bash

printf "Digite o processo que deseja buscar:\n";
read busca
printf "\n"
process=$(ps u -C $busca)


valida=$( wc -l <<< $process)

if [ $valida -gt 1 ]; then
    process=$( grep "$busca"  <<< $process)
    
    pid=$( tr " " "\n" <<< $process | egrep '[1-9]')
    
    status=$( tr " " "\n" <<< $process | egrep '[a-z]')

    tam=${#status}
    j=-1
    for ((i=0;i<$tam;i++)); do
		if [ $j -ne -1 ]; then
			j=$(($j+1))
		fi
		
    	if [ -z ${status:i:1} ]; then
    	    if [ $j -eq -1 ]; then 
    	    	j=0;
    	    	continue;
    	    fi
	    	
	    	status=${status:$(($i-$j+1)):$j}
		    break
    	fi
    done
    tam=${#pid}
    for ((i=0;i<$tam;i++)); do
	  	if [ -z ${pid:i:1} ]; then
		    pid=${pid:0:i}
	    break
    	fi
    done
  	printf "Processo:%s PID:%d Status:%s\n" $busca $pid $status;
  else
    printf "Processo não emcontrado"
fi
