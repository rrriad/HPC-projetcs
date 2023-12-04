set terminal png
set output 'temperature_plot.png'
set title 'Évolution de la température'
set xlabel 'Année'
set ylabel 'Température en K'
plot 'temperature_data.txt' using 1:2 with lines title 'Température'

