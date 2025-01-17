VAR_11=$(echo "$FT_NBR1" | sed "s/'/0/g")
VAR_1=$(echo "$VAR_11" | tr '\\\"?!' '1234')
VAR_2=$(echo "$FT_NBR2" | tr 'mrdoc' '01234')
SUM10=$(echo "ibase=5; "$VAR_1" + "$VAR_2"" | bc)
SUM13=$(echo "ibase=10; obase=13; "$SUM10"" | bc)
ANS=$(echo "$SUM13" | tr '0123456789ABC' 'gtaio luSnemf')
echo -n "$ANS"
