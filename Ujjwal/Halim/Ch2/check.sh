for ((i = 0; ; ++i)) do
	echo $i
	./string_gen $i > in
	./brute < in > out1
	./10905 < in > out2
	diff -w out1 out2 || break

done
