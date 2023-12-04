# Gnuplot script for plotting x_i against u[i]
set terminal png size 800,600
set output "plot2.png"
set title "Plot of x_i against u[i]"
set xlabel "x_i"
set ylabel "u[i]"
set grid
set style data lines
# Plot data from the file
plot 'data2.txt' using 2:3 with lines title 'Initial Condition', \
     'data5.txt' using 2:3 with lines title 'Upwind', \
     'data5.txt' using 2:4 with lines title 'LaxWendroff', \
     'data5.txt' using 2:5 with lines title 'Exact solution', 
    

