#!/bin/bash
# Aluna: Ana Luiza Croce

usuario=$1

if ["$usuario" == ""]; then
    usuario=$USER
    valida="user corrente"
fi

numeros=$(expr $(echo ${usuario//[^a-zA-Z]/} | wc -c) - 1)

if [[ $numeros == 0 ]]; then
    echo "Usuário não existe"
else
    val=$(id "$usuario" 2>/dev/null | wc -c)
    if [ $val == 0 ]; then
        echo "Usuário não existe"
    else
        valida=""
        
        ativos=$(ps aux | wc -l)
        ativos=$(($ativos - 4))
        
        pUser=$(ps aux | grep $usuario | wc -l)
        pUser=$(($pUser - 1))

        tUser=$(ps -eLf | grep $usuario | wc -l)
        tUser=$(($tUser - 1))
        
        if [ "$corrente" == "user corrente" ]; then
            pUser=$(($pUser - 3))
            tUser=$(($tUser - 3))
        fi
#       pA=$(ps aux  | grep $usuario | grep -n '.*' | grep -e "\(^1:\)\|${usuario}"| egrep "[1]:${usuario}" | cut -d ':' -f2- | tr "  " " ")

        pA=’N\A’

        proceUser=$(ps aux | grep -i -c $USER)
        processos=$(ps aux | wc -l)

        exesaoUser=$(($processos - $proceUser -1))
        if [ "$corrente" == "" ]; then
            exesaoUser=$(($processos - 1))
        fi

        procR=$(ps aux | grep -i -c root)
        procR=$(($procR - 1))

        if [ "$USER" == "root" ]; then
            procR=$(($procR - 2))
        fi

        data=$(date +%Y%m%d)
        time=$(date +%H%M%S)

        echo "Processo Ativos SO, Processo Ativos $usuario, Threads $usuario, Primeiro processo do $usuario, Usuário atual, Exceção $USER, Root." > "${data}_${time}_Processos_$usuario.csv"
        echo "$ativos,$procU,$threadsU,$pA,$USER,$extoUser,$procR" >> "${data}_${time}_Processos_$usuario.csv"
    fi
fi