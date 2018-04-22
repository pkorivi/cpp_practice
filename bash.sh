#!/bin/bash
clear
echo abcd; echo "abcd"

var="abcd" # not var = "abcd" or var='abcd'
#cmd #output
echo $var #abcd
echo "$var" #abcd
echo '$var' #$var
echo var #var

#parameter expansion
echo ${var} #abcd
var="abcd efg"
#replace and print
echo ${var/efg/A} #abcd A
echo ${var:0:3} #abc

foo=23
echo ${foo:-3} #default value if foo is missing or empty

#array
array=(on to te)
echo $array #on - first element
echo ${array[0]} #on - first element
echo ${array[@]} #on to te - all elements
echo ${#array[@]} # 3 - number of elements
echo ${#array[2]} # 2 - characters in thrid object
echo ${array[@]:1:3} # to te - print 1st and 2nd elements

#for loop
for i in "${array[@]}";do
  echo "i, $i"
done
#op
i, on
i, to
i, te

#brace expansion
echo {3..8} # 3 4 5 6 7 8
echo {W..f} # W X Y Z [  ] ^ _ ` a b c d e f

#Built in variables
echo "Last program's return value: $?"
echo "Script's PID : $$"
echo "Number of arguments passed to script: $#"
echo "All arguments passed to script: $@"
echo "Scripts arguments separated into different variables: $1 $2..."

#Access current path
echo "In $(pwd)"
echo "In $PWD"

clear #clears terminal

read name
echo "Hello $name"
#echo $USER

if [ $name != $USER ] #dont forget proper spacing
then
  echo "whos this"
else
  echo "heahh its you"
fi

#in above it fails if name is empt
#safe way is if [ "$name" != $USER ]

echo "aa" || echo "bb" #aa
echo "ca" && echo "bb" ## ca bb

read name
if [ "$name" == "billa" ] || [ "$name" -lt 65 ] # -eq  -gt -lt
then
 echo "rane"
elif [ "$name" -gt 95 ]
then
  echo "ma"
else
  echo "meme"
fi


#create alias
alias ping='bing'
#to escaple alias
\ping
alias -p #print all alias

#expressions
echo $((10+5))

ls # Lists the files and subdirectories contained in the current directory
# These commands have options that control their execution:
ls -l # Lists every file and directory on a separate line
ls -t # Sorts the directory contents by last-modified date (descending)
#ls -R # Recursively `ls` this directory and all of its subdirectories


#results from previous command can be passed as input to next command.
#grep filters input with provided patterns
ls -l | grep "\.txt"

#print files to stdout
cat hdfc.txt

data=$(cat hdfc.txt)
echo "START OF FILE\n$data\nEND OF FILE"

#copy one file and files recursively
cp srcFile.txt clone.txt
cp -r srcDirectory/ dst/ # recursively copy
mv source.txt dst.txt

# Use subshells to work across directories
(echo "First, I'm here: $PWD") && (cd Bonaverde; echo "Then, I'm here: $PWD")

# Use `mkdir` to create new directories.
mkdir myNewDir
# The `-p` flag causes new intermediate directories to be created as necessary.
mkdir -p myNewDir/with/intermediate/directories

# Read from stdin until ^EOF$ and overwrite hello.py with the lines
# between "EOF":
cat > hello.py << EOF

info bash 'Basic Shell Features' 'Redirections' > output.out 2>> error.err
wc -l output.out error.err

# Commands can be substituted within other commands using $( ):
# The following command displays the number of files and directories in the
# current directory.
#wc -l number of lines
echo "There are $(ls | wc -l) items here."

#case
read var
case "$var" in
  0) echo "zero";;
  1) echo one;;
  *) echo "not null";;
esac

#loops

for var in {1..4}
do
  echo "$var"
done

for ((a=1; a <= 3; a++))
do
    echo $a
done


for Variable in 1 2 3 4
do
    echo "$Variable"
done

for Variable in file1 file2
do
    cat "$Variable"
done


#print all files in the folder
#for Output in $(ls)
#do
#    cat "$Output"
#done

#while loop

while [ true ]
do
    echo "loop body here..."
    break
done

i="0"
while [ $i -lt 4 ]
do
  echo $i
  i=$[$i+1]
done

function foo ()
{
    echo "Arguments work just like script arguments: $@"
    echo "And: $1 $2..."
    echo "This is a function"
    return 0
}

foo ag1 ag2

bar ()
{
    echo "Another way to declare functions!"
    return 0
}
# Call the function `bar` with no arguments:
bar # => Another way to declare functions!


tail -n 10 temp.txt #last 10 lines
head -n 10 temp.txt #top 10 lines



















#
