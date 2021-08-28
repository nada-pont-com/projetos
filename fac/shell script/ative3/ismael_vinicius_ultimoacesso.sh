#!/bin/bash
# Integrantes:
# Vinicius Dall Olivo Gonçalves
# Ismael de Toledo Medeiros

busca=$(find -type f -atime -2)
data=$(date +%Y%m%d)
base=$(basename "$PWD")

echo "$busca" >> "ismael_vinicius__AcessoRecente_${base}_${data}.txt"