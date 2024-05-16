set xlabel "x"
set ylabel "y"
set grid
set terminal x11 8
set nokey
set title "Abrindo Gnuplot dentro do Fortran"
m = "./FXM"
plot m using 1:2 with linespoints
