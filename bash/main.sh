#!/bin/bash
Bin_Dir="../bin"
clear
echo "==================================="
echo "         Mini Task Manager         "
echo "==================================="
while true
do
  echo
  echo "===== Main Menu ====="
  echo "1) Process management"
  echo "2) Memory management"
  echo "3) Thread & scheduling"
  echo "4) Custom commands"
  echo "0) Shutdown OS"
  echo
read -p "Enter your choice: " choice

case $choice in
    1)
        echo "Select process:"
        echo "1) Zombie process"
        echo "2) Orphan process"
        echo "3) Signal handling"
        echo "4)signal kill"
	read -p "Enter choice: " pchoice
	case $pchoice in
		1) $Bin_Dir/process ;;
		2) $Bin_Dir/process_orphan ;;
		3) $Bin_Dir/signal ;;
		4) $Bin_Dir/signal_kill ;;
		*) echo "Invalid choice" ;;
	esac
	;;
     2)
	echo "--- Memory Management ---"
        echo "1) Dynamic memory"
	echo "2) shared memory"
	echo "3) Disk free space"
	read -p "choose: " mchoice
	case $mchoice in
	    1) $Bin_Dir/memory ;;
            2) $Bin_Dir/shared_mem ;;
            3) df -h ;;
	    *) echo "Invalid choice" ;;
	esac
	;;
     3)
	echo "--- Threads & scheduling ---"
	$Bin_Dir/thread_sync
        $Bin_Dir/scheduler ;;
     4)
	echo "--- Custom Commands ---"
	./mycommand.sh ;;
     0)
	echo "Shutting Down Mini Task Manager os"
	exit 0
	;;
     *)
	echo "Invalid input. Please enter a number from 0-4 :)"
	;;
     esac
     echo
     read -p "Press Enter to return to main menu..." dummy
     clear
done
