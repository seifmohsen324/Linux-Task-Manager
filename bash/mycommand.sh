#!/bin/bash
echo "==== Custom Commands Menu ===="
echo "1) myps (ps + grep)"
echo "2) mywc (wc + sort)"
echo
read -p "Choose command: " cmd

case $cmd in
    1)
	read -p "Enter keyword or username to filter process: " key
	echo
	echo "Running: ps aux | grep $key"
	ps aux | grep "$key"
	;;
    2)
	read -p "Enter file name: " file
	if [ -f "$file" ]; then
	   echo
	   echo "Running: wc $file | sort -n"
	   wc "$file" | sort -n
	else
	   echo "File not found!"
	fi
	;;
    *)
	echo "Invalid choice"
	;;
esac
