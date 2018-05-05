#Q1. [5 marks] Write a Bash script counter.sh that does the following: It records how many times you have run this script, and based on the number of times you have run the script it does the following

#If this is the first time, it prints out "Welcome to the PRISM computer environment"
#If this is the second time, it prints out "Welcome back to the PRISM computer environment"
#If this is the third time, it prints out "Welcome back to the PRISM computer environment, again"
#If this is the fourth through ninth time, it prints "You have been on the PRISM computer environment X times"
#If this is then tenth or more times, it prints out "You have been on the PRISM computer environment X times. Don't you have anything better to do?"

file=~/count.txt
savenum () 
{
  echo $1 > file
}
readnum ()
{
  x=0
  if [ -f file ]
  then x=‘cat file‘
  fi
  return $x
}
readnum
let x=$?+1
savenum $x
if [ $x -eq 1 ]; then
  echo "Welcome to the PRISM computer environment"
elif [ $x -eq 2 ]; then
  echo "Welcome back to the PRISM computer environment"
elif [ $x -eq 3 ]; then
  echo "Welcome back to the PRISM computer environment, again"
elif [[ $x -ge 4 && $x -le 9 ]]; then
  echo "You have been on the PRISM computer environment X times"
elif [ $x -ge 10 ]; then
  echo "You have been on the PRISM computer environment X times. Don't you have anything better to do?"
else
  echo ""
fi
