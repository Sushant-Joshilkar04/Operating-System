Program of loops (Check Whether given number is prime or not):
read -p 'Enter number to check whether it is prime or not: ' num
i=2
flag=1
while [ $i -le $((num / 2)) ]
do
if [ $((num % i)) -eq 0 ]
then
flag=0
break
fi
i=$(($i + 1))
done
if [ $flag -eq 1 ]
then
echo "Prime"
else
echo "Not prime"
fi
