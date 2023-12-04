set terminal png
set output "temperature_plot.png"
set title "Évolution de la température (2007-2107)"
set xlabel "Année"
set ylabel "Température (K)"
set grid

plot "temperature_data.txt" using 1:2 with lines title "Température"
