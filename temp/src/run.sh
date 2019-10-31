make clean
make
bunzip2 -kc ../traces/int_1.bz2 | ./predictor --gshare:10
