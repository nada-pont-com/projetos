#!/bin/bash
# Integrantes:
# Vinicius Dall Olivo Gonçalves
# Ismael de Toledo Medeiros


if [[ $1 = ?(+|-)+([0-9]) ]]; then
    echo "Usuario invalido"
else
    pid=$(id -u $1 2>/dev/null)
    if [ "$pid" == "" ]; then
        echo "Usuario invalido"
    else
        corrente=0
        user=$1
        
        if [ "$user" == "" ]; then
            user=$USER
            corrente=1
        fi

        # a) SO
        so=$(ps aux --no-heading | wc -l)
        so=$(($so - 3))
        
        # b) Processos $user
        procU=$(ps aux | grep -i $user | wc -l)
        procU=$(($procU - 1))

        # c) Threads $user
        threadsU=$(ps -eLf | grep -i $user | wc -l)
        threadsU=$(($threadsU - 1))

        # d) Processo antigo user
        antigo=$(ps --no-heading -u $user -o pid,uname,time,command --sort=+pid | { head -1; })

        # e) user corrente
        userC=$USER
        
        # f) Quantidade de processos sendo executados, excluindo-se os do usuário corrente.
        
        quantP=$(ps aux | grep -i -c $userC)
        quantTotal=$(ps aux --no-heading | wc -l)

        extoUser=$(($quantTotal - $quantP))

        # g) processos root
        root=$(ps aux | grep -i -c root)
        root=$(($root - 1))

        if [ "$userC" == "root" ]; then
            root=$(($root - 2))
        fi

        if [ $corrente == 1 ]; then
            procU=$(($procU - 3))
            threadsU=$(($threadsU - 3))
        fi

        data=$(date +%Y%m%d)

        FILE=${data}_Processos_${user}.csv

        if [[ ! -e "$FILE" ]]; then 
            echo "Número total de processos ativos no sistema,Número de processos ativos do usuário,Quantidade total de threads dos processos do usuário,Processo mais antigo do usuário, Nome do usuário corrente, Quantidade de processos sendo executados, excluindo-se os do usuário corrente, Quantidade de processos sendo executados como root"  >> $FILE
        fi

        echo "${so},${procU},${threadsU},${antigo},${userC},${extoUser},${root}" >> "${data}_Processos_${user}.csv"
    fi
fi