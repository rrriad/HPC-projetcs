# Gnuplot script for plotting x_i against u[i]
set terminal png size 800,600
set output "plot2.png"
set title "Plot of x_i against u[i]"
set xlabel "x_i"
set ylabel "u[i]"
set grid
set style data lines

# Plot data from the files
plot 'data_2s.txt' using 2:3 with lines title 'Upwind',\
     'data2.txt' using 2:3 with lines title 'Initial Condition', \
     'data_2s.txt' using 2:5 with lines title 'Exact solution',\
     'data_2s.txt' using 2:4 with lines title 'LaxWendroff', 





#'data2.txt' using 2:3 with lines title 'Initial Condition', \
#'data_2s.txt' using 2:5 with lines title 'Exact solution'
#'data_2s.txt' using 2:4 with lines title 'LaxWendroff', \
