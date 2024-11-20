echo "Enter a"
read a
echo "Enter b"
read b
echo "Enter c"
read c

if [ $a -gt $b ] && [ $a -gt $c ]
then
echo "a is greater and a : $a"
elif [ $b -gt $a ]  && [ $b -gt $c ]  # if-elif elif-else else-if
then
echo "b is greater and b: $b"
else
  echo "c is greater and c : $c"

fi       # fi is used to stop if

echo "End"   


