# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    analyzer.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 18:08:32 by aroulin           #+#    #+#              #
#    Updated: 2021/08/07 19:14:37 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/zsh

##
##		Need to have ./checker and ./push_swap
##
##		first request is the range of number with the smallest and biggest
##
##		second request is total loops that the program will perfom
##
##		third request is for know how many loops are above and below


printf "\x1B[36m";
printf "\n--- [ ANALYSING PUSH_SWAP] ---";
printf "\x1B[0m\n\n";

read -p "How many range of number [from ... to] (2 number needed) : " NBRBOT NBRTOP
read -p "How many loop : " TRY
read -p "Mediane for test : " MED
NBR=$(($NBRTOP - $NBRBOT))
((NBR++))
MOY=0;
MAX=-1;
MIN=-1;
ACTMAX="";
ACTMIN="";
MORE=0;
LESS=0;
IND=$TRY;
WELL=0;
TEST="";

printf "\n[ NBR == $NBR && TRY == $TRY && MED == $MED ]\n"

printf "\nAnalyse in progress ...\n\n";
while [ $IND -gt 0 ];
do
	ARG=`ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')"`
	NBRCOUP=$(./push_swap $ARG | wc -l);
	TEST=$(./push_swap $ARG | ./checker $ARG);
	if [ $TEST = "OK" ]
	then
		printf "\033[0;32m▓\033[0;0m"
		WELL=$(( $WELL + 1 ));
	else
		printf "\033[0;31m▓\033[0;0m"
	fi;

	if [ $MAX -lt $NBRCOUP ]
	then 
		MAX=$NBRCOUP; 
		ACTMAX=$ARG; 
	fi;
	if [ $MIN -eq "-1" ];
	then 
		MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	if [ $NBRCOUP -lt $MIN ]
	then MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	MOY=$(( $MOY + $NBRCOUP ));
	IND=$(( $IND - 1 ));
	if [ $NBRCOUP -gt $MED ]
	then 
		((MORE++))
	else
		((LESS++))
	fi;
done;
MOY=$(( $MOY / $TRY ));
printf "\n\nThere is \x1b[33m$WELL/$TRY\x1b[0m correct answer\n"
printf "There is \x1B[31m$MORE\x1b[0m more than $MED\n"
printf "There is \x1B[32m$LESS\x1b[0m less than $MED\n"
printf "The biggest  is :\x1B[31m$MAX\x1b[0m\n"
printf "The average is :\t\x1b[33m$MOY\x1b[0m\n"
printf "The smallest is :\x1B[32m$MIN\x1b[0m\n"
printf "The worst list :\t$ACTMAX\n"
printf "The best list :\t\t$ACTMIN\n"