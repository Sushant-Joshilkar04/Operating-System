# echo "Enter Choice"
# read a

# case $a in
# 10) echo "hello $a"
# ;;
# 20) echo "bye $a"
# ;;
# *) echo tata
# ;;
# esac



echo "Enter Choice 1.Addition 2.Subtraction 3.Multiplication 4.Division 5.Modulo"
read n

echo "Enter 2 Numbers"
read a
read b

case $n in
1) echo "Addition is $(($a+$b))"
;;
2) echo "Subtraction is $(($a-$b))"
;;
3) echo "Multiplication is $(($a*$b))"
;;
4) echo "Division is $(($a/$b))"
;;
5) echo "Modulo is $(($a%$b))"
;;
*) echo "Invalid Choice"
;;
esac







