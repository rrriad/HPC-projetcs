# Gnuplot script for plotting x_i against u[i]
set terminal png size 800,600
set output "plot.png"
set title "Plot of x_i against u[i]"
set xlabel "x_i"
set ylabel "u[i]"
set grid
set style data lines

plot "data.txt" using 2:3 title "u[i]"

