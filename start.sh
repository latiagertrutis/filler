# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 23:39:39 by mrodrigu          #+#    #+#              #
#    Updated: 2018/06/06 02:49:44 by jagarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

read -e -p "Map: " map;
read -e -p "Player 1: " p1;
read -e -p "Player 2: " p2;
if ["$map" = ""] || ["$p1" = ""] || ["$p2" = ""]
then
	afplay Mortal_Kombat.mp3 & resources/filler_vm -f resources/maps/map01 -p1 ./jagarcia.filler -p2 ./resources/players/lcharvol.filler | ./interface;
else
	while true
	do
		read -e -p "Do you want interface?[y/n]: " inter;
		case $inter in
			[Yy]* ) afplay Mortal_Kombat.mp3 & resources/filler_vm -f $map -p1 ./$p1 -p2 ./$p2 | ./interface; break;;
			[Nn]* ) afplay Mortal_Kombat.mp3 & resources/filler_vm -f $map -p1 ./$p1 -p2 ./$p2; break;;
			* ) echo Answer y or n;;
		esac
	done
fi
killall afplay
