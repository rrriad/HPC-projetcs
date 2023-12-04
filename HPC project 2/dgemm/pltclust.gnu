set style data histograms
set style histogram clustered
set datafile separator ';'
set style fill solid border -1
set boxwidth 0.8 relative
set xtics rotate by -45
set ytics nomirror
set ylabel "MiB/s"

set ytics 
set yrange [0:*]



do for [t in "0 1 2 3"] {
  outfile = sprintf('CLANG vs GCC%s.png',t)
  set output outfile
  set terminal png size 800,600
  set title 'GCC vs CLANG using flag '.t
  plot 'clang'.t.'.txt' using 11:xtic(1) title 'clang', 'gcc'.t.'.txt' using 11:xtic(1) title 'gcc'
  
}

exit
 

