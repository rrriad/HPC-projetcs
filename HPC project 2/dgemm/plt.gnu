set style data histograms
set style histogram clustered
set datafile separator ';'
set style fill solid border -1
set boxwidth 0.8 relative
set xtics rotate by -45
set ytics nomirror
set ylabel "MiB/s"

do for [i in "0 1 2 3"] {
  outfile = sprintf('gcc%s.png',i)
  set output outfile
  set terminal png size 800,600
  set title 'performances GCC using flag '.i
  plot 'gcc'.i.'.txt' using 11:xtic(1) notitle
  
}


do for [i in "0 1 2 3"] {
  outfile = sprintf('clang%s.png',i)
  set output outfile
  set terminal png size 800,600
  set title 'performances CLANG using flag '.i
  plot 'clang'.i.'.txt' using 11:xtic(1) notitle 
  
}
exit
 

