#Q2. [4 marks]   In this question you will write a shell program that guesses a number between 1 and 10 and asks you to guess it. If you guess it, the script will print "Congratulations", and exit. If you don't get the number right it will output "That's not it" and ask you to guess again.
#Hint #1: The shell variable $RANDOM has a new random value every time you access it. This number is in the range 0..32767. Thus the value of ($RANDOM % 10) + 1 will result in a number between 1 and 10.
#Hint #2: The shell command read, waits for input and reads one line of input. read a b c will assign to a the first part of the input, will assign to be the second part of the input, and will assign to c the third part of the input. Parts are separated by white space and double quotes can be used to join text together that contains white space.
#Use the script and enscript technique to save an interaction with your program along with a cat of your code as q2.pdf and upload this to Moodle. 
#Hint #3: Your entire code should be about 10 lines long, so if your solution is getting longer than that, think about your solution.

ans=$(( ( RANDOM % 10 ) + 1 ))

read guess

if [ $guess -eq $ans]
	then echo "Congratulations"
	exit
fi

while [ $guess -gt $ans -o $guess -lt $ans ]
	do echo "That's not it"
	read guess 
	if [ $ans -eq $guess ]
		then echo "Congratulations"
		exit
	fi
done