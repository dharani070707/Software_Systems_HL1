cc 2.c
./a.out &
ps
pid=$!
echo "The program is executing in $pid"
ls /proc/$pid/
echo "Killing the program with kill command"
kill -9 $pid
ps
