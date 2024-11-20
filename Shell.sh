echo "Enter a"
read a
echo "Enter b"
read b

echo "a: $a , b: $b"

c=$a

c=$a+$b
 
echo c : $c

c=$(($a+$b))
echo c : $c

d=$(($a-$b))
echo d : $d

e=$(($a * $b))
echo e: $e

f=$(($a/$b))
echo f: $f

