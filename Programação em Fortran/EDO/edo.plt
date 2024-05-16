set xlabel "x"
set ylabel "y"
set grid
set terminal x11 8
set nokey
set title "{/:Bold Lei de Hooke - Deformacao Massa-Mola - mg contra x_0}" 
set key right bottom
m = "./edo2_EULER"
plot m using 1:2 with linespoints lc 6
m2 = "./edo2_analytic"
rep m2 using 1:2 with linespoints lc 7
